#include "electriccar.h"
#include "car.h"

#include <memory>
#include <vector>
#include <algorithm>

// Functions & Classes
int instructionsAndChoice();
auto printNumberOfCars = [](){cout << "There are a total of " << Car::getCarCount() << " cars which " << ElectricCar::getElectricCarCount() << " are electric cars." << endl;};
string sortByWhat();

template<typename V>
void displayCars(V& vector){
    int number = 0;
    for(unique_ptr<Car>& c : vector){
        number++;
        cout << "Car number: " << number << endl;
        c->printInformation();
    }
}

/*
void addCar(vector & v){
    cout << "How many cars(Non electrical) do you want to add? ";
    cin >> carAmount;
    cin.ignore();
    for (int i = 0; i < carAmount; ++i){
        cout << "Car manufacturer: ";
        getline(cin, manufacturer);

        cout << "Car model: ";
        getline(cin, model);

        cout << "Year of manufacture: ";
        cin >> year;
        cin.ignore();

        cout << "Fuel type: ";
        getline(cin, fueltype);

        cars.push_back(unique_ptr<Car>(new Car(manufacturer,model,year,gasoline)));
    }
}

void addElectricCar(){

}
*/
// Variables
int Car::carCounter = 0;
int ElectricCar::electricCarCounter = 0;

