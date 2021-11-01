#include "World.h"

World::World(unsigned n, unsigned m) {
  n_rows_ = n;
  n_columns_ = m;
}

World::~World() {
  
}

void World::IsEmpty(Position position){
  try {
    if (!GetCell(position)->IsEmpty() && dynamic_cast<Goal*>(GetCell(position)->GetObject()) == 0)
      throw std::overflow_error("Posición ocupaba");
  }
  catch (const std::out_of_range& e) {
    throw e;
  }
}

bool World::IsObstacle(Position position) {
  if (dynamic_cast<Obstacle*>(GetCell(position)->GetObject()) != 0)
    return true;
  else
    return false;
}

Cell* World::GetCell(Position position){
  try {
    return &world_.at(position.first).at(position.second);
  }
  catch (const std::out_of_range& e) {
    throw e;
  }
}

void World::Resize(unsigned n, unsigned m) {
  assert(n > 2 && m > 2);
  n_rows_ = n;
  n_columns_ = m;
  world_.resize(n_rows_);
  for (unsigned i = 0; i < n; i++) {
    world_[i].resize(n_columns_);
    for (unsigned j = 0; j < m; j++) {
      world_[i][j].SetPosition(std::make_pair<int, int>(i, j));
    }
  }
}

void World::AddObstacle(Position position) {
  try {
    IsEmpty(position);
    GetCell(position)->SetObject(new Obstacle(position));
    n_obstacles_ += 1;
  }
  catch (const std::out_of_range& e) {
    throw e;
  }
  catch (const std::overflow_error& e) {
    throw e;
  }
}

void World::GenerateObstacles(unsigned number) {
  srand((unsigned)time(NULL));
  for (unsigned i = 0; i < number; i++) {
    Position position = std::make_pair<int, int>(std::rand() % n_rows_, std::rand() % n_columns_);
    if (world_[position.first][position.second].IsEmpty()) {
      world_[position.first][position.second].SetObject(new Obstacle(position));
    }
    else
      i--;
  }
  n_obstacles_ += number;
}

void World::AddVehicle(Position position) {
  try {
    IsEmpty(position);
    GetCell(position)->SetObject(new Vehicle(position, GetCell(position)));
  }
  catch (const std::out_of_range& e) {
    throw e;
  }
  catch (const std::overflow_error& e) {
    throw e;
  }
}

void World::AddGoal(Position position) {
  try {
    IsEmpty(position);
    GetCell(position)->SetObject(new Goal(position));
  }
  catch (const std::out_of_range& e) {
    throw e;
  }
  catch (const std::overflow_error& e) {
    throw e;
  }
}

std::vector<Cell*> World::GetAdjacent(Position position,bool adjacent_mode) {
  Direction directions(position);
  std::vector<Cell*> adjacents(0);
  try {
    IsEmpty(directions.GetDirectionUp());
    adjacents.push_back(GetCell(directions.GetDirectionUp()));
  }
  catch (const std::out_of_range& e) {}
  catch (const std::overflow_error& e) {}
  try {
    IsEmpty(directions.GetDirectionRight());
    adjacents.push_back(GetCell(directions.GetDirectionRight()));
  }
  catch (const std::out_of_range& e) {}
  catch (const std::overflow_error& e) {}
  try {
    IsEmpty(directions.GetDirectionLeft());
    adjacents.push_back(GetCell(directions.GetDirectionLeft()));
  }
  catch (const std::out_of_range& e) {}
  catch (const std::overflow_error& e) {}
  try {
    IsEmpty(directions.GetDirectionDown());
    adjacents.push_back(GetCell(directions.GetDirectionDown()));
  }
  catch (const std::out_of_range& e) {}
  catch (const std::overflow_error& e) {}
  if (adjacent_mode) {
      try {
        IsEmpty(directions.GetDirectionUpRight());
        adjacents.push_back(GetCell(directions.GetDirectionUpRight()));
      }
      catch (const std::out_of_range& e) {}
      catch (const std::overflow_error& e) {}
        try {
        IsEmpty(directions.GetDirectionDownRight());
        adjacents.push_back(GetCell(directions.GetDirectionDownRight()));
      }
      catch (const std::out_of_range& e) {}
      catch (const std::overflow_error& e) {}
        try {
        IsEmpty(directions.GetDirectionDownLeft());
        adjacents.push_back(GetCell(directions.GetDirectionDownLeft()));
      }
      catch (const std::out_of_range& e) {}
      catch (const std::overflow_error& e) {}
        try {
        IsEmpty(directions.GetDirectionUpLeft());
        adjacents.push_back(GetCell(directions.GetDirectionUpLeft()));
      }
      catch (const std::out_of_range& e) {}
      catch (const std::overflow_error& e) {}
    }
  return adjacents;
}

