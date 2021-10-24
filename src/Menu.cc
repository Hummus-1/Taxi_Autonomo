#include "Menu.h"

void InputTypeError() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  throw std::invalid_argument("Debe introducirse un numero");
}

bool VerifyInt(int min, int max, int value) {
  if (!std::cin >> value)
    InputTypeError();
  if (value < min || value > max)
    throw std::length_error("El valor '" + std::to_string(value) + "' debe estar dentro del rango " + std::to_string(min) + "-" + std::to_string(max));
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

void CreateEnvironment(World *world) {
  std::cout << "\n\nA continuación seleccione el modo de introducir los datos:\n";
  std::cout << "Selecciona '0' para emplear la terminal\n";
  std::cout << "Selecciona '1' para emplear un fichero de texto\n";
  if (RequestBool())
    return FileInput(world);
  else
    return TerminalInput(world);
}

void TerminalInput(World *world) {
  std::cout << "\nIntroduce el tamaño del entorno\n";
  std::cout << "A continuación introduce el largo del entorno: ";
  int n = RequestInt(10, 1000);
  std::cout << "A continuación introduce el ancho del entorno: ";
  int m = RequestInt(10, 1000);
  std::cout << "\nA continuación seleccione el modo de introducir los obstaculos:\n";
  std::cout << "Seleccione '0' para el modo aleatorio \n"; // no se si porner otra palabra
  std::cout << "Seleccione '1' para el modo manual \n";
  world->Reset(n, m);
  if (RequestBool())
    ManualObstacles(n, m, world);
  else
    AutomaticObstacles(n, m, world);
  std::cout << "\033[32m" << "Entorno creado satisfactoriamente\n" << "\033[0m";
}

void ManualObstacles(unsigned n, unsigned m, World* world) {
  Position obstacle;
  std::cout << "\nHa seleccionado el modo manual \n";
  std::cout << "Introduzca el número de obstáculos deseado: ";
  for (unsigned i = RequestInt(0, n * m); i > 0; i--) {
    std::cout << "Introduzca el numero de fila: ";
    obstacle.first = RequestInt(0, n);
    std::cout << "Introduzca numero de columna: ";
    obstacle.second = RequestInt(0, m);
    world->AddObstacle(obstacle);
  }
}

void AutomaticObstacles(unsigned n, unsigned m, World* world) {
  std::cout << "\nHa seleccionado el modo automático \n";
  std::cout << "Seleccione el porcentaje de obstáculos deseado: ";
  world->GenerateObstacles(((n * m * RequestInt(0, 100)) / 100));
}

void FileInput(World* world) {
  std::queue<int> file_data;
  std::string dato, input_filename = "ej.txt";
  std::cout << "Introduzca el nombre del archivo: ";
  //std::cin >> input_filename;
  //std::cin.clear();
  //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  try {
    std::ifstream input_file(input_filename);
    if (!input_file.is_open())
      throw std::ifstream::failure(input_filename);
    while (input_file >> dato) {
      if (!IsNumeric(dato))
        throw std::invalid_argument(dato);
      file_data.push(stoi(dato));
    }
    input_file.close();
  unsigned m = file_data.front();
  file_data.pop();
  unsigned n = file_data.front();
  file_data.pop();
  world->Reset(n, m);
  if (file_data.front() == 0) {
    file_data.pop();
    VerifyInt(0, 100, file_data.front());
    world->GenerateObstacles(((n * m * file_data.front()) / 100));
  }
  else if (file_data.front() == 1) {
    file_data.pop();
    Position obstacle;
    for (unsigned i = file_data.front(); i > 0; i--) {
      file_data.pop();
      obstacle.first = file_data.front();
      file_data.pop();
      obstacle.second = file_data.front();
      world->AddObstacle(obstacle);
    }
    file_data.pop();
  }
  else 
    throw std::length_error("El valor de la línea 2 debe ser 0 o 1");
  std::cout << "\033[32m" << "Entorno creado satisfactoriamente\n" << "\033[0m";
  }
  catch(const std::ifstream::failure& e) {
    std::cout << "\033[31m" << "No se puedo abrir el archivo" << "\033[0m" << "\n";
  }
  catch (const std::length_error& e) {
    std::cout << "\033[31m" << e.what() << "\033[0m" << "\n";
  }
  catch (const std::invalid_argument& e) {
    std::cout << "\033[31m" << "El valor '" << e.what() << "' no está en el formato correcto" "\033[0m" << "\n";
  }
}

