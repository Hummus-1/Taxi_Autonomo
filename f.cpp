#include <iostream>
#include <fstream>
#include <string>

class A
{
public:
    A(const std::string filename)
    {
       std::ifstream file;
       file.exceptions( std::ifstream::failbit | std::ifstream::badbit);
       file.open(filename);
       int dato;
       file >> dato;
       std::cout << dato << std::endl;
    }
};

int main()
{
    std::string filename("eji.txt");
    try
    {
        A MyClass(filename);
    }
    catch (std::ifstream::failure e)
    {
        std::cerr << "Error reading file" << std::endl;
    }
}