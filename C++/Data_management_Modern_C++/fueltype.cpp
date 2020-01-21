#include "fueltype.h"

FuelType::FuelType() : fuel(""){
    cout << "FuelType -luokan rakentaja" << endl;
}

FuelType::FuelType(const string &aFuel) : fuel(aFuel){
    cout << "FuelType -luokan parametrinen rakentaja" << endl;
}

FuelType::~FuelType(){
    cout << "FuelType -luokan purkaja" << endl;
}

void FuelType::setFuelType(const string& aFuel){
    fuel = aFuel;
}

string FuelType::getFuelType() const {
    return fuel;
}
