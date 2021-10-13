
/*
Nombre:Mundo.h y Mundo.cc

Lenguaje: C++

*/
#pragma once
#include <cstdlib>
#include <deque>
#include <string>
#include <vector>
#include <cstdlib>

#include "Cell.h"
//#include "Obstacle.h"

class World {
    public:
        World(unsigned n, unsigned m);
        ~World();
        void AddObstacle(Position position);
        std::ostream& operator<<(std::ostream& os);
    private:
        std::vector<std::vector<Cell>> world_;
        unsigned n_rows_;
        unsigned n_columns_;
        //std::deque<Obstacles> obstacles_;
};