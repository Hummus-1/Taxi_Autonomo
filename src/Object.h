#pragma once

#include <iostream>

typedef std::pair<int, int> Position;

class Object {
  public:
    Object() {}
    Object(Position position);
    Position GetPosition();
    virtual bool IsInGoal() {return 1;}
    virtual bool IsFinished() {return 1;}
    virtual void SetGoal(Position goal) {}
    virtual ~Object() = default;

  protected:
    Position position_;
};
