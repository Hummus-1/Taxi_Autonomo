#include "Compare.h"

bool compare(const State* state_1, const State* state_2) {
  return (state_1->GetFn() > state_2->GetFn()) || (((state_1->GetFn() == state_2->GetFn()) && state_1->GetGn() < state_2->GetGn()));
}