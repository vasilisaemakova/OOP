#pragma once

#include "invalid_format.h"

#include <string>

class extra_values : public invalid_format {
 private:
    std::string values_;
 public:
    explicit extra_values(std::string values) :
        values_(std::move(values)),
        invalid_format("There are an extra values [" + values + "]") {}

    const std::string& GetExtraValues() {
        return values_;
    }
};
