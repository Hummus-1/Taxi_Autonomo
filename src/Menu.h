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

bool RequestBool();
int RequestInt(int min, int max);
void TerminalInput(World* world);
void ManualObstacles(unsigned n, unsigned m, World* world);
void AutomaticObstacles(unsigned n, unsigned m, World* world);
void FileInput(World* world);
void Route(World* world);
void CreateEnvironment(World* world);
void MenuMessage();
void Help();
void Menu();
void Welcome();
/* includes al resto de archivos*/


