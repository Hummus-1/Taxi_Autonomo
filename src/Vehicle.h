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
#include <list>

#include "Object.h"
#include "Compare.h"
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
    Position Move(std::vector<Cell*> adjacents, bool heuristic_mode);
    bool IsFinished();
    void Finished();
    unsigned GetVisitedCells();
    unsigned GetExploredCells();
  private:
    Cell* cell_;
    Position goal_;
    State* best_goal_ = nullptr;
    std::list<State*> states_queue_;
    unsigned visited_cells_{0};
    unsigned explored_cells_{0};
};