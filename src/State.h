#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

typedef std::pair<int, int> Position;

class State {
    private:
        bool explored_ = 0;
        bool visited_ = 0;
        bool route_ = 0;
        State* previous_state_ = nullptr;

        Position position_;
        int gn_= 0;
        int hn_ = 0;
        int fn_ = 0;

    public:
        State() {}
        void RectilinearEnable(Position actual_pos, Position end, State* previous_state = nullptr);
        void EuclideanEnable(Position actual_pos, Position end, State* previous_state = nullptr);
        int GetGn() const;
        int GetHn();
        int GetFn() const;
        State* GetPrevState();
        bool IsExplored();
        bool IsVisited();
        bool IsRoute();
        bool operator()(const State& state_1, const State& state_2) {return state_1.GetFn() < state_2.GetFn();}
        Position GetPosition();
        void MakeVisited() {visited_ = true;}
        void MakeRoute();
        void Reset();
};   