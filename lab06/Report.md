# Lab 05 — Relationships Between Classes: Composition

---
**Course:** Programming, Part 2  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:** Illya Paralynov
**Date:** 04.02.2026  

---

## Task Description

The purpose of this laboratory work is to practice modeling class relationships in
which one object is built from integral parts whose lifetime is conceptually controlled
by the whole. Students are expected to distinguish composition from association and
aggregation, design a small domain model, represent it as a UML class diagram, and
implement the corresponding C++ project.


## Brief theoretical notes

```
In object-oriented design, classes are connected by different kinds of relationships,
and the correctness of the model depends on choosing the appropriate one. At this stage
of the course, students should clearly distinguish three related but different notions:
association, aggregation, and composition.
Composition is a stronger form of containment. In composition, the contained
objects are considered integral parts of the whole, and their lifetime is usually controlled
by the owner. If the whole object is destroyed, its composed parts are also destroyed as
part of the same conceptual entity. For example, a House may consist of Room objects,
or a Car may consist of an Engine and Wheel objects as parts of one assembled system.
This distinction is important both for modeling and for implementation.
```

## Variant specification

```text
Variant 15: Document Layout
Objective: Implement an object-oriented model of a document layout using composition.
Required classes:
• Document
• Paragraph
• Table
• Image
• Header
Implementation requirements:
1. Determine which class plays the role of the whole and which classes are its
integral parts.
2. Implement constructors, accessors, and behavior methods appropriate for the
domain.
3. Ensure that the main structural relationships are implemented as composition.
4. If the domain also contains association or aggregation, describe these links
explicitly and justify them.
5. Ensure that composition is reflected both in code and in the UML class diagram.
6. Implement a demonstration scenario in main.cpp.
7. Create unit tests for the key classes and their interaction logic.
8. Store declarations in public/, implementations in private/, tests in tests/.
9. Build the project using CMakeLists.txt.
Suggested composition focus: The Document structure should be primarily
composition-based, but the status of some embedded elements should be reasoned about
in the explanation.
```

## Justification of the chosen composition relationships

```
I chose this composition because it'sa the most logical and reasonable setup. Naturally, a document would be the main class, and all the others would be the composition elements.
```



### UML DIagram

![alt text](/home/ilya/programming-part-2/lab06/assets/document_layout.png)



### CMake project structure


```bash
cmake_minimum_required(VERSION 3.20)
project(document_layout LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(document_lib
    private/Document.cpp
    private/Paragraph.cpp
    private/Table.cpp
    private/Image.cpp
    private/Header.cpp
)

target_include_directories(document_lib PUBLIC public)
target_compile_features(document_lib PUBLIC cxx_std_20)

if(MSVC)
    target_compile_options(document_lib PRIVATE /W4)
else()
    target_compile_options(document_lib PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(document
    main.cpp
)

target_link_libraries(document PRIVATE document_lib)

add_executable(document_tests
    tests/test_document.cpp
)

target_link_libraries(document_tests
    PRIVATE document_lib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(document_tests)
```

## Fragments of the implementation code


```bash
#include "Document.hpp"

Document::Document() {
    paragraphCount = 0;
    tableCount = 0;
    imageCount = 0;
}

void Document::setHeader(const Header &header) {
    this->header = header;
}

void Document::addParagraph(const Paragraph &p) {
    if (paragraphCount < 10) {
        paragraphs[paragraphCount] = p;
        paragraphCount++;
    }
}

void Document::addTable(const Table &t) {
    if (tableCount < 5) {
        tables[tableCount] = t;
        tableCount++;
    }
}

void Document::addImage(const Image &i) {
    if (imageCount < 5) {
        images[imageCount] = i;
        imageCount++;
    }
}

int Document::getParagraphCount() const {
    return paragraphCount;
}

int Document::getTableCount() const {
    return tableCount;
}

int Document::getImageCount() const {
    return imageCount;
}
```

## Fragments of the unit test code
```
#include <gtest/gtest.h>

#include "Document.hpp"
#include "Paragraph.hpp"
#include "Table.hpp"
#include "Image.hpp"
#include "Header.hpp"

TEST(DocumentTest, InitialState) {
    Document doc;

    EXPECT_EQ(doc.getParagraphCount(), 0);
    EXPECT_EQ(doc.getTableCount(), 0);
    EXPECT_EQ(doc.getImageCount(), 0);
}

TEST(DocumentTest, AddParagraph) {
    Document doc;

    Paragraph p("Hello");
    doc.addParagraph(p);

    EXPECT_EQ(doc.getParagraphCount(), 1);
}

TEST(DocumentTest, AddTable) {
    Document doc;

    Table t(2, 3);
    doc.addTable(t);

    EXPECT_EQ(doc.getTableCount(), 1);
}

TEST(DocumentTest, AddImage) {
    Document doc;

    Image img("test.png");
    doc.addImage(img);

    EXPECT_EQ(doc.getImageCount(), 1);
}

TEST(DocumentTest, FullDocumentStructure) {
    Document doc;

    Header h("Test Document");
    doc.setHeader(h);

    doc.addParagraph(Paragraph("Paragraph 1"));
    doc.addParagraph(Paragraph("Paragraph 2"));

    doc.addTable(Table(3, 4));
    doc.addImage(Image("image.png"));

    EXPECT_EQ(doc.getParagraphCount(), 2);
    EXPECT_EQ(doc.getTableCount(), 1);
    EXPECT_EQ(doc.getImageCount(), 1);
}
```

## An example of running the application

![alt text](/home/ilya/programming-part-2/lab06/assets/Annotation 2026-04-01 193737.png)


---

## An example of unit tests

![alt text](/home/ilya/programming-part-2/lab06/assets/Annotation 2026-04-01 193800.png)

---

### Conclusions

```
I found this lab to be less difficult than the previous one. Not only an example variant was provided, and the topic itself was easier to understand for me, but also the directory system and the file composition was already familiar to me. overall, i found this lab enjoyable and useful.
```