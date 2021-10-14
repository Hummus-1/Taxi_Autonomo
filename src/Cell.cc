#include "Cell.h"

Cell::Cell(Position position) {
    this->position_ = position;
    this->empty_ = true;
    this->object_= nullptr;
}

Cell::Cell(Position position, std::shared_ptr<Object> object) {
    this->position_ = position;
    this->empty_ = false;
    this->object_ = move(object);
}

bool Cell::IsEmpty () {
    return this->empty_;
}

void Cell::Change(std::shared_ptr<Object> object) {
    this->empty_ = !empty_;
    this->object_ = move(object);
}

Position Cell::GetPosition() {
    return this->position_;
}

std::shared_ptr<Object> Cell::GetObject() {
    return this->object_;
}

void Cell::SetPosition(Position position) {
    this->position_ = position;
}