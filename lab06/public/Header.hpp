#ifndef HEADER_HPP
#define HEADER_HPP

#include <string>

class Header {
private:
    std::string title;

public:
    Header();
    Header(const std::string &title);

    std::string getTitle() const;
    void setTitle(const std::string &title);
};

#endif