
/*
Nombre:Mundo.h y Mundo.cc

Lenguaje: C++

*/
#pragma once

#include <cstdlib>
#include <deque>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <random>
#include <typeinfo>

#include "Cell.h"
#include "Vehicle.h"
#include "Obstacle.h"
#include "Goal.h"
#include "Direction.h"

class World {
  public:
    World() {}
    World(unsigned n, unsigned m);
    ~World();

    void IsEmpty(Position position);
    Cell* GetCell(Position position);

    void AddObstacle(Position position);
    void GenerateObstacles(unsigned number);
    void AddVehicle(Position position);
    void AddGoal(Position position);
    std::vector<Cell*> GetAdjacent(Position position);
    void StartRoute(Position start, Position end);

    void Resize(unsigned n, unsigned m);
    void Reset(unsigned n, unsigned m);

    unsigned GetN();
    unsigned GetM();
    void Print();

  private:
    std::deque<std::deque<Cell> > world_;
    unsigned n_rows_;
    unsigned n_columns_;
};