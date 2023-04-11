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

class Officer {
    /*
    register vehicle *
    register driver *
    renew car registration *
    renew license *
    change car owner *
    replace license *
    */
    public:
        DVLAOffice* office;

        Officer(DVLAOffice* office) {
            this->office = office;
        }

        void registerVehicle(string make, string model, string ownerLastName, string ownerFirstName, string registrationNumber, string registrationType, string vehicleType, time_t registrationExpiry) {
            Vehicle vehicle = Vehicle(make, model, ownerLastName, ownerFirstName, registrationNumber, registrationType, vehicleType, registrationExpiry);
            office->vehicles.push_back(vehicle);
        }

        void issueLicense(string lastName, string firstName, string licenseNumber, time_t licenseExpiry) {
            Driver driver = Driver(lastName, firstName, licenseNumber, licenseExpiry);
            office->drivers.push_back(driver);
        }

        void renewVehicleRegistration(string registrationNumber) {
            for(int i = 0; i < office->vehicles.size(); i++) {
                if (office->vehicles[i].registrationNumber == registrationNumber) {
                    office->vehicles[i].registrationExpiry = time(NULL);
                    cout << "Vehicle with registration number " << registrationNumber << " successfully renewed.\n\n";
                    return;
                }
            }
            cout << "No vehicle with registration number " << registrationNumber << " was found.\n\n";
        }

        void renewLicense(string licenseNumber) {
            for(int i = 0; i < office->drivers.size(); i++) {
                if (office->drivers[i].licenseNumber == licenseNumber) {
                    office->drivers[i].licenseExpiry = time(NULL);
                    cout << "License of " << office->drivers[i].lastName << " renewed successfully.\n\n";
                    return;
                }
            }
            cout << "No driver with license number " << licenseNumber << " was found.\n\n";
        }

        void changeVehicleOwner(string registrationNumber) {
            for(int i = 0; i < office->vehicles.size(); i++) {
                if (office->vehicles[i].registrationNumber == registrationNumber) {
                    string lastName, firstName;
                    cout << "Please input the last name of the new owner: ";
                    cin >> lastName;
                    cout << "Please input the first name of the new owner: ";
                    cin >> firstName;

                    office->vehicles[i].ownerLastName = lastName;
                    office->vehicles[i].ownerFirstName = firstName;

                    cout << "Owner of vehicle changed successfully.\n\n";
                    return;
                }
            }

            string response, make, model, vehicleType, lastName, firstName, newRegistrationNumber, registrationType;
            cout << "There is no vehicle with that number registered. Do you wish to register a new vehicle?\n";
            cout << "Press 'y' or 'Y' to register a new vehicle.\nPress any other key to to return.";
            cin >> response;

            if (response == "y" || response == "Y") {
                cout << "\nEnter car make: ";
                cin >> make;
                cout << "Enter car model: ";
                cin >> model;
                cout << "Enter the vehicle type: ";
                cin >> vehicleType;
                cout << "Enter owner's last name: ";
                cin >> lastName;
                cout << "Enter owner's first name: ";
                cin >> firstName;
                cout << "Enter vehicle registration number: ";
                cin >> newRegistrationNumber;
                cout << "Enter the type of registration,(whether private or commercial): ";
                cin >> registrationType;

                registerVehicle(make, model, lastName, firstName, registrationNumber, registrationType, vehicleType, time(NULL));
                return;
            }
        }

