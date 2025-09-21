#pragma once

#include <exception>
#include <string>

class missing_section : public std::exception {
 private:
    std::string section_name_;
    std::string message_;
 public:
    missing_section(std::string section_name) :
        message_("Not find [" + section_name + "] section"),
        section_name_(std::move(section_name)) {}

    const char* what() const noexcept override {
        return message_.c_str();
    }

    const std::string& GetSectionName() {
        return section_name_;
    }
};
