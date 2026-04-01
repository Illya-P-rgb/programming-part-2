#include "Image.hpp"

Image::Image() : path("") {}

Image::Image(const std::string &path) : path(path) {}

std::string Image::getPath() const {
    return path;
}