        void replaceLicense(string licenseNumber) {
             for (int i = 0; i < office->drivers.size(); i++) {
                if (office->drivers[i].licenseNumber == licenseNumber) {
                    string newLicenseNumber;
                    cout << "Please enter new license number for " << office->drivers[i].lastName << " .\n";
                    cin >> newLicenseNumber;

                    office->drivers[i].licenseNumber = newLicenseNumber;

                    cout << "License of " << office->drivers[i].lastName << " successfully replaced.\n";

                    return;
                }
            }

            string response, lastName, firstName, newLicenseNumber;
            cout << "There is no license with that number registered. Do you wish to register a new driver?\n";
            cout << "Press 'y' or 'Y' to register a new driver.\nPress any other key to to return.";
            cin >> response;

            if (response == "y" || response == "Y") {
                cout << "\nEnter last name: ";
                cin >> lastName;
                cout << "Enter first name: ";
                cin >> firstName;
                cout << "Enter driver license number: ";
                cin >> newLicenseNumber;

                issueLicense(lastName, firstName, newLicenseNumber, time(NULL));
                return ;
            }
        }

};

int welcomeMessage() {
    int userInput;
    cout << "\t\tWelcome to the DVLA Driver and Vehicle licensing software.\n";
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << setw(3) << "1." << setw(60) << "To register a new vehicle, press '1'.\n";
    cout << setw(3) << "2." << setw(60) << "To renew a vehicle registration, press '2'.\n";
    cout << setw(3) << "3." << setw(60) << "To register a new driver, press '3'.\n";
    cout << setw(3) << "4." << setw(60) << "To renew a driver registration, press '4'.\n";
    cout << setw(3) << "5." << setw(60) << "To replace a lost driver's license, press '5'.\n";
    cout << setw(3) << "6." << setw(60) << "To change the owner of a registered vehicle, press '6'.\n";
    cout << setw(3) << "99." << setw(60) << "To view all registered vehicles and drivers, press '99'.\n";
    cout << setw(3) << "9." << setw(60) << "To exit, press '9'.\n" << endl;
    cout << "Please enter a valid input: ";
    cin >> userInput;

    return userInput;
}

ostream& operator<<(ostream& os, DVLAOffice office) {
os << "\t\t\t***DRIVERS***\n";
    os << setw(15) << "Surname" << " || " << setw(15) << "First Name" << " || " << setw(15) << "License Number" << endl;
    os << "___________________________________________________________________\n";
    if (office.drivers.size() < 1) {
        os << "There are no registered drivers.\n";
    }
    for(int i = 0; i < office.drivers.size(); i++) {
        os << setw(15) << office.drivers[i].lastName << " || " << setw(15) << office.drivers[i].firstName << " || " << setw(15) << office.drivers[i].licenseNumber << endl;
    }

    os<< "\n\n\t\t\t***VEHICLES***\n";
    os << setw(10) << "Make" << " || " << setw(15) << "Model" << " || " << setw(22) << "Registration Number" << " || " << setw(15) << "Registration Type" << endl;
    os << "________________________________________________________________________________\n";
    if (office.vehicles.size() < 1) {
        os << "There are no registered vehicles.\n";
        return os;
    }
    for(int i = 0; i < office.vehicles.size(); i++) {
            os << setw(10) << office.vehicles[i].make << " || "
            << setw(15) << office.vehicles[i].model << " || " << setw(22) << office.vehicles[i].registrationNumber << " || " << setw(15) << office.vehicles[i].registrationType << endl;
    }
    os << endl << endl;

    return os;
}

int main() {
    DVLAOffice kumasiOffice;
    Officer Kim = Officer(&kumasiOffice);
    int input;

     while (input != 9) {
        string make, model, vehicleType, lastName, firstName, licenseNumber, registrationNumber, registrationType;
        switch (input) {
        case 1:
            cout << "\nEnter car make: ";
            cin >> make;
            cout << "Enter car model: ";
            cin >> model;
            cout << "Enter owner's last name: ";
            cin >> lastName;
            cout << "Enter owner's first name: ";
            cin >> firstName;
            cout << "Enter vehicle registration number: ";
            cin >> registrationNumber;
            cout << "Enter registration type,(whether private or commercial): ";
            cin >> registrationType;

            system("CLS");
            Kim.registerVehicle(make, model, lastName, firstName, registrationNumber, registrationType, vehicleType, time(NULL));
            input = 0;
        }
     }

    return 0;
}
