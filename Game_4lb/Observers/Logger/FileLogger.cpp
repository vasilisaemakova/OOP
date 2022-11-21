#include "FileLogger.h"

FileLogger::FileLogger(const std::string& file_path) {
    output_ = std::ofstream(file_path);
}

void FileLogger::log(ObserverLevel level, const std::string& update) {
    output_ << level << " " << update << std::endl;
}