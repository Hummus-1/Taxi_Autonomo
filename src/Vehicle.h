#pragma once 

#include <array>
#include <cstdlib>
#include <errno.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <vector>
#include <time.h>
#include <queue>
#include "Object.h"
#include "Mergesort.h"
#include "Cell.h"

typedef std::pair<int, int> Position;

class Vehicle : public Object {
  public:
    Vehicle(Position position, Cell* cell) {this->position_ = position; cell_ = cell;}
    ~Vehicle() {}
    void SetCell(Cell* cell);
    void SetPosition(Position position);
    void SetGoal(Position goal);
    bool IsInGoal();
    Position Move(std::vector<Cell*> adjacents);
    bool IsFinished();
    void Finished();
    unsigned GetVisitedCells();
    unsigned GetExploredCells();
  private:
    Cell* cell_;
    Position goal_;
    State* best_goal_ = nullptr;
    std::vector<State*> states_queue_;
    unsigned visited_cells_{0};
    unsigned explored_cells_{0};
    double t_merge_ac = 0.0;
};