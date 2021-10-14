#pragma once 

#include <cstdlib>
#include <utility>
#include <iostream>
#include <string>
#include <memory>

typedef std::pair<int, int> Position;

class Cell{
 private:
    bool empty_;
    Position position_;
    std::unique_ptr<Object> object_;
 public:
    Cell(Position position);
    Cell(Position position, bool in_use);
    bool IsEmpty();
    void Change();
    Position GetPosition();
    void SetPosition(Position position);
};