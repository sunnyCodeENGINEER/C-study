#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class Vehicle {
    public:
        string make;
        string model;
        string ownerLastName;
        string ownerFirstName;
        string registrationNumber;
        string registrationType;
        string vehicleType;
        time_t registrationExpiry;

        Vehicle(string make, string model, string ownerLastName, string ownerFirstName, string registrationNumber, string registrationType, string vehicleType, time_t registrationExpiry) {
            this->make = make;
            this->model = model;
            this->ownerLastName = ownerLastName;
            this->ownerFirstName = ownerFirstName;
            this->registrationNumber = registrationNumber;
            this->registrationType = registrationType;
            this->vehicleType = vehicleType;
            this->registrationExpiry = registrationExpiry;
        }
};

class Driver {
    public:
        string lastName;
        string firstName;
        string licenseNumber;
        time_t licenseExpiry;

        Driver(string lastName, string firstName, string licenseNumber, time_t licenseExpiry) {
            this->lastName = lastName;
            this->firstName = firstName;
            this->licenseNumber = licenseNumber;
            this->licenseExpiry = licenseExpiry;
        }
};

class DVLAOffice {
    public:
        vector<Vehicle> vehicles;
        vector<Driver> drivers;
};

int main() {

    return 0;
}
