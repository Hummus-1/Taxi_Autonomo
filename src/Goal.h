#pragma once 

#include <iostream>
#include <utility>

#include "Object.h"

typedef std::pair<int, int> Position;

class Goal: public Object {
   public:
      Goal(Position position) {this->position_ = position; }
      ~Goal() {}
};



