#include <iostream>
#include <cmath>     
#include <algorithm> 

int main() {

    static const int N = 10;
    double arr[N] = {1.2, 3.5, 5.2, 7.9, 9.0, 2.2, 4.7, 8.5, 5.7, 0.9};
    double minimo = arr[0];
    double massimo = arr[0];
    double somma = 0;

    for (int i = 0; i < N; ++i) {
        minimo = std::min(minimo, arr[i]);
        massimo = std::max(massimo, arr[i]);
        somma += arr[i];
    }

    double media = somma / N;

    double somma_quadrati_diff = 0;
    for (int i = 0; i < N; ++i) {
        somma_quadrati_diff += std::pow(arr[i] - media, 2);
    }
    double deviazione_standard = std::sqrt(somma_quadrati_diff / N);

    std::cout << "Minimo:             " << minimo << "\n";
    std::cout << "Massimo:            " << massimo << "\n";
    std::cout << "Media:              " << media << "\n";
    std::cout << "Deviazione Standard: " << deviazione_standard << "\n";

    return 0;
}

