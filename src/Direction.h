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

class Direction
{
private:
    std::vector<Position> direction_;
    Position actual_cell_;

public:
    Direction();
    Direction(Position actual_cell);
    Position GetDirectionUp();
    Position GetDirectionRight();
    Position GetDirectionDown();
    Position GetDirectionLeft();
};