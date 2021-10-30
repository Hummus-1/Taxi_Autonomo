#pragma once

#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <queue>
#include <fstream>

std::vector<std::string> split(const std::string str, const unsigned splits);
bool IsNumeric(std::string str);
void InputTypeError();
bool RequestBool();
std::string RequestString();
bool VerifyInt(int min, int max, int value);
int RequestInt(int min, int max);
std::queue<int> ReadFile(std::string filename = "");
std::fstream OpenFile(std::string filename = "");