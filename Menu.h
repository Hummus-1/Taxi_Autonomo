#pragma once

#include "MenuUtility.h"
#include "Cell.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <limits>
#include <string>

bool RequestBool();
int RequestInt(int min, int max);
void TerminalInput();
void ManualObstacles(unsigned n, unsigned m);
void AutomaticObstacles(unsigned n, unsigned m);
void FileInput();
void Route(); // Pasar el objeto mundo
void CreateEnvironment();
void MenuMessage();
void Help();
void Menu();
void Welcome();
/* includes al resto de archivos*/


