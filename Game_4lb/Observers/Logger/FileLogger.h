#pragma once

#include "Logger.h"

#include <fstream>

class FileLogger : public Logger {
 private:
    std::ofstream output_;

 public:
    explicit FileLogger(const std::string& file_path);

    void log(ObserverLevel level, const std::string &update) override;
};
