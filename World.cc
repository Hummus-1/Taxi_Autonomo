#include "World.h"

std::ostream& World::operator<<(std::ostream& os) {
  for (unsigned i = 0; i < n_rows_; i++) {
    for (unsigned j = 0; j < n_columns_; j++) {
      if (coche)
        os << "\033[0;35m" << "\025a9" << "\033[0m";
      else if (obstaculo)
        os << "\033[0;36m" << "\025a9" << "\033[0m";
      else
        os << "\025a9";
    }
  }
  return os;
}

