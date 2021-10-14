#include "Object.h"

Object::Object(Position position) {
    this->position_ = position;
}

Position Object::GetPosition() {
    return this->position_;
}