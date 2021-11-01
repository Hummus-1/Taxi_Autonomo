#include "Direction.h"

Direction::Direction() {
    this->direction_.push_back(Position(0, 1));
    this->direction_.push_back(Position(1, 1));
    this->direction_.push_back(Position(1, 0));
    this->direction_.push_back(Position(1, -1));
    this->direction_.push_back(Position(0, -1));
    this->direction_.push_back(Position(-1, -1));
    this->direction_.push_back(Position(-1, 0));
    this->direction_.push_back(Position(-1, 1));
    
}
Direction::Direction(Position actual_cell) {
    this->direction_.push_back(Position(0, 1));
    this->direction_.push_back(Position(1, 1));
    this->direction_.push_back(Position(1, 0));
    this->direction_.push_back(Position(1, -1));
    this->direction_.push_back(Position(0, -1));
    this->direction_.push_back(Position(-1, -1));
    this->direction_.push_back(Position(-1, 0));
    this->direction_.push_back(Position(-1, 1));
    this->actual_cell_=actual_cell;
}

Position Direction::GetDirectionUp() {
    Position calculated_pos;
    calculated_pos.first=actual_cell_.first+direction_[0].first;
    calculated_pos.second=actual_cell_.second+direction_[0].second;
    return calculated_pos;
}
Position Direction::GetDirectionUpRight() {
    Position calculated_pos;
    calculated_pos.first=actual_cell_.first+direction_[1].first;
    calculated_pos.second=actual_cell_.second+direction_[1].second;
    return calculated_pos;
}
Position Direction::GetDirectionRight() {
    Position calculated_pos;
    calculated_pos.first=actual_cell_.first+direction_[2].first;
    calculated_pos.second=actual_cell_.second+direction_[2].second;
    return calculated_pos;
}
Position Direction::GetDirectionDownRight() {
    Position calculated_pos;
    calculated_pos.first=actual_cell_.first+direction_[3].first;
    calculated_pos.second=actual_cell_.second+direction_[3].second;
    return calculated_pos;
}
Position Direction::GetDirectionDown() {
    Position calculated_pos;
    calculated_pos.first=actual_cell_.first+direction_[4].first;
    calculated_pos.second=actual_cell_.second+direction_[4].second;
    return calculated_pos;
}
Position Direction::GetDirectionDownLeft() {
    Position calculated_pos;
    calculated_pos.first=actual_cell_.first+direction_[5].first;
    calculated_pos.second=actual_cell_.second+direction_[5].second;
    return calculated_pos;
}

Position Direction::GetDirectionLeft() {
    Position calculated_pos;
    calculated_pos.first=actual_cell_.first+direction_[6].first;
    calculated_pos.second=actual_cell_.second+direction_[6].second;
    return calculated_pos;
}

Position Direction::GetDirectionUpLeft() {
    Position calculated_pos;
    calculated_pos.first=actual_cell_.first+direction_[7].first;
    calculated_pos.second=actual_cell_.second+direction_[7].second;
    return calculated_pos;
}
