#include "Flaschen.h"
#include <iostream>
#include <string>

Flasche::Flasche() : _dVolumen(0.0), _sMaterial("") {}

Flasche::Flasche(double dVolumen, std::string sMaterial): _dVolumen(dVolumen), _sMaterial(sMaterial) {}

Flasche::~Flasche() {}

double Flasche::getVolumen() const {
    return _dVolumen;
}

void Flasche::setVolumen(double volumen) {
    _dVolumen = volumen;
}

std::string Flasche::getMaterial() const {
    return _sMaterial;
}

void Flasche::setMaterial(std::string material) {
    _sMaterial = material;
}

void Flasche::printBottle() const {
    std::cout << "Flasche volumen: " << _dVolumen << "L, Material: " << _sMaterial << std::endl;
}

void Flasche::adoptFlasche(const Flasche& Flasche2) {
    this->_dVolumen = Flasche2._dVolumen;
    this->_sMaterial = Flasche2._sMaterial;
}