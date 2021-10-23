#pragma once

#include <iostream>
#include <utility>

typedef std::pair<int, int> Position;

class State{
    private:
        bool visited_ = 0;
        bool prohibited_ = 0;
        State* previous_state_ = nullptr;

        int gn_= 0;
        int hn_ = 0;
        int fn_ = 0;

    public:
        void Enable(Position actual_pos, Position end, State* previous_state = nullptr);
    int GetGn();
    int GetHn();
    int GetFn();
    bool GetVisited();
    bool GetProhibited();
    void MakeProhibited();
    

};