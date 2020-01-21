#ifndef ELECTRICCAR_H
#define ELECTRICCAR_H

#include "car.h"

class ElectricCar : public Car
{
public:
    ElectricCar(const string& aManufacturer, const string& aModel, int aYear, int aRange);
    ~ElectricCar();

    void setRange(int aRange);
    int getRange();
    void printInformation() const;
    static int getElectricCarCount();

private:
    int range;
    static int electricCarCounter;
};

#endif // ELECTRICCAR_H
