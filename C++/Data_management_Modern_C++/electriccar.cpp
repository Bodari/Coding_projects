#include "electriccar.h"

ElectricCar::ElectricCar(const string& aManufacturer, const string& aModel, int aYear, int aRange)
    : Car (aManufacturer, aModel, aYear), range (aRange){
    cout << "ElectircCar -luokan rakentaja" << endl;
    electricCarCounter++;
}

ElectricCar::~ElectricCar(){
    cout << "ElectircCar -luokan purkaja" << endl;
    electricCarCounter--;
}

void ElectricCar::setRange(int aRange){
    range = aRange;
}

int ElectricCar::getRange(){
    return range;
}

void ElectricCar::printInformation() const{
    Car::printInformation();
    cout << "Electric car range:   " << range << " km" << endl << endl;
}

int ElectricCar::getElectricCarCount(){
    return electricCarCounter;
}

