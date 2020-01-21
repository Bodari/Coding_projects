#include "car.h"

Car::Car() : manufacturer(""), model (""), year(0){
    cout << "Car -luokan rakentaja" << endl;
    carCounter++;
}

Car::Car(const string& aManufacturer, const string& aModel, int aYear) : manufacturer(aManufacturer), model(aModel), year(aYear){
    cout << "Car -luokan 3 parametrinen rakentaja. (Sahkoauto)" << endl;
    carCounter++;
}

Car::Car(const string & aManufacturer, const string& aModel, int aYear, const FuelType & aFueltype) : manufacturer(aManufacturer), model(aModel), year(aYear), fueltype(new FuelType(aFueltype)){
    cout << "Car -luokan 4 parametrinen rakentaja" << endl;
    carCounter++;
}

Car::Car(const Car& aCar) : manufacturer(aCar.manufacturer), model(aCar.model), year(aCar.year), fueltype(new FuelType(*(aCar.fueltype))){
    cout << "Car -luokan kopiorakentaja" << endl;
    carCounter++;
}

Car::~Car(){
    // Vapautetaan olion varaama dynaaminen muisti ja muut resurssit
    cout << "Car -luokan purkaja" << endl;
    delete fueltype;
    carCounter--;
}

void Car::setManufacturer(const string& aManufacturer){
    manufacturer = aManufacturer;
}

string Car::getManufacturer() const{
    return manufacturer;
}

void Car::setModel(const string& aModel){
    model = aModel;
}

string Car::getModel() const{
    return model;
}

void Car::setYear(int aYear){
    year = aYear;
}

int Car::getYear() const{
    return year;
}

void Car::setFuelType(const FuelType & aFueltype){
    if (fueltype) {
        *fueltype = aFueltype;
    }
    else {
        fueltype = new FuelType(aFueltype);
    }
}

FuelType Car::getFuelType() const{
    return FuelType(*fueltype);
}

void Car::setFuelTypePtr(FuelType* aFueltype){
    delete fueltype;
    fueltype = aFueltype;
}

FuelType* Car::getFuelTypePtr() const{
    return fueltype;
}

void Car::printInformation() const{
    cout << "Car memory address:   " << this << endl;
    cout << "Manufacturer:         " << manufacturer << endl;
    cout << "Model:                " << model << endl;
    cout << "Year of manufacture:  " << year << endl;
    if (fueltype) {
        cout << "Fuel type:            " << fueltype->getFuelType() << endl;
        cout << endl;
    }
}

int Car::getCarCount(){
    return carCounter;
}

void Car::addCarCountListener(CarCountListener *aNewListener){
    listener = aNewListener;
}

Observer::Observer(){
    cout << "Observer -luokan rakentaja" << endl;
}

Observer::~Observer(){
    cout << "Observer -luokan purkaja" << endl;
}

void Observer::carCountChanged(int aNewCarCount){
    cout << "The number of cars has changed, the new number: " << aNewCarCount << endl;
}

