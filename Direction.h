#pragma once
#include "Position.h"
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

class Direction
{
private:
    std::vector<Position> direction_;

public:
    Direction();
    Position GetDirectionUp();
    Position GetDirectionRight();
    Position GetDirectionDown();
    Position GetDirectionleft();
};