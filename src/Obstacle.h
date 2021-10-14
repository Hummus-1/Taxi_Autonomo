#pragma once 

#include <iostream>
#include <utility>

#include "Object.h"

typedef std::pair<int, int> Position;

class Obstacle: public Object {
   public:
      Obstacle(Position position) {this->position_ = position; }
      ~Obstacle() {}
};