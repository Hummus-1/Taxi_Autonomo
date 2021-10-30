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
    Cell(Position position, Object* object_);
    ~Cell() {}

    bool IsEmpty();

    Position GetPosition();
    Object* GetObject();
    void EnableState(Position end, Cell* previous_cell = nullptr);
    State* GetState();

    void SetPosition(Position position);
    void SetState(State state) {state_ = state; }
    void MakeEmpty();
    void SetObject(Object* object);
    void ResetState() {State empty_state; state_ = empty_state;}
    void Reset();
    
  private:
    Position position_;
    State state_;
    Object* object_;
    bool empty_{true};

    void Change(Object* object = nullptr);
};