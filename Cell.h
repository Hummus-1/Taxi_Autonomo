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

class Cell{
 private:
    bool empty_;
    Position position_;
 public:
    Cell(Position position);
    Cell(Position position, bool in_use);
    bool IsEmpty();
    void Change();
    Position GetPosition();
    void SetPosition(Position position);
};