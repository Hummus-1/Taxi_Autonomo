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
    if (object == nullptr)
        object_ = nullptr;
    else
        this->object_ = move(object);
}

Position Cell::GetPosition() {
    return this->position_;
}

std::shared_ptr<Object> Cell::GetObject() {
    return this->object_;
}

void Cell::EnableState(Position end, Cell* previous_cell) {
    if (previous_cell == nullptr) 
        state_.Enable(position_, end);
    else
        state_.Enable(position_, end, previous_cell->GetState());

}

State* Cell::GetState() {
    return &state_;
}

void Cell::SetPosition(Position position) {
    this->position_ = position;
}

void Cell::MakeEmpty() {
    if (!empty_) 
        Change();
}
void Cell::SetObject(std::shared_ptr<Object> object) {
    Change(object);
}