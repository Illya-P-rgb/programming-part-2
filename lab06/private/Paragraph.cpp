#include "Paragraph.hpp"

Paragraph::Paragraph() : text("") {}

Paragraph::Paragraph(const std::string &text) : text(text) {}

std::string Paragraph::getText() const {
    return text;
}

void Paragraph::setText(const std::string &text) {
    this->text = text;
}