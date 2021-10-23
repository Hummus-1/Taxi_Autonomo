#include "World.h"

World::World(unsigned n, unsigned m) {

}

World::~World() {
  
}

void World::IsEmpty(Position position){
  if (!GetCell(position)->IsEmpty())
    throw std::overflow_error("Posición ocupaba");
}

Cell* World::GetCell(Position position){
  try {
    return &world_[position.first][position.second];
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
    GetCell(position)->SetObject(std::make_shared<Obstacle>(position));
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
      world_[position.first][position.second].SetObject(std::make_shared<Obstacle>(position));
    }
    else
      i--;
  }
}

void World::AddVehicle(Position position) {
  try {
    IsEmpty(position);
    GetCell(position)->SetObject(std::make_shared<Vehicle>(position, GetCell(position)));
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
    GetCell(position)->SetObject(std::make_shared<Goal>(position));
  }
  catch (const std::out_of_range& e) {
    throw e;
  }
  catch (const std::overflow_error& e) {
    throw e;
  }
}

void World::StartRoute(Position start, Position end) {
  GetCell(start)->GetState()->Enable(start, end);
}

void World::Reset(unsigned n, unsigned m) {
  assert(n > 2 && m > 2);
  n_rows_ = n;
  n_columns_ = m;
  world_.resize(n_rows_);
  for (unsigned i = 0; i < n; i++) {
    world_[i].resize(n_columns_);
    for (unsigned j = 0; j < m; j++) {
      world_[i][j].SetPosition(std::make_pair<int, int>(i, j));
      world_[i][j].MakeEmpty();
    }
  }
}

unsigned World::GetN() {
  return n_rows_;
}

unsigned World::GetM() {
  return n_columns_;
}

void World::Print() {
  std::cout << "\n";
  for (unsigned i = 0; i < n_rows_; i++) {
    for (unsigned j = 0; j < n_columns_; j++) {
      if(!world_[i][j].IsEmpty()) {
        if (dynamic_cast<Vehicle*>(world_[i][j].GetObject().get()) != 0)
          std::cout << "\033[0;42m" << " " << "\033[0m";
        else if (dynamic_cast<Obstacle*>(world_[i][j].GetObject().get()) != 0)
          std::cout << "\033[0;44m" << " " << "\033[0m";
        else if (dynamic_cast<Goal*>(world_[i][j].GetObject().get()) != 0)
          std::cout << "\033[0;41m" << " " << "\033[0m";
      }
      else
        std::cout << "\033[0;47m" << " " << "\033[0m";
      if (j == n_columns_ - 1)
        std::cout << "\n";
    }
  }
  std::cout << "\n";
}

