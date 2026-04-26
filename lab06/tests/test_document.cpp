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