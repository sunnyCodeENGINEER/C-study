class Vehicle {
    private:
        string make;
        string model;
        int year;
        string reg_num;
        string owner_name;
        int registration_expiry;

    public:
        void register_vehicle(string make, string model, int year, string reg_num, string owner_name, int registration_expiry);
        void renew_registration(int new_expiry);
};

void Vehicle::register_vehicle(string make, string model, int year, string reg_num, string owner_name, int registration_expiry) {
    this->make = make;
    this->model = model;
    this->year = year;
    this->reg_num = reg_num;
    this->owner_name = owner_name;
    this->registration_expiry = registration_expiry;
}

void Vehicle::renew_registration(int new_expiry) {
    this->registration_expiry = new_expiry;
}
