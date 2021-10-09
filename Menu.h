#pragma once

#include "MenuUtility.h"

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
void ManualObstacles(int n, int m);
void AutomaticObstacles(int n, int m);
void FileInput();
void Route();
void CreateEnvironment();
void MenuMessage();
void Help();
void Menu();
void Welcome();
/* includes al resto de archivos*/


