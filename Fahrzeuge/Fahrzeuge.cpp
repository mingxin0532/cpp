#include "Fahrzeuge.h"
#include <sstream>
#include <stdexcept>

int Vehicle::_nextID = 1000;

std::string Vehicle::colorToString(Color c) const {
    switch (c) {
        case BLUE: return "Blue";
        case RED: return "Red";
        case GREEN: return "Green";
        case WHITE: return "White";
        case BLACK: return "Black";
        default: return "unknown";
    }
}

Vehicle::Vehicle(Color color, double price, int year)
    : _color(color),
      _price(price),
      _year(year),
      _id(_nextID++){}

Vehicle::Color Vehicle::getColorEnum() const {
    return _color;
}

std::string Vehicle::getColorString() const {
    return colorToString(_color);
}

double Vehicle::getPrice() const {
    return _price;
}

int Vehicle::getYear() const {
    return _year;
}

int Vehicle::getID() const {
    return _id;
}

bool Vehicle::isOldtimer(const Vehicle& vehicle) {
    return vehicle.getYear() < 1980;
}