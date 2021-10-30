#pragma once

#include <iostream>
#include <utility>
#include <memory>
#include <vector>

#include "State.h"

void Merge(std::vector<State*>& sequence, int ini, int centre, int end);
void Msort(std::vector<State*>& sequence, int ini, int end);
void Mergesort(std::vector<State*>& sequence);
bool compare(const State* state_1, const State* state_2);