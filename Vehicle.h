#pragma once 
#include "Direction.h"
#include "Posicion.h"
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
class Coche{
 private:
    Position actual_position_;
 public:
    Coche(int world_limit_x,int world_limit_y);
    Coche(Position position);
    GetActualPosition();
    SetActualPosition(Position position);

};