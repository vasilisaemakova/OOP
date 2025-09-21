#pragma once

#include "../Reader/Mediator.h"
#include <string>
#include <algorithm>
#include <cctype>

class Loader : public ILoader {
 private:
    std::string file_path_;
    Mediator* mediator_;

    void ReadPlayer(std::ifstream& fin);
    void ReadField(std::ifstream& fin);
    bool CompareField(Field& other);
    bool ComparePlayer(Player& other);
    void Load();
 public:
    Loader(std::string file_path) :
        file_path_(std::move(file_path)),
        mediator_(new Mediator()) {
        try {
            Load();
        } catch (...) {}
    }

    void SetMediator(Mediator* other_mediator) override;

    ~Loader() {
        delete mediator_;
    }


};
