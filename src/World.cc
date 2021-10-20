#include "World.h"

World::World(unsigned n, unsigned m) {

}

World::~World() {
  
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
  world_[position.first][position.second].SetObject(std::make_shared<Obstacle>(position));
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
  world_[position.first][position.second].SetObject(std::make_shared<Vehicle>(position));
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

void World::Print() {
  /*std::cout << " ";
  for (unsigned i = 0; i < n_columns_; i++) {
    std::cout << "_";
  }*/
  std::cout << "\n";
  for (unsigned i = 0; i < n_rows_; i++) {
    for (unsigned j = 0; j < n_columns_; j++) {
      /*if (j == 0)
        std::cout << "|";*/
      if(!world_[i][j].IsEmpty()) {
      if (dynamic_cast<Vehicle*>(world_[i][j].GetObject().get()) != 0)
        std::cout << "\033[0;42m" << " " << "\033[0m";
      else if (dynamic_cast<Obstacle*>(world_[i][j].GetObject().get()) != 0)
        std::cout << "\033[0;44m" << " " << "\033[0m";
      }
      else
        std::cout << "\033[0;47m" << " " << "\033[0m";
        //std::cout << "\u25A0";
      if (j == n_columns_ - 1)
        std::cout << "\n";
        //std::cout << "| \n";
    }
  }
  /*std::cout << " ";
  for (unsigned i = 0; i < n_columns_; i++) {
    std::cout << "-";
  }*/
  std::cout << "\n";

  
  for (unsigned i = 0; i < (n_columns_ + 2); i++) {
    std::cout << "\033[0;47m" << " " << "\033[0m";
  }
  std::cout << "\n";
  for (unsigned i = 0; i < n_rows_; i++) {
    for (unsigned j = 0; j < n_columns_; j++) {
      if (j == 0)
        std::cout << "\033[0;47m" << " " << "\033[0m";
      if(!world_[i][j].IsEmpty()) {
      if (dynamic_cast<Vehicle*>(world_[i][j].GetObject().get()) != 0)
        std::cout << "\033[0;42m" << " " << "\033[0m";
      else if (dynamic_cast<Obstacle*>(world_[i][j].GetObject().get()) != 0)
        std::cout << "\033[0;44m" << " " << "\033[0m";
      }
      else
        std::cout << "\033[0;49m" << " " << "\033[0m";
        //std::cout << "\u25A0";
      if (j == n_columns_ - 1) {
        std::cout << "\033[0;47m" << " " << "\033[0m";
        std::cout << "\n";
      }
    }
  }
  for (unsigned i = 0; i < (n_columns_ + 2); i++) {
    std::cout << "\033[0;47m" << " " << "\033[0m";
  }
  std::cout << "\n";
}

