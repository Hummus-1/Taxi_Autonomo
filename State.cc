    #include "State.h"

    int State::GetGn() {return gn_;}

    int State::GetHn() {return hn_;}
    
    int State::GetFn() {return fn_;}

    void State::Enable(Position actual_pos, Position end, State* previous_state) {
      visited_ = 1;
      if (previous_state != nullptr) {
        previous_state_ = previous_state;
        gn_ = previous_state_->GetGn() + 1;
      }
      hn_ = abs(end.first - actual_pos.first) + abs(end.second - actual_pos.second);
      fn_ = gn_ + hn_;
    }

    bool State::GetVisited() {return visited_;}

    bool State::GetProhibited() {return prohibited_;}
    
    void State::MakeProhibited() {this->prohibited_ = 1;}