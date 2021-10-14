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

typedef std::pair<int, int> Position;

class Vehicle : public Object {
  public:
    Vehicle(Position position) {this->position_ = position; }
    ~Vehicle() {}
    void SetPosition(Position position);
};