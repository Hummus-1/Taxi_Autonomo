#pragma once 

#include <array>
#include <cstdlib>
#include <ctime>
#include <errno.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <vector>

typedef std::pair<int, int> Position;

class Vehicle{
 private:
    Position position_;
 public:
    Vehicle(int world_limit_x,int world_limit_y);
    Vehicle(Position position);
    Position GetPosition();
    void SetPosition(Position position);

};