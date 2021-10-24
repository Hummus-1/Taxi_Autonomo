#pragma once 

#include <iostream>
#include <utility>
#include <memory>

#include "State.h"
#include "Object.h"

class Cell {
  public:
    Cell() {}
    Cell(Position position);
    Cell(Position position, std::shared_ptr<Object> object_);
    ~Cell() {}

    bool IsEmpty();

    Position GetPosition();
    std::shared_ptr<Object> GetObject();
    void EnableState(Position end, Cell* previous_cell = nullptr);
    State* GetState();

    void SetPosition(Position position);
    void MakeEmpty();
    void SetObject(std::shared_ptr<Object> object);
  private:
    Position position_;
    State state_;
    std::shared_ptr<Object> object_;
    bool empty_{true};

    void Change(std::shared_ptr<Object> object = nullptr);
};