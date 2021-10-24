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
    void Finished();
  private:
    Cell* cell_;
    Position goal_;
    std::vector<State*> states_queue_;
};