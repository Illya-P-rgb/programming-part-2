#include "Document.hpp"
#include <iostream>

Document::Document() {
    paragraph_Count = 0;
    table_Count = 0;
    image_Count = 0;
}

void Document::setHeader(const Header &header) {
    this->header_ = header;
}

void Document::addParagraph(const Paragraph &p) {
    if (paragraph_Count < MAX_PARAGRAPHS) {
        paragraphs_[paragraph_Count] = p;
        paragraph_Count++;
    } else {
        std::cout << "Cannot add more paragraphs\n";
    }
}

void Document::addTable(const Table &t) {
    if (table_Count < 5) {
        tables_[table_Count] = t;
        table_Count++;
    }
}

void Document::addImage(const Image &i) {
    if (image_Count < 5) {
        images_[image_Count] = i;
        image_Count++;
    }
}

int Document::getParagraphCount() const {
    return paragraph_Count;
}

int Document::getTableCount() const {
    return table_Count;
}

int Document::getImageCount() const {
    return image_Count;
}

bool Document::removeLastParagraph() {
    if (paragraph_Count > 0) {
        paragraph_Count--;
        return true;
    } else {
        return false;
    }
}

bool Document::removeLastTable() {
    if (table_Count > 0) {
        table_Count--;
        return true;
    } else {
        return false;
    }
}

bool Document::removeLastImage() {
    if (image_Count > 0) {
        image_Count--;
        return true;
    } else {
        return false;
    }
}

int Document::getTotalElements() const {
    return paragraph_Count + table_Count + image_Count;
}