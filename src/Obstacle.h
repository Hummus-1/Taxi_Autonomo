#pragma once 
#include <array>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <errno.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <vector>

typedef std::pair<int, int> Position;

class Obstacle{
 private:
    Position position_;
 public:
    Obstacle(Position position);
    Position GetPosition();
    void SetPosition(Position position);
};