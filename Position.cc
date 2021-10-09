#include "Position.h"
Position::Position()
{
    this->x_ = 0;
    this->y_ = 0;
}

Position::Position(int x,int y)
{
    this->x_ = x;
    this->y_ = y;
}

void Position::SetX(int x)
{
    this->x_ = x;
}
void Position::SetY(int y)
{
    this->y_ = y;
}
int Position::GetX()
{
    return x_;
}
int Position::GetY()
{
    return y_;
}