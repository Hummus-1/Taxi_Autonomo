    #include "State.h"

    int State::GetGn() const {return gn_;}

    int State::GetHn() {return hn_;}
    
    int State::GetFn() const {return fn_;}

    State* State::GetPrevState() {return previous_state_;}

    void State::RectilinearEnable(Position actual_pos, Position end, State* previous_state) {
      if (explored_ == 0 || ((previous_state->GetGn() + 1 + abs(end.first - actual_pos.first) + abs(end.second - actual_pos.second)) < fn_)) {
        explored_ = 1;
        position_ = actual_pos;
        if (previous_state != nullptr) {
          previous_state_ = previous_state;
          gn_ = previous_state_->GetGn() + 1;
        }
        hn_ = abs(end.first - actual_pos.first) + abs(end.second - actual_pos.second);
        fn_ = gn_ + hn_;
      }
    }

    void State::EuclideanEnable(Position actual_pos, Position end, State* previous_state) {
      if (explored_ == 0 || (sqrt(pow(abs(actual_pos.first - end.first), 2) + pow(abs(actual_pos.second - end.second), 2)) < fn_)) {
        explored_ = 1;
        position_ = actual_pos;
        if (previous_state != nullptr) {
          previous_state_ = previous_state;
          gn_ = previous_state_->GetGn() + 1;
        }
        hn_ = sqrt(pow(abs(actual_pos.first - end.first), 2) + pow(abs(actual_pos.second - end.second), 2));
        fn_ = gn_ + hn_;
      }
    }

    bool State::IsVisited() {return visited_;}

    bool State::IsExplored() {return explored_;}

    bool State::IsRoute() {return route_;}
    
    Position State::GetPosition() {return position_;}

    void State::MakeRoute() {this->route_ = 1;}

    void State::Reset() {
      explored_ = 0;
      visited_ = 0;
      route_ = 0;
      previous_state_ = nullptr;
      position_ = std::make_pair<int, int> (0, 0);
      gn_= 0;
      hn_ = 0;
      fn_ = 0;
    }