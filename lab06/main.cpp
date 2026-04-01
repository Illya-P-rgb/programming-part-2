#include <iostream>
#include "Document.hpp"

int main() {
    Document doc;

    Header h("Report");
    doc.setHeader(h);

    doc.addParagraph(Paragraph("Introduction"));
    doc.addParagraph(Paragraph("Main section"));

    doc.addTable(Table(3, 4));
    doc.addImage(Image("diagram.png"));

    std::cout << "Paragraphs: " << doc.getParagraphCount() << std::endl;
    std::cout << "Tables: " << doc.getTableCount() << std::endl;
    std::cout << "Images: " << doc.getImageCount() << std::endl;

    return 0;
}