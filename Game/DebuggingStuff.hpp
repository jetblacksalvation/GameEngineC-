#pragma once
#include <iostream>
class NullPointer : public std::exception {
public:
    char* what() {
        return (char*)"NullPointer Exception";
    }
};
