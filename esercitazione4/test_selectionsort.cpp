#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <random>
#include "randfiller.h"
#include "sorts.hpp"

int main(void)
{
    randfiller rf;
    
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist_dim(1, 1000);
    
    for (int i = 0; i < 100; i++) {
        int dim = dist_dim(gen);
        std::vector<int> vi(dim);
        rf.fill(vi, -1000, 1000); 

        selection_sort(vi);

        if (!is_sorted(vi)) {
            return EXIT_FAILURE;
        }
    }

    std::vector<std::string> vs = {
        "gianluca", "mela", "macchina", "australopiteco", "supercalifragilistichespiralidoso", 
        "trattore", "azzurro", "lampada", "cavallo", "mesopotamia"
    };

    selection_sort(vs);

    if (!is_sorted(vs)) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}