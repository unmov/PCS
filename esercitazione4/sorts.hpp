#pragma once

#include <vector>
#include <utility> 

template<typename T>
bool is_sorted(const std::vector<T>& vec)
{
    if (vec.size() <= 1) {
        return true;
    }

    for (size_t i = 1; i < vec.size(); i++) {
        if (vec[i] < vec[i - 1]) {
            return false;
        }
    }
    return true;
}
//Bubble Sort
template<typename T>
void bubble_sort(std::vector<T>& A)
{
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (A[j] < A[j - 1]) {
                std::swap(A[j], A[j - 1]);
            }
        }
    }
}
//Insertion Sort
template<typename T>
void insertion_sort(std::vector<T>& A)
{
    int n = A.size();
    for (int j = 1; j < n; j++) {
        T key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}
//Selection Sort
template<typename T>
void selection_sort(std::vector<T>& A)
{
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        std::swap(A[i], A[min]);
    }
}