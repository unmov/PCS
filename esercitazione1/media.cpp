#include <iostream>
#include <fstream>
#include <string>

int main(int argc, const char *argv[]) {
    if (argc != 2) {
        std::cerr << "Errore: specificare il nome del file.\n";
        return 1;
	}
	
	std::string input_es1 = argv[1];
	std::ifstream ifs(input_es1);
	if (!ifs.is_open()) {
		std::cerr << "Errore nell'apertura del file.\n";
        return 1;
    }
	
	std::string città;
	double t0, t1, t2, t3;
	while(!ifs.eof()) {
		ifs >> città >> t0 >> t1 >> t2 >> t3; 
		double media = (t0+t1+t2+t3)/4.0;
		std::cout << città << " " << media << "\n";
	}
	return 0;
}


	