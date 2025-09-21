#pragma once

#include "invalid_format.h"

class missing_value : public invalid_format {
 private:
    std::string missed_value_name_;
 public:
    missing_value(std::string missed_value_name) :
        invalid_format('[' + missed_value_name + "] not specified"),
        missed_value_name_(std::move(missed_value_name)) {}

    const std::string& GetMissedValueName() {
        return missed_value_name_;
    }
};
