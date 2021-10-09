/*
AUTOR: Daniel García Hernández
EMAIL: alu0101353340@ull.edu.es
*/

#include "MenuUtility.h"

vector<string> split(const string str, const unsigned splits) {
  vector <string> str_split(splits);
  unsigned count = 0;
  for (unsigned i = 0; i < str.length(); i++) {
    if (str[i] != ' ')
      str_split[count] += str[i]; 
    else
      count++;
  }
  return str_split;
}

bool IsNumeric(string str) {
   for (int i = 0; i < str.length(); i++)
      if (isdigit(str[i]) == false)
         return false;
      return true;
}