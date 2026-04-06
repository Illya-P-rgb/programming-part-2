#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>

class Image {
private:
    std::string path_;
    int width_;
    int height_;

public:
    Image();
    Image(const std::string &path, int w, int h);

    std::string getPath() const;

    void scale(int factor);
};

#endif