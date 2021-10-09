#include "Direction.h"

Direction::Direction()
{
    this->direction_.push_back(Position(0, 1));
    this->direction_.push_back(Position(1, 0));
    this->direction_.push_back(Position(0, -1));
    this->direction_.push_back(Position(-1, 0));
}

Position Direction::GetDirectionUp()
{
    return direction_[0];
}
Position Direction::GetDirectionRight()
{
    return direction_[1];
}
Position Direction::GetDirectionDown()
{
    return direction_[2];
}
Position Direction::GetDirectionleft()
{
    return direction_[3];
}