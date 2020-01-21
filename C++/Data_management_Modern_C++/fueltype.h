#ifndef FUELTYPE_H
#define FUELTYPE_H

#include <string>
#include <iostream>

using namespace std;

class FuelType{
public:
    FuelType();
    FuelType(const string& aFuel);
    ~FuelType();

    void setFuelType(const string& aFuel);
    string getFuelType() const;

private:
    string fuel;
};



#endif // FUELTYPE_H
