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

class Position
{
private:
    int x_, y_;

public:
    Position();
    Position(int x,int y);
    void SetX(int x);
    void SetY(int y);
    int GetX();
    int GetY();
};
