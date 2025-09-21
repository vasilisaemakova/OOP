#pragma once

#include <exception>
#include <string>

class invalid_format : public std::exception {
 private:
    std::string message_;
 public:
    invalid_format(std::string message) : message_(std::move(message)) {}

    const char * what() const noexcept override {
        return message_.c_str();
    }
};