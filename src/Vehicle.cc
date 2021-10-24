#include "Vehicle.h"

void Vehicle::SetCell(Cell* cell) {
    this->cell_ = cell;
}

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
        if (!adjacents.at(i)->GetState()->IsVisited()) {
            adjacents.at(i)->EnableState(goal_, cell_);
            states_queue_.push_back(adjacents.at(i)->GetState());
        }
    }
    Mergesort(states_queue_);
    //cell_->MakeEmpty();
    position_ = states_queue_.at(0)->GetPosition();
    states_queue_.erase(states_queue_.begin());
    //cell_ = states_queue_.at(states_queue_.size() - 1);
    //cell_->SetObject((Object*)this);
    return position_;
}
void Vehicle::Finished() {
    State* state = cell_->GetState();
    state->MakeRoute();
    while (state->GetPrevState() != nullptr) {
        state = state->GetPrevState();
        state->MakeRoute();
    }
}