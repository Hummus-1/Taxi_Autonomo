#include "Menu.h"

bool RequestBool() {
  try {
    bool option; std::cin >> option;
    if (!std::cin >> option) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      throw "Argumento invalido";
    }
    return option;
  }
  catch(const char* error) {
    std::cout << error << "\n";
    return RequestBool();
  }
  catch (const std::invalid_argument& e) {
    std::cout << e.what() << "\n";
    return RequestBool();
  }
}

int RequestInt(int min, int max) {
  try {
    int value; std::cin >> value;
    if (!std::cin >> value) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      throw "Argumento invalido";
    }
    if (value < min || value > max)
      throw "Valor introducido no valido";
    return value;
  }
  catch(const char* error) {
    std::cout << error << "\n";
    std::cout << "El valor debe estar dentro del rango " << min << "-" << max << "\n";
    return RequestInt(min, max);
  }
  catch (const std::invalid_argument& e) {
    std::cout << e.what() << "\n";
    return RequestInt(min, max);
  }
}

void CreateEnvironment(World *world) {
  std::cout << "\n\nA continuación seleccione el modo de introducir los datos:\n";
  std::cout << "Selecciones '0' para emplear la terminal\n";
  std::cout << "Selecciones '1' para emplear un fichero de texto\n";
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
  std::cout << "Selecciones '0' para el modo aleatorio \n"; // no se si porner otra palabra
  std::cout << "Selecciones '1' para el modo manual \n";
  world->Reset(n, m);
  if (RequestBool())
    ManualObstacles(n, m, world);
  else
    AutomaticObstacles(n, m, world);
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
  world->GenerateObstacles(((n * m *RequestInt(0, 100)) / 100));
}

void FileInput(World* world) {
  std::queue<int> file_data;
  std::string dato;
  std::cout << "Introduzca el nombre del archivo \n";
  std::string input_filename="";
  std::cin >> input_filename;
  try {
    std::ifstream input_file(input_filename);
    if (!input_file.is_open()) {
      std::cerr << "Error al abrir el archivo \n"; 
    }
    while (input_file >> dato) {
      if (!IsNumeric(dato))
        throw "Alguno de los valores del archivo no son correctos";
      file_data.push(stoi(dato));
    }
    input_file.close();
  }
  catch(const char* error) {
    std::cout << error << "\n";
    return FileInput(world);
  }
}

void Route(World* world) { // Hay que pasarle objeto mundo
  Position start, end;
  std::cout << "A continuación deberá seleccionar la posición de inicio de la ruta \n";
  std::cout << "Introduzca el numero de fila: ";
  start.first = RequestInt(0, 100); // El maximo vendra definido por el objeto mundo
  std::cout << "Introduzca numero de columna: ";
  start.second = RequestInt(0, 100); // El maximo vendra definido por el objeto mundo
  std::cout << "A continuación deberá seleccionar la posición final de la ruta \n";
  std::cout << "Introduzca el numero de fila: ";
  end.first = RequestInt(0, 100); // El maximo vendra definido por el objeto mundo
  std::cout << "Introduzca numero de columna: ";
  end.second = RequestInt(0, 100); // El maximo vendra definido por el objeto mundo
  world->AddVehicle(start);
  world->Print();
  // GenerateRoute(start, end)
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
  bool init {false};
  bool repeat {true};
  while (repeat) {
    MenuMessage();
    switch (RequestInt(1, 5)) {
        case 1:
          CreateEnvironment(&menu_world); //error al crear uno despues de hacer otro
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
  std::cout << " ------------------------------------------------------------------\n";
  std::cout << "|                  ¡¡Bienvenido al taxi autonomo DAR!!             |\n";            
  std::cout << " ------------------------------------------------------------------\n";
}