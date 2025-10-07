#ifndef FLASCHEN_H
#define FLASCHEN_H

#include <string>

class Flasche {
public:
    Flasche();
    Flasche(double volumen, std::string material);
    ~Flasche();

    double getVolumen() const;
    std::string getMaterial() const;

    void setVolumen(double volumen);
    void setMaterial(std::string material);

    void printBottle() const;
    
    void adoptFlasche(const Flasche& Flasche2);

private:
    double _dVolumen;
    std::string _sMaterial;
};

#endif // FLASCHEN_H