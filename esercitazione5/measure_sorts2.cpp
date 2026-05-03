#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "sorts2.hpp"
#include "randfiller.h"
#include "timecounter.h"

int main() {
    randfiller rf;
    timecounter tc;
    
    std::vector<int> sizes = {4, 8, 16, 32, 64, 128, 256, 512}; //Ho scelto di includere vettori di dimensione ben superiore a 100 perchè il mio PC mostrava performance migliori per l'Insertion rispetto al Quick fino a 128, per cui non avrebbe neanche avuto senso creare un algoritmo modificato
    int num_vectors = 100;

    std::cout << std::left << std::setw(10) << "Size" 
              << std::setw(12) << "Bubble" 
              << std::setw(12) << "Insert" 
              << std::setw(12) << "Select" 
              << std::setw(12) << "Merge" 
              << std::setw(12) << "Quick" 
              << std::setw(12) << "Modified"
              << std::setw(12) << "std::sort" << "\n";
			  std::cout << "\n";

    for (int size : sizes) {
        std::vector<std::vector<int>> base_vectors(num_vectors, std::vector<int>(size));
        for (int i = 0; i < num_vectors; ++i) {
            rf.fill(base_vectors[i], -1000, 1000);
        }

        std::vector<std::vector<int>> work;
//Bubble
        work = base_vectors;
        tc.tic();
        for(int i = 0; i < num_vectors; i++) bubble_sort(work[i]);
        double t_bubble = tc.toc() / num_vectors;
//Insertion
        work = base_vectors;
        tc.tic();
        for(int i = 0; i < num_vectors; i++) insertion_sort(work[i]);
        double t_insert = tc.toc() / num_vectors;

// Selection Sort
        work = base_vectors;
        tc.tic();
        for(int i = 0; i < num_vectors; i++) selection_sort(work[i]);
        double t_select = tc.toc() / num_vectors;



// Merge Sort
        work = base_vectors;
        tc.tic();
        for(int i = 0; i < num_vectors; i++) merge_sort(work[i], 0, size - 1);
        double t_merge = tc.toc() / num_vectors;

// Quick Sort
        work = base_vectors;
        tc.tic();
        for(int i = 0; i < num_vectors; i++) quick_sort(work[i], 0, size - 1);
        double t_quick = tc.toc() / num_vectors;
        
// Modified Quick Sort
        work = base_vectors;
        tc.tic();
        for(int i = 0; i < num_vectors; i++) modified_quicksort(work[i], 0, size - 1);
        double t_modified = tc.toc() / num_vectors;

// std::sort
        work = base_vectors;
        tc.tic();
        for(int i = 0; i < num_vectors; i++) std::sort(work[i].begin(), work[i].end());
        double t_std = tc.toc() / num_vectors;

       std::cout << std::left << std::setw(10) << size 
                  << std::fixed << std::setprecision(8)
                  << std::setw(12) << t_bubble 
                  << std::setw(12) << t_insert 
                  << std::setw(12) << t_select 
                  << std::setw(12) << t_merge 
                  << std::setw(12) << t_quick 
                  << std::setw(12) << t_modified
                  << std::setw(12) << t_std << "\n";
    }

    return 0;
}