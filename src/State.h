#pragma once

#include <iostream>
#include <utility>
#include <vector>

typedef std::pair<int, int> Position;

class State{
    private:
        bool visited_ = 0;
        bool route_ = 0;
        State* previous_state_ = nullptr;

        Position position_;
        int gn_= 0;
        int hn_ = 0;
        int fn_ = 0;

    public:
        void Enable(Position actual_pos, Position end, State* previous_state = nullptr);
    int GetGn();
    int GetHn();
    int GetFn();
    State* GetPrevState();
    bool IsVisited();
    bool IsRoute();
    Position GetPosition();
    void MakeRoute();
    void Reset();
};