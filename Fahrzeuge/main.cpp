#include "Fahrzeuge.h"
#include <iostream>
#include <stdexcept>

void printVehicleInfo(const Vehicle& v) {
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Fahrzeug ID:   " << v.getID() << std::endl;
    std::cout << "Farbe (Enum):  " << v.getColorEnum() << std::endl;
    std::cout << "Farbe (String):" << v.getColorString() << std::endl;
    std::cout << "Preis:         " << v.getPrice() << " EUR" << std::endl;
    std::cout << "Baujahr:       " << v.getYear() << std::endl;
    
    // Testen der statischen Methode
    std::string status = Vehicle::isOldtimer(v) ? "JA" : "NEIN";
    std::cout << "Ist Oldtimer?  " << status << std::endl;
}


int main() {
    try {
        Vehicle car1(Vehicle::RED, 25500.0, 2018);
        printVehicleInfo(car1);

        Vehicle car2(Vehicle::BLACK, 85000.0, 1975);
        printVehicleInfo(car2);

        Vehicle car3(Vehicle::BLUE, 1200.0, 1999);
        printVehicleInfo(car3);

        // Demonstrieren der ID-Generierung
        std::cout << "\nID-Sequenz: " 
                  << car1.getID() << ", " 
                  << car2.getID() << ", " 
                  << car3.getID() << std::endl;


    } catch (const std::invalid_argument& e) {
        std::cerr << "Fehler bei der Initialisierung: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}