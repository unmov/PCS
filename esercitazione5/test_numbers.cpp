#include <iostream>
#include <vector>
#include <random>
#include "sorts2.hpp"
#include "randfiller.h"

int main() {
    randfiller rf;
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist_size(10, 1000);

    for (int i = 0; i < 100; ++i) {
        int size = dist_size(gen);
        std::vector<int> v_merge(size);
        
        rf.fill(v_merge, -1000, 1000);
        
        std::vector<int> v_quick = v_merge;

        merge_sort(v_merge, 0, v_merge.size() - 1);
        if (!is_sorted(v_merge)) return EXIT_FAILURE;
        

        quick_sort(v_quick, 0, v_quick.size() - 1);
        if (!is_sorted(v_quick)) return EXIT_FAILURE;
	}
    
    return EXIT_SUCCESS;
}