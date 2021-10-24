#pragma once

#include <iostream>

typedef std::pair<int, int> Position;

class Object {
  public:
    Object() {}
    Object(Position position);
    Position GetPosition();
    virtual bool IsInGoal() {return 1;}
    virtual void SetGoal(Position goal) {}
    //virtual Position Move(void* to_vector) {return std::make_pair<int, int> (0, 0);}
    virtual ~Object() = default;

  protected:
    Position position_;
};
