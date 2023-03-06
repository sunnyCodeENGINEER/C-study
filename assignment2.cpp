#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

using namespace std;

class Vehicle {
    public:
        string make;
        string model;
        string registrationNumber;
        time_t registrationExpiryDate;

        Vehicle(string make, string model, string registrationNumber, time_t registrationExpiryDate) {
            this->make = make;
            this->model = model;
            this->registrationNumber = registrationNumber;
            this->registrationExpiryDate = registrationExpiryDate;
        }
};

class Driver {
    public:
        string lastName;
        string firstName;
        string licenseNumber;
        time_t licenseExpiryDate;

        Driver(string lastName, string firstName, string licenseNumber, time_t licenseExpiryDate) {
            this->lastName = lastName,
            this->firstName = firstName;
            this->licenseNumber = licenseNumber;
            this->licenseExpiryDate = licenseExpiryDate;
        }
};

class Officer {
    public:
        vector<Vehicle> vehicles;
        vector<Driver> drivers;

        void registerVehicle(string make, string model, string registrationNumber, time_t registrationExpiryDate) {
            Vehicle vehicle(make, model, registrationNumber, registrationExpiryDate);
            vehicles.push_back(vehicle);
            cout << "Vehicle registered successfully." << endl;
        }

        void issueLicense(string lastName, string firstName, string licenseNumber, time_t licenseExpiryDate) {
            Driver driver(lastName, firstName, licenseNumber, licenseExpiryDate);
            drivers.push_back(driver);
            cout << "License issued successfully to " << firstName << " " << lastName << ".\n\n";
        }

        void checkRegistrationExpiry(string registrationNumber) {
            for (int i = 0; i < vehicles.size(); i++) {
                if (vehicles[i].registrationNumber == registrationNumber) {
                    time_t currentTime = time(NULL);
                    if (vehicles[i].registrationExpiryDate < currentTime) {
                        cout << "Registration for vehicle " << registrationNumber << " has expired." << endl;
                    } else {
                        cout << "Registration for vehicle " << registrationNumber << " is valid." << endl;
                    }
                    return;
                }
            }
            cout << "Vehicle with registration number " << registrationNumber << " not found." << endl;
        }

        void checkLicenseExpiry(string licenseNumber) {
            for (int i = 0; i < drivers.size(); i++) {
                if (drivers[i].licenseNumber == licenseNumber) {
                    time_t currentTime = time(NULL);
                    if (drivers[i].licenseExpiryDate < currentTime) {
                        cout << "License " << licenseNumber << " has expired." << endl;
                    } else {
                        cout << "License " << licenseNumber << " is valid." << endl;
                    }
                    return;
                }
            }
            cout << "Driver with license number " << licenseNumber << " not found." << endl;
        }

        void renewRegistration(string registrationNumber, time_t newExpiryDate) {
            for (int i = 0; i < vehicles.size(); i++) {
                if (vehicles[i].registrationNumber == registrationNumber) {
                    vehicles[i].registrationExpiryDate = newExpiryDate;
                    cout << "Registration for vehicle " << registrationNumber << " has been renewed." << endl;
                    return;
                }
            }
            cout << "Vehicle with registration number " << registrationNumber << " not found." << endl;
        }

        void renewLicense(string licenseNumber, time_t newExpiryDate) {
            for (int i = 0; i < drivers.size(); i++) {
                if (drivers[i].licenseNumber == licenseNumber) {
                    drivers[i].licenseExpiryDate = newExpiryDate;
                    cout << "License " << licenseNumber << " has been renewed." << endl;
                    return;
                }
            }
            cout << "Driver with license number " << licenseNumber << " not found." << endl;
        }

};



string welcomeMessage() {
    string userInput;
    cout << "\t\tWelcome to the DVLA Driver and Vehicle licensing software.\n";
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << setw(3) << "1." << setw(50) << "To register a new vehicle, press '1'.\n";
    cout << setw(3) << "2." << setw(50) << "To renew a vehicle registration, press '2'.\n";
    cout << setw(3) << "3." << setw(50) << "To register a new driver, press '3'.\n";
    cout << setw(3) << "4." << setw(50) << "To renew a driver registration, press '4'.\n";
    cout << setw(3) << "9." << setw(50) << "To exit, press '9'.\n" << endl;
    cout << "Please enter a valid input: ";
    cin >> userInput;

    return userInput;
}

int main () {
    Officer testOfficer;
    string userInput;

    userInput = welcomeMessage();

    while (userInput != "9") {
            string make, model, registrationNumber, lastName, firstName, licenseNumber;
        if (userInput == "1") {
            cout << "\nEnter car make: ";
            cin >> make;
            cout << "Enter car model: ";
            cin >> model;
            cout << "Enter vehicle registration number: ";
            cin >> registrationNumber;

            testOfficer.registerVehicle(make, model, registrationNumber, time(NULL));
            userInput = "";
        }
        else if (userInput == "2") {
            cout << "\nEnter the vehicle registration number: ";
            cin >> registrationNumber;

            testOfficer.renewRegistration(registrationNumber, time(NULL));
            userInput = "";
        }
        else if (userInput == "3") {
            cout << "\nEnter last name: ";
            cin >> lastName;
            cout << "Enter first name: ";
            cin >> firstName;
            cout << "Enter driver license number: ";
            cin >> licenseNumber;

            testOfficer.issueLicense(lastName, firstName, licenseNumber, time(NULL));
            userInput = "";
        }
        else if (userInput == "4") {
            cout << "\nEnter the driver license number: ";
            cin >> licenseNumber;

            testOfficer.renewLicense(licenseNumber, time(NULL));
            userInput = "";
        }
        else {
            userInput = "";
            userInput = welcomeMessage();
        }
    }


    userInput = welcomeMessage();
    cout << userInput;
    return 0;
}
