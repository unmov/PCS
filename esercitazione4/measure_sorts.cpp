#include <iostream>
#include <vector>
#include <algorithm> 
#include "timecounter.h"
#include "randfiller.h"
#include "sorts.hpp"

int main(void)
{
    randfiller rf;
    timecounter tc;

    std::cout << "Dimensione\tBubble\t\tInsertion\tSelection\tstd::sort\n";

    for (int size = 4; size <= 8192; size *= 2) {
        
        std::vector<int> v_orig(size);
        rf.fill(v_orig, -10000, 10000);

        std::vector<int> v = v_orig;
        tc.tic();
        bubble_sort(v);
        double t_bubble = tc.toc();

        v = v_orig;
        tc.tic();
        insertion_sort(v);
        double t_insertion = tc.toc();

        v = v_orig;
        tc.tic();
        selection_sort(v);
        double t_selection = tc.toc();

        v = v_orig;
        tc.tic();
        std::sort(v.begin(), v.end());
        double t_std = tc.toc();

        std::cout << size << "\t\t" 
                  << std::fixed << std::setprecision(6) << t_bubble << "\t"
                  << t_insertion << "\t"
                  << t_selection << "\t"
                  << t_std << "\n";
    }

    return EXIT_SUCCESS;
}