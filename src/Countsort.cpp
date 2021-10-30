#include "Countsort.h"

void CountSort(std::vector<State*>& sequence) {
    State* max;
    State* min;
    for(int i = 0; i < sequence.size(); i++) {
        if(sequence[i]->GetFn() > max->GetFn()){
                max = sequence[i];
        }
        if(sequence[i]->GetFn() < min->GetFn()){
            min = sequence[i];
        }
    }
    int range = max->GetFn() - min->GetFn() + 1;
    vector<int> count(range), output(arr.size());

    for (int i = 0; i < arr.size(); i++)
        count[arr[i].GetFn() - min->GetFn()]++;
 
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];
 
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i].GetFn() - min->GetFn()] - 1] = sequence[i];
        count[sequence[i]->GetFn() - min->GetFn()]--;
    }
 
    for (int i = 0; i < arr.size(); i++)
        sequence[i] = output[i];
}