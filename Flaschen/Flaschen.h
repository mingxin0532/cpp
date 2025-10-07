#include <string>

class flaschen
{
private:
	double dVolumen;
	std::string sMaterial;

public:
	flaschen();
	~flaschen();
	double getdVolumen();
	bool setdVolumen(double volumen);
	std::string getsMaterial();
	bool setsMaterial(std::string Material);

	void printFlasche(flaschen thisflasche);
	void adoptFlasche(flaschen& anotherFlasche);

};

