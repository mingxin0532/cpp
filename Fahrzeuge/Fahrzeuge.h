#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>

class Vehicle {
public:
    enum Color {
        BLUE, 
        RED, 
        GREEN, 
        WHITE, 
        BLACK
    };

    Vehicle(Color color, double price, int year);
    
    Color getColorEnum() const;
    std::string getColorString() const;
    double getPrice() const;
    int getYear() const;
    int getID() const;

    static bool isOldtimer(const Vehicle& vehicle);
    
private:
    Color _color;
    double _price;
    int _year;
    int _id;

    static int _nextID;

    std::string colorToString(Color c) const;
};

#endif // VEHICLE_H