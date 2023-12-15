#include <iostream>
using namespace std;

class Vehicle
{
public:
    virtual string getType() = 0;
};

class Car : public Vehicle
{
public:
    string getType() override
    {
        return "Car";
    }
};

class Bike : public Vehicle
{
public:
    string getType() override
    {
        return "Bike";
    }
};

class Truck : public Vehicle
{
public:
    string getType() override
    {
        return "Truck";
    }
};

class VehicleFactory
{
public:
    virtual Vehicle *createVehicle() = 0;
};

class CarFactory : public VehicleFactory
{
public:
    Vehicle *createVehicle() override
    {
        return new Car();
    }
};

class BikeFactory : public VehicleFactory
{
public:
    Vehicle *createVehicle() override
    {
        return new Bike();
    }
};

class TruckFactory : public VehicleFactory
{
public:
    Vehicle *createVehicle() override
    {
        return new Truck();
    }
};

int main()
{

    VehicleFactory *carFactory = new CarFactory();
    VehicleFactory *truckFactory = new TruckFactory();
    VehicleFactory *bikeFactory = new BikeFactory();

    Vehicle *myCar = carFactory->createVehicle();
    Vehicle *myTruck = truckFactory->createVehicle();
    Vehicle *myBike = bikeFactory->createVehicle();

    cout << myCar->getType() << endl;   // "Car"
    cout << myTruck->getType() << endl; // "Truck"
    cout << myBike->getType() << endl;  // "Bike"

    return 0;
}