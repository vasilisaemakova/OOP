#pragma once

#include <string>

class WrongRuleException : public std::exception {
 private:
    std::string message_;
 public:
    explicit WrongRuleException(std::string message) : message_(std::move(message)) {}
    const char* what() const noexcept override {
        return message_.c_str();
    }
};