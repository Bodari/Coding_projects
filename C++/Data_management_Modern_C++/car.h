#ifndef CAR_H
#define CAR_H

#include "fueltype.h"
#include <functional>

class CarCountListener{
public:
    virtual void carCountChanged(int aNewCarCount) = 0;
};

class Car
{
public:
    Car(); // Oletusrakentaja ei luo osoitetta, vaan osoite on nullptr
    Car(const string& aManufacturer, const string& aModel, int aYear);
    Car(const string& aManufacturer, const string& aModel, int aYear, const FuelType& aFueltype); // luodaan osoite new:lla
    Car(const Car& aCar);
    virtual ~Car();

    void setManufacturer(const string& aManufacturer);
    string getManufacturer() const;

    void setModel(const string& aModel);
    string getModel() const;

    void setYear(int aYear);
    int getYear() const;

    void setFuelType(const FuelType& aFueltype);
    FuelType getFuelType() const;

    void setFuelTypePtr(FuelType* aFueltype);
    FuelType* getFuelTypePtr() const;

    virtual void printInformation() const;

    static int getCarCount();

    void addCarCountListener(CarCountListener* aNewListener);

private:
    string manufacturer, model, search = "";
    int year = 0;

    FuelType* fueltype = nullptr;
    static int carCounter;

    CarCountListener* listener = nullptr;
};

class Observer : public CarCountListener{
public:
    Observer();
    ~Observer();

    virtual void carCountChanged(int aNewCarCount);
};

#endif // CAR_H
