#include "public/TouchDisplay.hpp"

int main() {
    TouchDisplay td("Smart Touch");

    td.describe(); // g++ main.cpp private/*.cpp -Ipublic -o app to compile

    return 0;
}