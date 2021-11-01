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

Position Vehicle::Move(std::vector<Cell*> adjacents, bool heuristic_mode) {
    cell_->GetState()->MakeVisited();
    for (unsigned i = 0; i < adjacents.size(); i++) {
        if (!adjacents.at(i)->GetState()->IsVisited()) {
            if (!adjacents.at(i)->GetState()->IsExplored()) {
                states_queue_.push_back(adjacents.at(i)->GetState());
                explored_cells_++;
            }
            if (heuristic_mode)
                adjacents.at(i)->EnableEuclideanState(goal_, cell_);
            else
                adjacents.at(i)->EnableRectilinearState(goal_, cell_);
        }
    }
    if (states_queue_.empty())
        throw std::out_of_range("No candidates");
    states_queue_.sort(compare);
    position_ = states_queue_.back()->GetPosition();
    if (IsInGoal()) {
        states_queue_.back()->MakeVisited();
        visited_cells_++;
        if (best_goal_ == nullptr)
            best_goal_ = states_queue_.back();
        else if (best_goal_->GetGn() > states_queue_.back()->GetGn())
            best_goal_ = states_queue_.back(); 
    }
    states_queue_.pop_back();
    visited_cells_++;
    return position_;
}

// Comprueba que la celda actual es la meta y comprueba que se ha seleccionado es el mejor estado que esta dentro de la cola.  
bool Vehicle::IsFinished() {
    if (IsInGoal() && (states_queue_.empty() || (best_goal_->GetFn() <= states_queue_.back()->GetFn()) )) 
        return 1;
    else
        return 0;
}

void Vehicle::Finished() {
    State* state = cell_->GetState();
    state->MakeRoute();
    while (state->GetPrevState() != nullptr) {
        state = state->GetPrevState();
        state->MakeRoute();
    }
}

unsigned Vehicle::GetVisitedCells() {return visited_cells_;}

unsigned Vehicle::GetExploredCells() {return explored_cells_;}


    