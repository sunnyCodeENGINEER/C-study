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
        string ownerLastName;
        string ownerFirstName;
        string registrationNumber;
        time_t registrationExpiryDate;

        Vehicle(string make, string model, string ownerLastName, string ownerFirstName, string registrationNumber, time_t registrationExpiryDate) {
            this->make = make;
            this->model = model;
            this->ownerLastName = ownerLastName;
            this->ownerFirstName = ownerFirstName;
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

class DVLAOffice {
    public:
        vector<Vehicle> vehicles;
        vector<Driver> drivers;
};

class Officer {
    public:

        void registerVehicle(string make, string model, string ownerLastName, string ownerFirstName, string registrationNumber, time_t registrationExpiryDate, DVLAOffice office) {
            Vehicle vehicle(make, model, ownerLastName, ownerFirstName, registrationNumber, registrationExpiryDate);
            office.vehicles.push_back(vehicle);
            cout << "Vehicle registered successfully." << endl;
        }

        void issueLicense(string lastName, string firstName, string licenseNumber, time_t licenseExpiryDate, DVLAOffice office) {
            Driver driver(lastName, firstName, licenseNumber, licenseExpiryDate);
            office.drivers.push_back(driver);
            cout << "License issued successfully to " << firstName << " " << lastName << ".\n\n";
        }

        bool findRegistration(string registrationNumber, DVLAOffice office) {
            for (int i = 0; i < office.vehicles.size(); i++) {
                    if (office.vehicles[i].registrationNumber == registrationNumber) {
                        return true;
                    }
            }
            return false;
        }

        bool findLicense(string licenseNumber, DVLAOffice office) {
            for (int i = 0; i < office.drivers.size(); i++) {
                if (office.drivers[i].licenseNumber == licenseNumber) {
                        return true;
                }
            }
            return false;
        }

        void checkRegistrationExpiry(string registrationNumber, DVLAOffice office) {
            for (int i = 0; i < office.vehicles.size(); i++) {
                if (office.vehicles[i].registrationNumber == registrationNumber) {
                    time_t currentTime = time(NULL);
                    if (office.vehicles[i].registrationExpiryDate < currentTime) {
                        cout << "Registration for vehicle " << registrationNumber << " has expired." << endl;
                    } else {
                        cout << "Registration for vehicle " << registrationNumber << " is valid." << endl;
                    }
                    return;
                }
            }
            cout << "Vehicle with registration number " << registrationNumber << " not found." << endl;
        }

        void checkLicenseExpiry(string licenseNumber, DVLAOffice office) {
            for (int i = 0; i < office.drivers.size(); i++) {
                if (office.drivers[i].licenseNumber == licenseNumber) {
                    time_t currentTime = time(NULL);
                    if (office.drivers[i].licenseExpiryDate < currentTime) {
                        cout << "License " << licenseNumber << " has expired." << endl;
                    } else {
                        cout << "License " << licenseNumber << " is valid." << endl;
                    }
                    return;
                }
            }
            cout << "Driver with license number " << licenseNumber << " not found." << endl;
        }

        void renewRegistration(string registrationNumber, time_t newExpiryDate, DVLAOffice office) {
            for (int i = 0; i < office.vehicles.size(); i++) {
                if (office.vehicles[i].registrationNumber == registrationNumber) {
                    office.vehicles[i].registrationExpiryDate = newExpiryDate;
                    cout << "Registration for vehicle " << registrationNumber << " has been renewed." << endl;
                    return;
                }
            }
            cout << "Vehicle with registration number " << registrationNumber << " not found." << endl;
        }

        void renewLicense(string licenseNumber, time_t newExpiryDate, DVLAOffice office) {
            for (int i = 0; i < office.drivers.size(); i++) {
                if (office.drivers[i].licenseNumber == licenseNumber) {
                    office.drivers[i].licenseExpiryDate = newExpiryDate;
                    cout << "License " << licenseNumber << " has been renewed." << endl;
                    return;
                }
            }
            cout << "Driver with license number " << licenseNumber << " not found." << endl;
        }

        void changeOfVehicleOwner(string registrationNumber, DVLAOffice office) {
            for (int i = 0; i < office.vehicles.size(); i++) {
                if (office.vehicles[i].registrationNumber == registrationNumber) {
                    string lastName, firstName;
                    cout << "Please enter new owner's last name: ";
                    cin >> lastName;
                    cout << "Please enter new owner's first name: ";
                    cin >> firstName;

                    office.vehicles[i].ownerLastName = lastName;
                    office.vehicles[i].ownerFirstName = firstName;

                    return;
                }
            }
            string response, make, model, lastName, firstName, newRegistrationNumber;
                cout << "There is no vehicle with that number registered. Do you wish to register a new vehicle?\n";
                cout << "Press 'y' or 'Y' to register a new vehicle.\nPress any other key to to return.";
                cin >> response;

                if (response == "y" || response == "Y") {
                    cout << "\nEnter car make: ";
                    cin >> make;
                    cout << "Enter car model: ";
                    cin >> model;
                    cout << "Enter owner's last name: ";
                    cin >> lastName;
                    cout << "Enter owner's first name: ";
                    cin >> firstName;
                    cout << "Enter vehicle registration number: ";
                    cin >> newRegistrationNumber;

                    registerVehicle(make, model, lastName, firstName, registrationNumber, time(NULL), office);
                }
                 else {
                    return;
                 }
        }

        void replaceLicense(string licenseNumber, DVLAOffice office) {
            for (int i = 0; i < office.drivers.size(); i++) {
                if (office.drivers[i].licenseNumber == licenseNumber) {
                    string newLicenseNumber;
                    cout << "Please enter new license number for " << office.drivers[i].lastName << " .\n";
                    cin >> newLicenseNumber;

                    return ;
                }
            }
            if (findLicense(licenseNumber, office)) {
                // implement code for replacing a lost license.
            }
            else {
                string response, lastName, firstName, licenseNumber;;
                cout << "There is no license with that number registered. Do you wish to register a new driver?\n";
                cout << "Press 'y' or 'Y' to register a new driver.\nPress any other key to to return.";
                cin >> response;

                if (response == "y" || response == "Y") {
                    cout << "\nEnter last name: ";
                    cin >> lastName;
                    cout << "Enter first name: ";
                    cin >> firstName;
                    cout << "Enter driver license number: ";
                    cin >> licenseNumber;

                    issueLicense(lastName, firstName, licenseNumber, time(NULL), office);
                }
                 else {
                    return;
                 }
            }
        }

};

string welcomeMessage() {
    string userInput;
    cout << "\t\tWelcome to the DVLA Driver and Vehicle licensing software.\n";
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << setw(3) << "1." << setw(60) << "To register a new vehicle, press '1'.\n";
    cout << setw(3) << "2." << setw(60) << "To renew a vehicle registration, press '2'.\n";
    cout << setw(3) << "3." << setw(60) << "To register a new driver, press '3'.\n";
    cout << setw(3) << "4." << setw(60) << "To renew a driver registration, press '4'.\n";
    cout << setw(3) << "5." << setw(60) << "To replace a lost driver's license, press '5'.\n";
    cout << setw(3) << "6." << setw(60) << "To change the owner of a registered vehicle, press '6'.\n";
    cout << setw(3) << "9." << setw(60) << "To exit, press '9'.\n" << endl;
    cout << "Please enter a valid input: ";
    cin >> userInput;

    return userInput;
}

int main () {
    DVLAOffice kumasiOffice;
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
            cout << "Enter owner's last name: ";
            cin >> lastName;
            cout << "Enter owner's first name: ";
            cin >> firstName;
            cout << "Enter vehicle registration number: ";
            cin >> registrationNumber;

            testOfficer.registerVehicle(make, model, lastName, firstName, registrationNumber, time(NULL), kumasiOffice);
            userInput = "";
        }
        else if (userInput == "2") {
            cout << "\nEnter the vehicle registration number: ";
            cin >> registrationNumber;

            testOfficer.renewRegistration(registrationNumber, time(NULL), kumasiOffice);
            userInput = "";
        }
        else if (userInput == "3") {
            cout << "\nEnter last name: ";
            cin >> lastName;
            cout << "Enter first name: ";
            cin >> firstName;
            cout << "Enter driver license number: ";
            cin >> licenseNumber;

            testOfficer.issueLicense(lastName, firstName, licenseNumber, time(NULL), kumasiOffice);
            userInput = "";
        }
        else if (userInput == "4") {
            cout << "\nEnter the driver license number: ";
            cin >> licenseNumber;

            testOfficer.renewLicense(licenseNumber, time(NULL), kumasiOffice);
            userInput = "";
        }
        else if (userInput == "5") {
            cout << "Enter the license number: ";
            cin >> licenseNumber;

            testOfficer.replaceLicense(licenseNumber, kumasiOffice);
            userInput = "";
        }
        else if (userInput == "6") {
            cout << "Enter the registration number: ";
            cin >> registrationNumber;

            testOfficer.changeOfVehicleOwner(registrationNumber, kumasiOffice);
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
