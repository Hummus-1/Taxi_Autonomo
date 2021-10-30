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
    if(goal_ == position_ || best_goal_ != nullptr)
        return 1;
    else
        return 0;
}

Position Vehicle::Move(std::vector<Cell*> adjacents) {
    // cell no tiene que tener un estado
    // Cada cell podría tener varios estados
    // a move solo hay que darle un vector de positions
    cell_->GetState()->MakeVisited();
    for (unsigned i = 0; i < adjacents.size(); i++) {
        if (!adjacents.at(i)->GetState()->IsVisited()) {
            if (!adjacents.at(i)->GetState()->IsExplored()) {
            states_queue_.push_back(adjacents.at(i)->GetState());
            explored_cells_++;
            }
            adjacents.at(i)->EnableState(goal_, cell_);
            //std::cout << explored_cells_ << " ";
        }
    }
    clock_t t_merge = clock();
    Mergesort(states_queue_);
    t_merge_ac += (double)(clock() - t_merge)/CLOCKS_PER_SEC;
    position_ = states_queue_.at(0)->GetPosition();
    if (IsInGoal()) {
        if (best_goal_ == nullptr)
            best_goal_ = states_queue_.at(0);
        else if (best_goal_->GetGn() > states_queue_.at(0)->GetGn())
            best_goal_ = states_queue_.at(0); 
    }
    states_queue_.erase(states_queue_.begin());
    visited_cells_++;
    //std::cout << "*" << visited_cells_ << "*" << std::endl;
    return position_;
}

bool Vehicle::IsFinished() {
    if (IsInGoal() && (states_queue_.empty() || (best_goal_->GetGn() <= states_queue_[0]->GetFn()) )) 
        return 1;
    else
        return 0;
}

void Vehicle::Finished() {
    std::cout << "T por merge " << t_merge_ac/visited_cells_ << "\n";
    State* state = cell_->GetState();
    state->MakeRoute();
    while (state->GetPrevState() != nullptr) {
        state = state->GetPrevState();
        state->MakeRoute();
    }
}

unsigned Vehicle::GetVisitedCells() {return visited_cells_;}

unsigned Vehicle::GetExploredCells() {return explored_cells_;}