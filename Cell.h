#pragma once 
#include <array>
#include <cstdlib>
#include <ctime>
#include <errno.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <vector>
class Cell{
 private:
    bool in_use_;
 public:
    Cell();
    Cell(bool in_use);
    bool GetUse();
    bool SetUse(bool in_use);
}