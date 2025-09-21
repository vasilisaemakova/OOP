#pragma once

#include <string>

class file_changed : public std::exception {
 private:
    std::string message_;
 public:
    file_changed() : message_("File with game condition has been changed!") {}
    const char * what() const noexcept override {
        return message_.c_str();
    }
};