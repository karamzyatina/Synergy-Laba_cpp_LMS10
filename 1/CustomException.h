#ifndef CUSTOMEXCEPTION_H
#define CUSTOMEXCEPTION_H

#include <stdexcept>
#include <string>

class CustomException : public std::exception {
private:
    std::string errorMessage;
public:
    CustomException(std::string message) : errorMessage(message) {}

    const char* what() const throw() {
        return errorMessage.c_str();
    }
};

#endif
