#pragma once

#include <iostream>

typedef std::pair<int, int> Position;

class Object {
  public:
    Object() {}
    Object(Position position);
    Position GetPosition();
    virtual ~Object() = default;

  protected:
    Position position_;
};
