#include "Header.hpp"

Header::Header() : title("") {}

Header::Header(const std::string &title) : title(title) {}

std::string Header::getTitle() const {
    return title;
}

void Header::setTitle(const std::string &title) {
    this->title = title;
}