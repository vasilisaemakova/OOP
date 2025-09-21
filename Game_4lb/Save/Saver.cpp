#include <fstream>

#include "Saver.h"

void Saver::Save(Mediator& mediator) {
    std::ofstream out(file_path_);
    // Write Player
    out << "Player\n";
    out << "health_level " << mediator.player_->getHealth() << '\n';
    out << "damage " << mediator.player_->getPower() << '\n';
    out << "x " << mediator.player_->getPosX() << '\n';
    out << "y " << mediator.player_->getPosY() << '\n';
    out << "name " << mediator.player_->getNick() << '\n';
    out << "key " << mediator.player_->haveKey() << '\n';
    out << "win " << mediator.player_->getWin() << '\n';
    // Write Field
    out << "Field\n";
    out << "width " << mediator.field_->getWidth() << '\n';
    out << "height " << mediator.field_->getHeight() << '\n';

    for (int i = 0; i < mediator.field_->getHeight(); i++) {
        for (int j = 0; j < mediator.field_->getWidth(); j++) {
            Cell& cell = mediator.field_->getCell(i, j);
            out << i << ' ' << j << ' ' << cell.isOnCell() << ' ' << cell.isAvailable() << ' ';
            Event* event = cell.getEvent();
            if (event != nullptr) {
                EventType type = event->GetType();
                out << type;
                if (type == EventType::kMedicalEvent || type == EventType::kTrapEvent) {
                    out << ' ' << dynamic_cast<EventPlayer*>(cell.getEvent())->GetValue();
                }
            } else {
                out << EventType::kEmptyEvent;
            }
            out << '\n';
        }
    }
}
