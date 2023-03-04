#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Vehicle {
    public:
        string make;
        string model;
        string registration_number;
        time_t registration_expiry_date;

        Vehicle(string make, string model, string registration_number, time_t registration_expiry_date) {
            this->make = make;
            this->model = model;
            this->registration_number = registration_number;
            this->registration_expiry_date = registration_expiry_date;
        }
};

class Driver {
    public:
        string name;
        string license_number;
        time_t license_expiry_date;

        Driver(string name, string license_number, time_t license_expiry_date) {
            this->name = name;
            this->license_number = license_number;
            this->license_expiry_date = license_expiry_date;
        }
};

class Officer {
    public:
        vector<Vehicle> vehicles;
        vector<Driver> drivers;

        void register_vehicle(string make, string model, string registration_number, time_t registration_expiry_date) {
            Vehicle vehicle(make, model, registration_number, registration_expiry_date);
            vehicles.push_back(vehicle);
            cout << "Vehicle registered successfully." << endl;
        }

        void issue_license(string name, string license_number, time_t license_expiry_date) {
            Driver driver(name, license_number, license_expiry_date);
            drivers.push_back(driver);
            cout << "License issued successfully." << endl;
        }

        void check_registration_expiry(string registration_number) {
            for (int i = 0; i < vehicles.size(); i++) {
                if (vehicles[i].registration_number == registration_number) {
                    time_t current_time = time(NULL);
                    if (vehicles[i].registration_expiry_date < current_time) {
                        cout << "Registration for vehicle " << registration_number << " has expired." << endl;
                    } else {
                        cout << "Registration for vehicle " << registration_number << " is valid." << endl;
                    }
                    return;
                }
            }
            cout << "Vehicle with registration number " << registration_number << " not found." << endl;
        }

        void check_license_expiry(string license_number) {
            for (int i = 0; i < drivers.size(); i++) {
                if (drivers[i].license_number == license_number) {
                    time_t current_time = time(NULL);
                    if (drivers[i].license_expiry_date < current_time) {
                        cout << "License " << license_number << " has expired." << endl;
                    } else {
                        cout << "License " << license_number << " is valid." << endl;
                    }
                    return;
                }
            }
            cout << "Driver with license number " << license_number << " not found." << endl;
        }

        void renew_registration(string registration_number, time_t new_expiry_date) {
            for (int i = 0; i < vehicles.size(); i++) {
                if (vehicles[i].registration_number == registration_number) {
                    vehicles[i].registration_expiry_date = new_expiry_date;
                    cout << "Registration for vehicle " << registration_number << " has been renewed." << endl;
                    return;
                }
            }
            cout << "Vehicle with registration number " << registration_number << " not found." << endl;
        }

        void renew_license(string license_number, time_t new_expiry_date) {
            for (int i = 0; i < drivers.size(); i++) {
                if (drivers[i].license_number == license_number) {
                    drivers[i].license_expiry_date = new_expiry_date;
                    cout << "License " << license_number << " has been renewed." << endl;
                    return;
                }
            }
        }

};

int main () {

    return 0;
}
