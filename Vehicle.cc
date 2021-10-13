#include "Vehicle.h"

Vehicle::Vehicle(int world_limit_x,int world_limit_y)
{
   srand(time(NULL));
   this->position_.first = rand() % world_limit_x;
   this->position_.second = rand() % world_limit_y;

}

Vehicle::Vehicle(Position position)
{
   position_ = position;
}

Position Vehicle::GetPosition() {
    return this->position_;
}
void Vehicle::SetPosition(Position position){
    this->position_ = position;
}