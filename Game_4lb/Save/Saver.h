#pragma once

#include "string"
#include "../Reader/Mediator.h"

class Saver {
 private:
    std::string file_path_;
 public:
    Saver(std::string file_path) : file_path_(std::move(file_path)) {}

    void Save(Mediator& mediator);
};