Position SelectVehicle(World* world) {
  Position start;
  try {
    std::cout << "A continuación deberá seleccionar la posición de inicio de la ruta \n";
    std::cout << "Introduzca el numero de fila: ";
    start.first = RequestInt(0, world->GetN());
    std::cout << "Introduzca numero de columna: ";
    start.second = RequestInt(0, world->GetM());
    world->AddVehicle(start);
  }
  catch (const std::overflow_error& e) {
    std::cout << "\033[31m" <<  "Posicion introducida ya ocupada\n" << "\033[0m";
    SelectVehicle(world);
  }
  return start;
}

Position SelectGoal(World* world) {
  Position end;
  try {
    std::cout << "A continuación deberá seleccionar la posición final de la ruta \n";
    std::cout << "Introduzca el numero de fila: ";
    end.first = RequestInt(0, world->GetN());
    std::cout << "Introduzca numero de columna: ";
    end.second = RequestInt(0, world->GetM());
    world->AddGoal(end);
  }
  catch(const std::overflow_error& e){
    std::cout << "\033[31m" <<  "Posicion introducida ya ocupada\n" << "\033[0m";
    SelectGoal(world);
  }
  return end;
}

void Route(World* world) {
  Position start, end;
  start = SelectVehicle(world);
  end = SelectGoal(world);
  world->StartRoute(start, end);
}

void MenuMessage() {
  std::cout << "\n1. Crear un nuevo entorno\n";
  std::cout << "2. Visualizar el entorno\n";
  std::cout << "3. Procesar y visualizar una nueva trayectoria\n";
  std::cout << "4. Ayuda \n";
  std::cout << "5. Salir del programa\n";
}

void Help() {
  std::cout << "Si necesita mas informacion de las opciones del menu seleccione 0\n"; // se puede redactar mejor
  std::cout << "Si necesita ayuda con el formato del fichero seleccione 1\n"; 
  if (RequestBool()) {
    std::cout << "\n\nEl diseño del fichero debe seguir el siguiente formato:";
    std::cout << "10 10 -> n m separados por espacios indicando el tamaño del entorno\n";
    std::cout << "0 -> 0 o 1 para seleccionar modo auto o manual";
    std::cout << "30 -> si es auto introducir un numero entero entre 0 y 100 para indicar el numero de obstaculos";
    std::cout << "1 -> si es manual -> primero se pone el numero (entero entre 0 y n*m) de obstaculos a poner";
    std::cout << "y luego añadir posicion de cada obstaculo -> n m";
  } else {
    std::cout << "\n\n1. Crear un nuevo entorno (crear un nuevo mundo donde el taxi se movera\n";
    std::cout << "2. Visualizar el entorno (muestra por pantalla el entorno que se ha creado)\n";
    std::cout << "3. Procesar y visualizar una nueva trayectoria (A partir del inicio y el final te muestra el \ncamino minimo\n";
    std::cout << "4. Ayuda \n";
    std::cout << "5. Salir del programa (Cerrar el programa)\n";
  }
}

void Menu() {
  World menu_world;
  FileInput(&menu_world);
  menu_world.AddVehicle(make_pair<int, int>(3, 0));
  menu_world.AddGoal(make_pair<int, int>(0, 0));
  menu_world.StartRoute(make_pair<int, int>(3, 0), make_pair<int, int>(0, 0));
  bool init {false};
  bool repeat {true};
  while (repeat) {
    MenuMessage();
    switch (RequestInt(1, 5)) {
        case 1:
          CreateEnvironment(&menu_world);
          init = true;
          break;
        case 2:
          if (!init) {
            cout << "Selecciona primero la opcion 1 \n";
            break;
          }
          menu_world.Print();
          break;
        case 3:
          if (!init) {
            cout << "Selecciona primero la opcion 1 \n";
            break;
          }
          Route(&menu_world);
          break;
        case 4:
          Help();
          break;
        case 5:
          repeat = false;
          break;
        default:
          break;
    }
  }
}

void Welcome() {
  std::cout << "\033[34m" <<" --------------------------------------------------------------------\n" << "\033[0m";
  std::cout << "\033[34m" << "|" << "\033[0m" << "                 ¡¡Bienvenido al taxi autonomo DAR!!                " << "\033[34m" << "|\n" << "\033[0m";        
  std::cout << "\033[34m" <<" --------------------------------------------------------------------\n" << "\033[0m";
}