#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>

class Image {
private:
    std::string path;

public:
    Image();
    Image(const std::string &path);

    std::string getPath() const;
};

#endif