void World::StartRoute(Position start, Position end, bool heuristic_mode, bool adjacent_mode) {
  AddVehicle(start);
  AddGoal(end);
  Vehicle* vehicle = (Vehicle*)(GetCell(start)->GetObject());
  vehicle->SetGoal(end);
  Position actual_position = start;
  
  clock_t t_start = clock();
  
  std::vector<Cell*> adjacents = GetAdjacent(start, adjacent_mode);
  if (heuristic_mode)
    GetCell(start)->EnableEuclideanState(end);
  else
    GetCell(start)->EnableRectilinearState(end);
  
  while (1) {
    GetCell(actual_position)->MakeEmpty();
    try {
      actual_position = vehicle->Move(GetAdjacent(actual_position, adjacent_mode), heuristic_mode);
    }
    catch (const std::out_of_range& e) {
      Print();
      std::cout << "No hay forma de realizar la ruta escogida\n";
      break;
    }
    GetCell(actual_position)->SetObject((Object*)vehicle);
    vehicle->SetCell(GetCell(actual_position));
    if (vehicle->IsFinished()) {
      vehicle->Finished();
      GetCell(start)->MakeEmpty();
      AddVehicle(start);
      GetCell(end)->MakeEmpty();
      AddGoal(end);
      Print();
      std::cout << "El coste del camino mínimo es: " << GetCell(actual_position)->GetState()->GetGn() << "\n";
      break;
    }
  }
  std::cout << "Se han visitado " << vehicle->GetVisitedCells() << " casillas\n";
  std::cout << "Se han explorado " << vehicle->GetExploredCells() << " casillas\n";
  std::cout << "El tiempo de ejecución ha sido de: " << (double)(clock() - t_start)/CLOCKS_PER_SEC << " segundos \n";
}

void World::Clear() {
  for (unsigned i = 0; i < n_rows_; i++) {
    for (unsigned j = 0; j < n_columns_; j++) {
      world_[i][j].ResetState();
      if ((dynamic_cast<Vehicle*>(world_[i][j].GetObject()) != 0)
      ||(dynamic_cast<Goal*>(world_[i][j].GetObject()) != 0))
        world_[i][j].MakeEmpty();
    }
  }
}

void World::Reset(unsigned n, unsigned m) {
  if (n != 0 && m != 0) {
    n_rows_ = n;
    n_columns_ = m;
  }
  assert(n_rows_ > 2 && n_columns_ > 2);
  n_obstacles_ = 0;
  world_.resize(n_rows_);
  for (unsigned i = 0; i < n_rows_; i++) {
    world_[i].resize(n_columns_);
    for (unsigned j = 0; j < n_columns_; j++) {
      world_[i][j].Reset();
      world_[i][j].SetPosition(std::make_pair<int, int>(i, j));
    }
  }
}

unsigned World::GetN() {
  return n_rows_;
}

unsigned World::GetM() {
  return n_columns_;
}

unsigned World::GetNumberOfObstacles() {
  return n_obstacles_;
}

void World::Print() {
  std::cout << "\n";
  std::cout << "\033[0;42m" << " " << "\033[0m -> Vehículo";
  std::cout << "    \033[0;41m" << " " << "\033[0m -> Meta";
  std::cout << "    \033[0;44m" << " " << "\033[0m -> Obstáculo \n";
  std::cout << "\033[0;43m" << " " << "\033[0m -> Camino mínimo";
  std::cout << "    \033[0;46m" << " " << "\033[0m -> Celda visitada";
  std::cout << "    \033[0;45m" << " " << "\033[0m -> Celda explorada \n\n";
  for (unsigned i = 0; i < n_rows_; i++) {
    for (unsigned j = 0; j < n_columns_; j++) {
      if(!world_[i][j].IsEmpty()) {
        if (dynamic_cast<Vehicle*>(world_[i][j].GetObject()) != 0)
          std::cout << "\033[0;42m" << " " << "\033[0m";
        else if (dynamic_cast<Obstacle*>(world_[i][j].GetObject()) != 0)
          std::cout << "\033[0;44m" << " " << "\033[0m";
        else if (dynamic_cast<Goal*>(world_[i][j].GetObject()) != 0)
          std::cout << "\033[0;41m" << " " << "\033[0m";
      }
      else if (world_[i][j].GetState()->IsRoute())
        std::cout << "\033[0;43m" << " " << "\033[0m";
      else if (world_[i][j].GetState()->IsVisited())
        std::cout << "\033[0;46m" << " " << "\033[0m";
      else if (world_[i][j].GetState()->IsExplored())
        std::cout << "\033[0;45m" << " " << "\033[0m";
      else
        std::cout << "\033[0;47m" << " " << "\033[0m";
      if (j == n_columns_ - 1)
        std::cout << "\n";
    }
  }
  std::cout << "\n";
}

