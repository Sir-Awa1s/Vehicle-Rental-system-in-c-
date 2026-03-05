#ifndef VEHICLERENTSYS_H
#define VEHICLERENTSYS_H

#include<string>
#include<fstream>
#include<string_view>

int mainmenu();
int userMenu();
void ToUpper(std::string& input);

class Vehicle{
    private:
    std::string chasisID{},type{},licensePlate{},make{},model{},year{},fueltype{},renterID{},
     rentalRate{},engineCapacity{},availability{};

    public:
    std::string gettype()const;
    std::string getchasisID()const;
    std::string getlicensePlate()const;
    std::string getmake()const;
    std::string getmodel()const;
    std::string getyear()const;
    std::string getfueltype()const;
    std::string getrenterID()const;
    std::string getrentalRate()const;
    std::string getengineCapacity()const;
    std::string getavailability()const;

    Vehicle& settype(std::string_view type);
    Vehicle& setchasisID(std::string_view chasisID);
    Vehicle& setlicensePlate(std::string_view licensePlate);
    Vehicle& setmake(std::string_view make);
    Vehicle& setmodel(std::string_view model);
    Vehicle& setyear(std::string_view year);
    Vehicle& setfueltype(std::string_view fueltype);
    Vehicle& setrenterID(std::string_view renterID);
    Vehicle& setrentalRate(std::string_view rentalRate);
    Vehicle& setengineCapacity(std::string_view engineCapacity);
    Vehicle& setavailability(std::string_view availability);    

};

class IVehicle : public Vehicle{
    public:
    
    virtual double calculatetotalrent(int days,double rate){
        return days*rate;
    }
    virtual ~IVehicle()=default;
};

class Car : public IVehicle{
    private:
    std::string cartype{};
    std::string carseats{};
    double carratePerDay{},carratePerHour{};

    public:

    Car()=default;

    std::string getcartype(){return cartype;}
    std::string getcarseats(){return carseats;}
    double getcarrateperday(){return carratePerDay;}
    double getcarrateperhour(){return carratePerHour;}

    Car& setcartype(std::string_view cartype){this->cartype=cartype; return *this;}
    Car& setcarseats(std::string_view carseats){this->carseats=carseats; return *this;}
    Car& setcarrateperday(double carratePerDay){this->carratePerDay=carratePerDay; return *this;}
    Car& setcarrateperhour(double carratePerHour){this->carratePerHour=carratePerHour; return *this;}

    double calculatetotalrent(int days,double rate) override {
        return days*rate;
    }
};

class Truck : public IVehicle{
    private:
    std::string trucktype{};
    std::string truckseats{};
    double truckratePerDay{},truckratePerHour{};

    public:

    Truck()=default;

    std::string gettrucktype(){return trucktype;}
    std::string gettruckseats(){return truckseats;}
    double gettruckrateperday(){return truckratePerDay;}
    double gettruckrateperhour(){return truckratePerHour;}

    Truck& settrucktype(std::string_view trucktype){this->trucktype=trucktype; return *this;}
    Truck& setbtruckseats(std::string_view truckseats){this->truckseats=truckseats; return *this;}
    Truck& settruckrateperday(double truckratePerDay){this->truckratePerDay=truckratePerDay; return *this;}
    Truck& settruckrateperhour(double truckratePerHour){this->truckratePerHour=truckratePerHour; return *this;}

    double calculatetotalrent(int days,double rate) override {
        return days*rate;
    }
};

class Bike : public IVehicle{
    private:
    std::string biketype{};
    std::string bikeseats{};
    double bikeratePerDay{},bikeratePerHour{};

    public:

    Bike()=default;

    std::string getbiketype(){return biketype;}
    std::string getbikeseats(){return bikeseats;}
    double getbikerateperday(){return bikeratePerDay;}
    double getbikerateperhour(){return bikeratePerHour;}

    Bike& setbiketype(std::string_view biketype){this->biketype=biketype; return *this;}
    Bike& setbikeseats(std::string_view bikeseats){this->bikeseats=bikeseats; return *this;}
    Bike& setbikerateperday(double bikeratePerDay){this->bikeratePerDay=bikeratePerDay; return *this;}
    Bike& setbikerateperhour(double bikeratePerHour){this->bikeratePerHour=bikeratePerHour; return *this;}


    double calculatetotalrent(int days,double rate) override {
        return days*rate;
    }
};

class Filesystem{
    public:
    Filesystem()=default;

    int administratorMenu();
    int printfile(std::ifstream& pfile);
    int modifyfilemodule(int option,std::ifstream& modfile);
};

int carmenu();
int truckmenu();
int bikemenu();
int searcherrormodule(bool flag);
#endif