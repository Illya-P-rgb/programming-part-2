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