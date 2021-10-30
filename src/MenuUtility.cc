#include "MenuUtility.h"

std::vector<std::string> split(const std::string str, const unsigned splits) {
  std::vector <std::string> str_split(splits);
  unsigned count = 0;
  for (unsigned i = 0; i < str.length(); i++) {
    if (str[i] != ' ')
      str_split[count] += str[i]; 
    else
      count++;
  }
  return str_split;
}

bool IsNumeric(std::string str) {
   for (int i = 0; i < str.length(); i++)
      if (isdigit(str[i]) == false)
         return false;
      return true;
}

void InputTypeError() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  throw std::invalid_argument("Debe introducirse un numero");
}

bool VerifyInt(int min, int max, int value) {
  if (!std::cin >> value)
    InputTypeError();
  if (value < min || value > max)
    throw std::length_error("El valor a introducir debe estar dentro del rango " + std::to_string(min) + "-" + std::to_string(max));
  return 1;
}

int RequestInt(int min, int max) {
  try {
    int value; std::cin >> value;
    VerifyInt(min, max, value);
    return value;
  }
  catch(const std::invalid_argument& e) {
    std::cout << "\033[31m" << "Argumento inválido. " << e.what() << "\033[0m" << "\n";
    return RequestInt(min, max);
  }
  catch(const std::length_error& e) {
    std::cout << "\033[33m" << e.what() << "\033[0m" << "\n";
    return RequestInt(min, max);
  }
}

bool RequestBool() {
  return bool(RequestInt(0, 1));
}

std::string RequestString() {
  std::string str;
  std::cin >> str;
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return str;
}

std::queue<int> ReadFile(std::string filename) {
  std::queue<int> data;
  try {
    std::fstream file = OpenFile(filename);
    std::string dato;
      while (file >> dato) {
        if (!IsNumeric(dato))
          throw std::invalid_argument(dato);
        data.push(stoi(dato));
      }
    file.close();
  }
  catch(const std::ifstream::failure& e) {
    std::cout << "\033[31m" << "No se puedo abrir el archivo" << "\033[0m" << "\n";
    return ReadFile();
  }
  catch (const std::invalid_argument& e) {
    std::cout << "\033[31m" << "El valor '" << e.what() << "' no está en el formato correcto" "\033[0m" << "\n";
    return ReadFile();
  }
  return data;
}

std::fstream OpenFile(std::string filename) {
  std::cout << "Introduzca el nombre del archivo: ";
  if (filename.size() == 0) 
    filename = RequestString();
  std::fstream input_file(filename);
  try {
    if (!input_file.is_open())
      throw std::ifstream::failure(filename);
  }
  catch(const std::ifstream::failure& e) {
    std::cout << "\033[31m" << "No se puedo abrir el archivo" << "\033[0m" << "\n";
    return OpenFile();
  }
  return input_file;
}