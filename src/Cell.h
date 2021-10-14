#pragma once 

#include <iostream>
#include <utility>
#include <memory>

#include "Object.h"

typedef std::pair<int, int> Position;

class Cell {
  public:
    Cell() {}
    Cell(Position position);
    Cell(Position position, std::shared_ptr<Object> object_);
    ~Cell() {}

    bool IsEmpty();

    Position GetPosition();
    std::shared_ptr<Object> GetObject();

    void SetPosition(Position position);
    void MakeEmpty();
    void SetObject(std::shared_ptr<Object> object);
  private:
    Position position_;
    std::shared_ptr<Object> object_;
    bool empty_{true};

    void Change(std::shared_ptr<Object> object = nullptr);
};