int main()
{
    FuelType diesel("Diesel");
    FuelType gasoline("Gasoline");
    vector<unique_ptr<Car>> cars;

    cars.push_back(unique_ptr<Car>(new Car("Audi","TT",1999,gasoline)));
    cars.push_back(unique_ptr<Car>(new Car("Peugeot","407",2003,gasoline)));
    // cars.push_back(make_unique<Car>("Peugeot","407",2003,gasoline));
    cars.push_back(unique_ptr<Car>(new Car("Mercedes","Model E",2015,diesel)));
    cars.push_back(unique_ptr<Car>(new Car("Ferrari","Spider",2019,gasoline)));
    cars.push_back(unique_ptr<ElectricCar>(new ElectricCar("Tesla","Model S",2018,313)));
    cars.push_back(unique_ptr<ElectricCar>(new ElectricCar("Tesla","Cybertruck",2022,250)));

    int choice, carAmount, electricCarAmount = 0;

    do
    {
        choice = instructionsAndChoice();
        cin.ignore();

        switch(choice){
        case 1:
        {
            displayCars(cars);
            break;
        }
        case 2:
        {
            string sortType = sortByWhat();

            if (sortType == "ma"){
                auto comparatorManifacturer = [](unique_ptr<Car>& a, unique_ptr<Car>& b) { return a->getManufacturer() < b->getManufacturer(); };
                sort(cars.begin(), cars.end(), comparatorManifacturer);
                cout << "Cars sorted by manufacturer." << endl;
            }

            else if (sortType == "mo"){
                auto comparatorModel = [](unique_ptr<Car>& a, unique_ptr<Car>& b) { return a->getModel() < b->getModel(); };
                sort(cars.begin(), cars.end(), comparatorModel);
                cout << "Cars sorted by model type." << endl;
            }

            else if (sortType == "ye"){
                auto comparatorYear = [](unique_ptr<Car>& a, unique_ptr<Car>& b) { return a->getYear() < b->getYear(); };
                sort(cars.begin(), cars.end(), comparatorYear);
                cout << "Cars sorted by year of manufacture." << endl;
            }

            else if(sortType == "ft"){
                auto comparatorFuelType = [](unique_ptr<Car>& a, unique_ptr<Car>& b) { return a->getFuelTypePtr() < b->getFuelTypePtr(); };
                sort(cars.begin(), cars.end(), comparatorFuelType);
                cout << "Cars sorted by fuel type." << endl;
            }

            else{
                cout << "Feed " << sortType << " not recognized." << endl;
            }
        }
            break;

        case 3:
            printNumberOfCars();
            break;

        case 4:
        {
            string manufacturer, model, fueltype= "";
            int year, range = 0;
            cout << "How many cars(Non electrical) do you want to add? ";
            cin >> carAmount;
            cin.ignore();
            for (int i = 0; i < carAmount; ++i){              
                cout << "Car manufacturer: ";
                getline(cin, manufacturer);

                cout << "Car model: ";
                getline(cin, model);

                cout << "Year of manufacture: ";
                cin >> year;
                cin.ignore();

                cout << "Fuel type: ";
                getline(cin, fueltype);

                cars.push_back(unique_ptr<Car>(new Car(manufacturer,model,year,gasoline)));
            }

            cout << "How many electrical car do you want to add? ";
            cin >> electricCarAmount;
            cin.ignore();
            for (int i = 0; i < electricCarAmount; ++i){           
                cout << "Car manufacturer: ";
                getline(cin, manufacturer);

                cout << "Car model: ";
                getline(cin, model);

                cout << "Year of manufacture: ";
                cin >> year;
                cin.ignore();

                cout << "Range: ";
                cin >> range;

                cars.push_back(unique_ptr<ElectricCar>(new ElectricCar(manufacturer,model,year,range)));
            }
        }
            break;

        case 5:
        {
            string manufacturer, model, fueltype= "";
            int year, carNumber = 0;
            cout << "Enter a car number to edit it: " << endl;
            cin >> carNumber;
            cin.ignore();
            carNumber--;

            cout << "Car manufacturer: ";
            getline(cin, manufacturer);

            cars[carNumber]->setManufacturer(manufacturer);

            cout << "Car model: ";
            getline(cin, model);

            cars[carNumber]->setModel(model);

            cout << "Year of manufacture: ";
            cin >> year;
            cin.ignore();

            cars[carNumber]->setYear(year);

            cout << "Fuel type: ";
            getline(cin, fueltype);

            cars[carNumber]->setFuelType(fueltype);

        }
            break;

        case 6:
        {
            int carNumber;
            cout << "Enter a car number to delete it: ";
            cin >> carNumber;
            carNumber--;
            cars.erase(cars.begin()+carNumber);
        }
            break;

        case 7:
        {
            string search = "";
            cout << "Search (name must match perfectly): ";
            getline(cin, search);

            /*
            for(unique_ptr<Car>& c : cars){
                if(c->getModel() == search){
                    c->printInformation();
                }
            }

            auto searchByModel = [&] (const auto& c){
                if(c->getModel() == search){
                    c->printInformation();
                }
            };

            for_each(cars.begin(), cars.end(), searchByModel);


            for (const auto& entry : s)
                    std::cout << "Match(\"" << entry << "\") = " << (std::find_if(v.begin(), v.end(), [entry](const std::string& in){return in.find(entry)!= std::string::npos;}) != v.end()) << std::endl;
            }
            */
            for_each(cars.begin(), cars.end(), [&](unique_ptr<Car>& c){
                if(c->getModel() == search){
                    cout << "Search result: " << endl;
                    c->printInformation();
                }
            }
            );

        }
            break;
        case 8:
            cout << "Program closed." << endl;
            break;

        default:
            cout << "Number not recognized. Choose between 1 - 8. " << endl;

        }

    }while(choice != 8);

    return 0;
}

int instructionsAndChoice(){
    int choice;
    cout << "\nPress 1 to display all information about cars. \n";
    cout << "Press 2 to sort data by of choice. \n";
    cout << "Press 3 to display number of cars. \n";
    cout << "Press 4 to add number of Cars. \n";
    cout << "Press 5 to edit a car. \n";
    cout << "Press 6 to delete car of your choice. \n";
    cout << "Press 7 to search by model. \n";
    cout << "Press 8 to exit. \n";
    cout << "Enter a number: ";
    cin >> choice;

    cout << endl;

    return choice;
}

string sortByWhat(){
    cout << "How do you want to sort, by manufacturer(ma), model(mo), year of manufacture(ye) or by fuel type(ft)?\n";
    cout << "Please enter a letters inside a bracket: ";
    string sortType = "";
    getline(cin,sortType);

    return sortType;
}

