#include "Obstacle.h"

Obstacle::Obstacle(Position position) {
    this->position_=position;
}
Position Obstacle::GetPosition() {
    return this->position_;
}
void Obstacle::SetPosition(Position position) {
    this->position_=position;
}