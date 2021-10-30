#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <limits>
#include <string>

#include "MenuUtility.h"
#include "World.h"
#include "Cell.h"

void TerminalInput(World* world);
Position SelectVehicle(World* world);
Position SelectGoal(World* world);
void ManualObstacles(unsigned n, unsigned m, World* world);
void AutomaticObstacles(unsigned n, unsigned m, World* world);
void FileInput(World* world, std::string filename = "");
void Route(World* world);
void CreateEnvironment(World* world);
void ExportWorld(World* world);
void MenuMessage();
void Help();
void Menu();
void Welcome();