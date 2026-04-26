#include "Image.hpp"

Image::Image() : path_(""), width_(0), height_(0) {}

Image::Image(const std::string &path, int w, int h)
    : path_(path), width_(w), height_(h) {}

std::string Image::getPath() const {
    return path_;
}

void Image::scale(int factor) {
    width_ *= factor;
    height_ *= factor;
}