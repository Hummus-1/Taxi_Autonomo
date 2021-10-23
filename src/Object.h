#pragma once

#include <iostream>

typedef std::pair<int, int> Position;

class Object {
  public:
    Object() {}
    Object(Position position);
    Position GetPosition();
    virtual bool IsInGoal(Position position_f){return 1;}
    virtual ~Object() = default;

  protected:
    Position position_;
};
