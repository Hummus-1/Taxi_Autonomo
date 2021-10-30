#include "Mergesort.h"

void Merge(std::vector<State*>& sequence, int ini, int centre, int end) {
  std::vector<State*> aux = sequence;
  unsigned i = ini ; unsigned j = centre + 1 ; unsigned k = ini;
  while ((i <= centre) && (j <= end)) {
    if ((sequence[i]->GetFn() < sequence[j]->GetFn()) || ((sequence[i]->GetFn() == sequence[j]->GetFn()) && sequence[i]->GetGn() > sequence[j]->GetGn())) {
      aux[k] = sequence[i];
      i++;
    }
    else {
      aux[k] = sequence[j];
      j++;
    }
    k++;
  }
  if (i > centre) {
    while (j <= end) {
      aux[k] = sequence[j];
      j++ ; k++;
    }
  }
  else {
    while (i <= centre) {
      aux[k] = sequence[i];
      i++ ; k++;
    }
  }
  for (int k = ini; k <= end; k++)
    sequence[k] = aux[k];
}

void Msort(std::vector<State*>& sequence, int ini, int end) {
  if (ini < end) {
    int centre = (ini + end) / 2;
    Msort(sequence, ini, centre);
    Msort(sequence, centre + 1, end);
    Merge(sequence, ini, centre, end);
  }
}

void Mergesort(std::vector<State*>& sequence) {
  Msort(sequence, 0, sequence.size() - 1);
}

bool compare(const State* state_1, const State* state_2) {
  return (state_1->GetFn() > state_2->GetFn()) || (((state_1->GetFn() == state_2->GetFn()) && state_1->GetGn() > state_2->GetGn()));
}