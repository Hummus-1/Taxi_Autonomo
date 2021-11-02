#include "Menu.h"

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
  std::cout << "Seleccione '0' para el modo aleatorio \n";
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
    obstacle.first = RequestInt(0, n - 1);
    std::cout << "Introduzca numero de columna: ";
    obstacle.second = RequestInt(0, m - 1);
    world->AddObstacle(obstacle);
  }
}

void AutomaticObstacles(unsigned n, unsigned m, World* world) {
  std::cout << "\nHa seleccionado el modo automático \n";
  std::cout << "Seleccione el porcentaje de obstáculos deseado: ";
  world->GenerateObstacles(((n * m * RequestInt(0, 100)) / 100));
}

void FileInput(World* world, std::string filename) {
  try {
    std::queue<int> file_data = ReadFile(filename);
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
}

Position SelectVehicle(World* world) {
  Position start;
  try {
    std::cout << "A continuación deberá seleccionar la posición de inicio de la ruta \n";
    std::cout << "Introduzca el numero de fila: ";
    start.first = RequestInt(0, world->GetN() - 1);
    std::cout << "Introduzca numero de columna: ";
    start.second = RequestInt(0, world->GetM() - 1);
    world->IsEmpty(start);
  }
  catch (const std::overflow_error& e) {
    std::cout << "\033[31m" <<  "Posicion introducida ya ocupada\n" << "\033[0m";
    return SelectVehicle(world);
  }
  return start;
}

Position SelectGoal(World* world) {
  Position end;
  try {
    std::cout << "A continuación deberá seleccionar la posición final de la ruta \n";
    std::cout << "Introduzca el numero de fila: ";
    end.first = RequestInt(0, world->GetN() - 1);
    std::cout << "Introduzca numero de columna: ";
    end.second = RequestInt(0, world->GetM() - 1);
    world->IsEmpty(end);
  }
  catch(const std::overflow_error& e){
    std::cout << "\033[31m" <<  "Posicion introducida ya ocupada\n" << "\033[0m";
    return SelectGoal(world);
  }
  return end;
}

void ExportWorld(World* world) {
  std::fstream file = OpenFile("ExportedWorld.txt");
  file << world->GetN() << " " << world->GetM() << "\n";
  file << "1 \n";
  file << world->GetNumberOfObstacles() << "\n";
  for (unsigned i = 0; i < world->GetN(); i++) {
    for (unsigned j = 0; j < world->GetM(); j++) {
      if (world->IsObstacle(std::make_pair<int, int>(i, j)) == true)
        file << i << " " << j << "\n";
    }
  }
}

void Route(World* world) {
  Position start, end;
  start = SelectVehicle(world);
  end = SelectGoal(world);
  std::cout << "\nSeleccione la funcion heuristica que desea usar\n";
  std::cout << "Seleccione 0 para la Rectilinea\n";
  std::cout << "Seleccione 1 para la Euclidea\n";
  bool heuristic_mode = RequestBool();
  std::cout << "\nElija el número de direcciones que quiere que tenga el vehículo\n";
  std::cout << "Seleccione 0 para 4\n";
  std::cout << "Seleccione 1 para 8\n";
  world->StartRoute(start, end, heuristic_mode, RequestBool());
  world->Clear();
}

void MenuMessage() {
  std::cout << "\n1. Crear un nuevo entorno\n";
  std::cout << "2. Visualizar el entorno\n";
  std::cout << "3. Procesar y visualizar una nueva trayectoria\n";
  std::cout << "4. Ayuda \n";
  std::cout << "5. Exportar mundo \n";
  std::cout << "6. Salir del programa\n";
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
    std::cout << "\n\n1. Crear un nuevo entorno (crear un nuevo mundo donde el taxi se movera)\n";
    std::cout << "2. Visualizar el entorno (muestra por pantalla el entorno que se ha creado)\n";
    std::cout << "3. Procesar y visualizar una nueva trayectoria (A partir del inicio y el final te muestra el \ncamino minimo)\n";
    std::cout << "4. Ayuda \n";
    std::cout << "5. Exportar mundo actual al archivo 'ExportedWorld.txt' \n";
    std::cout << "6. Salir del programa (Cerrar el programa)\n";
  }
}

void Menu() {
  World menu_world;
  bool init {false};
  bool repeat {true};
  while (repeat) {
    MenuMessage();
    switch (RequestInt(1, 6)) {
        case 1:
          CreateEnvironment(&menu_world);
          init = true;
          break;
        case 2:
          if (!init) {
            std::cout << "Selecciona primero la opcion 1 \n";
            break;
          }
          menu_world.Print();
          break;
        case 3:
          if (!init) {
            std::cout << "Selecciona primero la opcion 1 \n";
            break;
          }
          Route(&menu_world);
          break;
        case 4:
          Help();
          break;
        case 5:
          ExportWorld(&menu_world);
          break;
        case 6:
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