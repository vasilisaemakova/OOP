#pragma once

#include <string>
#include <utility>

class WrongSettingsException : public std::exception {
 private:
    std::string message_;
 public:
    explicit WrongSettingsException(std::string message) : message_(std::move(message)) {}
    const char* what() const noexcept override {
        return message_.c_str();
    }

};

