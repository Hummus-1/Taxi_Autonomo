#include "Vehicle.h"

void Vehicle::SetPosition(Position position){
    this->position_ = position;
}

void Vehicle::SetGoal(Position goal) {
    this->goal_ = goal;
}

bool Vehicle::IsInGoal() {
    if(position_.first==goal_.first && position_.second==goal_.second){
        return 1;
    }
    return 0;
}

Position Vehicle::Move(std::vector<Cell*> adjacents) {
    for (unsigned i = 0; i < adjacents.size(); i++) {
        adjacents.at(i)->EnableState(goal_);
        states_queue_.push_back(adjacents.at(i)->GetState());
    }
    Mergesort(states_queue_);
    cell_->MakeEmpty();
    position_ = adjacents.at(adjacents.size() - 1)->GetPosition();
    cell_ = adjacents.at(adjacents.size() - 1);
    /*std::shared_ptr<Object> sh;
    sh.reset(*this);*/
    cell_->SetObject((std::shared_ptr<Object>)this);
    return adjacents.at(adjacents.size() - 1)->GetPosition();
}