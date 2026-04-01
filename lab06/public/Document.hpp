#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include "Header.hpp"
#include "Paragraph.hpp"
#include "Table.hpp"
#include "Image.hpp"

class Document {
private:
    Header header;

    Paragraph paragraphs[5];
    Table tables[3];
    Image images[5];

    int paragraphCount;
    int tableCount;
    int imageCount;

public:
    Document();

    void setHeader(const Header &header);

    void addParagraph(const Paragraph &p);
    void addTable(const Table &t);
    void addImage(const Image &i);

    int getParagraphCount() const;
    int getTableCount() const;
    int getImageCount() const;
};

#endif