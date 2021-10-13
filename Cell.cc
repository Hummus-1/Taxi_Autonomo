#include "Cell.h"

Cell::Cell(Position position)
{
    this->position_=position;
    this->empty_=false;
}
Cell::Cell(Position position,bool in_use)
{
    this->position_=position;
    this->empty_=in_use;
}
bool Cell::IsEmpty () {
    return this->empty_;
}
void Cell::Change(){
    this->empty_ = !empty_;
}
Position Cell::GetPosition(){
    return this->position_;
}
void Cell::SetPosition(Position position){
    this->position_=position;
}