#include "Paragraph.hpp"

Paragraph::Paragraph() : text_("") {}

Paragraph::Paragraph(const std::string &text) : text_(text) {}

std::string Paragraph::getText() const {
    return text_;
}

void Paragraph::setText(const std::string &text) {
    this->text_ = text;
}

int Paragraph::getLength() const {
    return text_.length();
}