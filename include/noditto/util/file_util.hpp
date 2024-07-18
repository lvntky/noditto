#ifndef FILE_UTIL_HPP_
#define FILE_UTIL_HPP_

#include <fstream>
#include <string>
#include <iostream>


std::string readFileToString(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return "";
    }

    std::string content((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));

    file.close();
    return content;
}

#endif //FILE_UTIL_HPP_
