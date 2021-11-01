#include "Cell.h"

Cell::Cell(Position position) {
    this->position_ = position;
    this->empty_ = true;
    this->object_= nullptr;
}

Cell::Cell(Position position, Object* object) {
    this->position_ = position;
    this->empty_ = false;
    this->object_ = object;
}

bool Cell::IsEmpty () {
    return this->empty_;
}

Position Cell::GetPosition() {
    return this->position_;
}

Object* Cell::GetObject() {
    return this->object_;
}

void Cell::EnableRectilinearState(Position end, Cell* previous_cell) {
    if (previous_cell == nullptr) 
        state_.RectilinearEnable(position_, end);
    else
        state_.RectilinearEnable(position_, end, previous_cell->GetState());

}

void Cell::EnableEuclideanState(Position end, Cell* previous_cell) {
    if (previous_cell == nullptr) 
        state_.EuclideanEnable(position_, end);
    else
        state_.EuclideanEnable(position_, end, previous_cell->GetState());

}

State* Cell::GetState() {
    return &state_;
}

void Cell::SetPosition(Position position) {
    this->position_ = position;
}

void Cell::MakeEmpty() {
    empty_ = true;
    this->object_ = nullptr;
}

void Cell::Reset() {
    MakeEmpty();
    state_.Reset();
    position_ = std::make_pair<int, int>(0, 0);
    empty_ = true;
}

void Cell::SetObject(Object* object) {
    empty_ = false;
    this->object_ = object;
}