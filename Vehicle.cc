#include "Vehicle.h"

Vehicle::Vehicle(int world_limit_x,int world_limit_y)
{
   srand(time(NULL));
   this->actual_position_.setX(rand()%world_limit_x);
   this->actual_position_.setX(rand()%world_limit_y);
   
}

Vehicle::Vehicle(Position position)
{
   this->actual_position_.setX(position.getX());
   this->actual_position_.setY(position.getY());
}

Vehicle::GetActualPosition()
{
    return this->actual_position_;
}
Vehicle::SetActualPosition(Position position){
    actual_posicion_=position;
}