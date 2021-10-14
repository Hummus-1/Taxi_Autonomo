
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

class World {
  public:
    World() {}
    World(unsigned n, unsigned m);
    ~World();
    void Resize(unsigned n, unsigned m);
    void AddObstacle(Position position);
    void GenerateObstacles(unsigned number);
    void AddVehicle(Position position);
    void Reset(unsigned n, unsigned m);
    void Print();
  private:
    std::deque<std::deque<Cell> > world_;
    unsigned n_rows_;
    unsigned n_columns_;
};