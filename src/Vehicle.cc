#include "Vehicle.h"

void Vehicle::SetPosition(Position position){
    this->position_ = position;
}

bool Vehicle::IsInGoal(Position end) {
    if(position_.first==end.first && position_.second==end.second){
        return 1;
    }
    return 0;
}