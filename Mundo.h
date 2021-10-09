
/*
Nombre:Mundo.h y Mundo.cc

Lenguaje: C++

*/
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

class Mundo
{
private:
    int mundo_array_[10][10];

public:
    void CrearMundo(int anchura, int altura);
};