#pragma once

#include <iostream>
#include <utility>
#include <memory>
#include <vector>

#include "State.h"

void Merge(std::vector<State*>& sequence, int ini, int centre, int end);
void Msort(std::vector<State*>& sequence, int ini, int end);