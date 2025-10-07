#include "Date.h"
#include <iostream>

std::string getComparisonResult(int result) {
    if (result == 1) return "VOR dem Vergleichsdatum.";
    if (result == 0) return "GLEICH dem Vergleichsdatum.";
    if (result == -1) return "NACH dem Vergleichsdatum.";
    return "FEHLER";
}

int main() {
    srand(static_cast<unsigned int>(time(NULL))); 

    Date dateA(15, 6, 2024);
    Date dateB(15, 6, 2024); 
    Date dateC(1, 1, 2000); 

    std::cout << "--- Feste Daten ---" << std::endl;
    std::cout << "Datum A: " << dateA.toString() << std::endl;
    std::cout << "Datum B: " << dateB.toString() << std::endl;
    std::cout << "Datum C: " << dateC.toString() << std::endl;
    
    std::cout << "\n--- Vergleich A mit B ---" << std::endl;
    int resAB = dateA.compare(dateB);
    std::cout << "A (" << dateA.toString() << ") ist " 
              << getComparisonResult(resAB) << std::endl;

    std::cout << "\n--- Vergleich A mit C ---" << std::endl;
    int resAC = dateA.compare(dateC);
    std::cout << "A (" << dateA.toString() << ") ist " 
              << getComparisonResult(resAC) << std::endl; 

    std::cout << "\n--- Vergleich C mit A ---" << std::endl;
    int resCA = dateC.compare(dateA);
    std::cout << "C (" << dateC.toString() << ") ist " 
              << getComparisonResult(resCA) << std::endl; 

    std::cout << "\n--- Zufällige Daten ---" << std::endl;
    Date dateRandom1;
    Date dateRandom2;

    std::cout << "Zufallsdatum 1: " << dateRandom1.toString() << std::endl;
    std::cout << "Zufallsdatum 2: " << dateRandom2.toString() << std::endl;
    
    std::cout << "\n--- Vergleich Zufall 1 mit Zufall 2 ---" << std::endl;
    int resR1R2 = dateRandom1.compare(dateRandom2);
    std::cout << "R1 ist " << getComparisonResult(resR1R2) << std::endl;

    return 0;
}