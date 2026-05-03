#include <iostream>
#include <vector>
#include <string>
#include "sorts2.hpp"

int main() {
    std::vector<std::string> base_strings = {
        "giovanni", "zucchina", "acciuga", "albero", "ferrarelle", 
        "napoli", "fenicottero", "pappardelle", "galfer", "pizzeria"
    };

    std::vector<std::string> v_merge = base_strings;
    std::vector<std::string> v_quick = base_strings;

    merge_sort(v_merge, 0, v_merge.size() - 1);
    if (!is_sorted(v_merge)) return EXIT_FAILURE;

    quick_sort(v_quick, 0, v_quick.size() - 1);
    if (!is_sorted(v_quick)) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}