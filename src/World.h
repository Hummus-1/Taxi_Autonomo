
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
#include <time.h>
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
    bool IsObstacle(Position position);

    void AddObstacle(Position position);
    void GenerateObstacles(unsigned number);
    void AddVehicle(Position position);
    void AddGoal(Position position);
    void StartRoute(Position start, Position end);

    void Resize(unsigned n, unsigned m);
    void Reset(unsigned n = 0, unsigned m = 0);

    unsigned GetN();
    unsigned GetM();
    unsigned GetNumberOfObstacles();
    Cell* GetCell(Position position);
    std::vector<Cell*> GetAdjacent(Position position);
    void Print();

  private:
    std::deque<std::deque<Cell> > world_;
    unsigned n_rows_;
    unsigned n_columns_;
    unsigned n_obstacles_{0};
    double t_adj_ac = 0.0;
};