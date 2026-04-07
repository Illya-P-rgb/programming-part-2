#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include "Header.hpp"
#include "Paragraph.hpp"
#include "Table.hpp"
#include "Image.hpp"


class Document {
private:
    Header header_;

    Paragraph paragraphs_[5];
    Table tables_[3];
    Image images_[5];

    int paragraph_Count;
    int table_Count;
    int image_Count;

    static const int MAX_PARAGRAPHS = 10;
    static const int MAX_TABLES = 3;
    static const int MAX_IMAGES = 5;

public:
    Document();

    void setHeader(const Header &header);

    void addParagraph(const Paragraph &p);
    void addTable(const Table &t);
    void addImage(const Image &i);

    int getParagraphCount() const;
    int getTableCount() const;
    int getImageCount() const;

    bool removeLastParagraph();
    bool removeLastTable();
    bool removeLastImage();

    int getTotalElements() const;
};

#endif