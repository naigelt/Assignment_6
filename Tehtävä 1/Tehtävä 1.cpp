#include <iostream>

class Vehicle {
protected:
    int topSpeed;
    int yearOfManufacture;
    double weight;

public:
    Vehicle(int topSpeed, int yearOfManufacture, double weight)
        : topSpeed(topSpeed), yearOfManufacture(yearOfManufacture), weight(weight) {}
};

class Car : public Vehicle {
protected:
    int doors;
    int wheels;

public:
    Car(int topSpeed, int yearOfManufacture, double weight, int doors, int wheels)
        : Vehicle(topSpeed, yearOfManufacture, weight), doors(doors), wheels(wheels) {}
};

class PassengerCar : public Car {
    int maxPassengers;

public:
    PassengerCar(int topSpeed, int yearOfManufacture, double weight, int doors, int wheels, int maxPassengers)
        : Car(topSpeed, yearOfManufacture, weight, doors, wheels), maxPassengers(maxPassengers) {}
};

class Truck : public Car {
    double maxLoad;

public:
    Truck(int topSpeed, int yearOfManufacture, double weight, int doors, int wheels, double maxLoad)
        : Car(topSpeed, yearOfManufacture, weight, doors, wheels), maxLoad(maxLoad) {}
};

class Airplane : public Vehicle {
    int maxAltitude;

public:
    Airplane(int topSpeed, int yearOfManufacture, double weight, int maxAltitude)
        : Vehicle(topSpeed, yearOfManufacture, weight), maxAltitude(maxAltitude) {}
};

class Ship : public Vehicle {
    double maxDraft;

public:
    Ship(int topSpeed, int yearOfManufacture, double weight, double maxDraft)
        : Vehicle(topSpeed, yearOfManufacture, weight), maxDraft(maxDraft) {}
};

int main() {
    PassengerCar myCar(180, 2020, 1500, 4, 4, 5);
    Truck myTruck(120, 2018, 3500, 2, 6, 10000);
    Airplane myPlane(900, 2015, 80000, 35000);
    Ship myShip(30, 2010, 500000, 30);

 

    return 0;
}
