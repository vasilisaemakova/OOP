#pragma once

#include "invalid_format.h"

class wrong_type : public invalid_format {
 private:
    std::string key_;
    std::string value_;
 public:
    wrong_type(std::string key, std::string value) :
        invalid_format("Wrong type for key [" + key + "] - [" + value + "]"),
        key_(std::move(key)),
        value_(std::move(value)) {}
};
