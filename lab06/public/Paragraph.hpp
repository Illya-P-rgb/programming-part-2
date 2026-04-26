#ifndef PARAGRAPH_HPP
#define PARAGRAPH_HPP

#include <string>

class Paragraph {
private:
    std::string text_;

public:
    Paragraph();
    Paragraph(const std::string &text);

    std::string getText() const;
    void setText(const std::string &text);
    int getLength() const;
};

#endif