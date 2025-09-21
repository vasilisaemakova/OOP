#pragma once

#include <exception>
#include <string>

class missing_file : public std::exception {
 private:
    std::string file_name_;
    std::string message_;
 public:
    missing_file(std::string file_name) :
        file_name_(std::move(file_name)),
        message_("There's no such file as [" + file_name_ + "]") {}

    const char* what() const noexcept override {
        return message_.c_str();
    }

    const std::string& GetFileName() {
        return file_name_;
    }
};
