#pragma once
#include <vector>
#include <utility> 
#include <algorithm>

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

//MERGESORT
template <typename T>
void merge(std::vector<T>& A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<T> L(n1);
    std::vector<T> R(n2);

    for (int i = 0; i < n1; ++i) L[i] = A[p + i];
    for (int j = 0; j < n2; ++j) R[j] = A[q + 1 + j];

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void merge_sort(std::vector<T>& A, int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

//QUICKSORT
template <typename T>
int partition(std::vector<T>& A, int p, int r) {
    T x = A[r];
    int i = p - 1;
    for (int j = p; j < r; ++j) {
        if (A[j] <= x) {
            i++;
            std::swap(A[i], A[j]);
        }
    }
    std::swap(A[i + 1], A[r]);
    return i + 1;
}

template <typename T>
void quick_sort(std::vector<T>& A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}

//MODIFIED QUICKSORT
template <typename T>
void insertion_sort_subarray(std::vector<T>& v, int p, int r) {
    for (int i = p + 1; i <= r; ++i) {
        T key = v[i];
        int j = i - 1;
        while (j >= p && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}


template <typename T>
void modified_quicksort(std::vector<T>& A, int p, int r) {
    if (p < r) {
        if (r - p + 1 <= 200) {
            insertion_sort_subarray(A, p, r);
        } else {
            int q = partition(A, p, r);
            modified_quicksort(A, p, q - 1);
            modified_quicksort(A, q + 1, r);
        }
    }
}
