#include "vehiclerentsys.h"
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <vector>
#include <limits>

int mainmenu()
{

    std::cout <<
        R"(        ___                        __               
       /   |  ____ ___  ____ _____/ /__  __  _______
      / /| | / __ `__ \/ __ `/ __  / _ \/ / / / ___/
     / ___ |/ / / / / / /_/ / /_/ /  __/ /_/ (__  ) 
    /_/  |_/_/ /_/ /_/\__,_/\__,_/\___/\__,_/____/  
    )" << "\n";

    std::cout << "       #########################################\n";
    std::cout << "       #                                       #\n";
    std::cout << "       #        VEHICLE RENTAL SYSTEM          #\n";
    std::cout << "       #                                       #\n";
    std::cout << "       #########################################\n\n";
    std::cout << "\n\n"
              << std::endl;

    int mainmenuchoice{};
    std::cout << "Welcome to Amadeus vehical rental system! >> " << std::endl;
    std::cout << "Enter as > \n1-Administrator >> \n2-User >> " << std::endl;
    std::cin >> mainmenuchoice;

    return mainmenuchoice;
}

int Filesystem::administratorMenu()
{

    Filesystem adminsys1;

    std::cout << R"(        ___       __          _       _      __             __                                          
       /   | ____/ /___ ___  (_)___  (_)____/ /__________ _/ /_____  _____   ____ ___  ___  ____  __  __
      / /| |/ __  / __ `__ \/ / __ \/ / ___/ __/ ___/ __ `/ __/ __ \/ ___/  / __ `__ \/ _ \/ __ \/ / / /
     / ___ / /_/ / / / / / / / / / / (__  ) /_/ /  / /_/ / /_/ /_/ / /     / / / / / /  __/ / / / /_/ / 
    /_/  |_\__,_/_/ /_/ /_/_/_/ /_/_/____/\__/_/   \__,_/\__/\____/_/     /_/ /_/ /_/\___/_/ /_/\__,_/      
    )" << "\n";

    int adminchoice{};

    std::string border(50, '=');
    std::cout << border << "\n";
    std::cout << "| 1 - View Database                       |\n";
    std::cout << "| 2 - Modify Database                     |\n";
    std::cout << "| 3- Exit                                 |\n";
    std::cout << border << "\n";
    std::cin >> adminchoice;

    switch (adminchoice)
    {
    case 1:
    {
        system("clear");
        std::ofstream createfl("Database.csv", std::ios::app);
        createfl.close();

        std::ifstream prntfl("Database.csv");
        printfile(prntfl);
    }
    break;

    case 2:
    {
        system("clear");
        std::ofstream createfl("Database.csv", std::ios::app);
        createfl.close();

        int modifydatachoice{};

        std::ifstream modifyfl("Database.csv");
        std::cout << "| 1 - Add new data                 |\n";
        std::cout << "| 2 - Update data                  |\n";
        std::cout << "| 3 - Delete data                  |\n";
        std::cin >> modifydatachoice;

        modifyfilemodule(modifydatachoice, modifyfl);
    }
    break;

    case 3:
        exit(0);
        break;

    default:
        std::cerr << "ERROR!, out-of-bounds option for administrator menu >> " << std::endl;
        return 1;
        break;
    }
    return 0;
}

int userMenu()
{
    std::cout << R"(       __  __                                            
      / / / /_______  _____   ____ ___  ___  ____  __  __
     / / / / ___/ _ \/ ___/  / __ `__ \/ _ \/ __ \/ / / /
    / /_/ (__  )  __/ /     / / / / / /  __/ / / / /_/ / 
    \____/____/\___/_/     /_/ /_/ /_/\___/_/ /_/\__,_/  
    )" << "\n";

    int userchoice{};
    std::cout << "Rent a: >  \n1-Car >> \n2-Truck >> \n3-Bike >> " << std::endl;
    std::cin >> userchoice;

    switch (userchoice)
    {
    case 1:
        system("clear");
        carmenu();
        break;

    case 2:
        system("clear");
        truckmenu();
        break;

    case 3:
        system("clear");
        bikemenu();
        break;

    default:
        std::cerr << "ERROR!,out-of-bounds or undefined input on User-menu. >> " << std::endl;
        return 1;
        break;
    }
    return 0;
}

void ToUpper(std::string &input)
{
    std::for_each(std::begin(input), std::end(input), [](char &c)
                  {
                      c = static_cast<char>(std::toupper(static_cast<unsigned char>(c))); // https://stackoverflow.com/a/59893102
                  });
}

int searcherrormodule(bool flag)
{

    if (!flag)
    {
        std::cerr << "ERROR!, failed to search >> " << std::endl;
        std::cout << "Press Enter to exit..";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        exit(0);
    }
    return 0;
}

std::string Vehicle::gettype() const { return type; };
std::string Vehicle::getchasisID() const { return chasisID; }
std::string Vehicle::getlicensePlate() const { return licensePlate; }
std::string Vehicle::getmake() const { return make; }
std::string Vehicle::getmodel() const { return model; }
std::string Vehicle::getyear() const { return year; }
std::string Vehicle::getfueltype() const { return fueltype; }
std::string Vehicle::getrenterID() const { return renterID; }
std::string Vehicle::getrentalRate() const { return rentalRate; }
std::string Vehicle::getengineCapacity() const { return engineCapacity; }
std::string Vehicle::getavailability() const { return availability; }

Vehicle &Vehicle::settype(std::string_view type)
{
    this->type = type;
    return *this;
}
Vehicle &Vehicle::setchasisID(std::string_view chasisID)
{
    this->chasisID = chasisID;
    return *this;
}
Vehicle &Vehicle::setlicensePlate(std::string_view licensePlate)
{
    this->licensePlate = licensePlate;
    return *this;
}
Vehicle &Vehicle::setmake(std::string_view make)
{
    this->make = make;
    return *this;
}
Vehicle &Vehicle::setmodel(std::string_view model)
{
    this->model = model;
    return *this;
}
Vehicle &Vehicle::setyear(std::string_view year)
{
    this->year = year;
    return *this;
}
Vehicle &Vehicle::setfueltype(std::string_view fueltype)
{
    this->fueltype = fueltype;
    return *this;
}
Vehicle &Vehicle::setrenterID(std::string_view renterID)
{
    this->renterID = renterID;
    return *this;
}
Vehicle &Vehicle::setrentalRate(std::string_view rentalRate)
{
    this->rentalRate = rentalRate;
    return *this;
}
Vehicle &Vehicle::setengineCapacity(std::string_view engineCapacity)
{
    this->engineCapacity = engineCapacity;
    return *this;
}
Vehicle &Vehicle::setavailability(std::string_view availability)
{
    this->availability = availability;
    return *this;
}

int carmenu()
{

    std::cout << R"(       ______                              __        __
      / ____/___ ______   ________  ____  / /_____ _/ /
     / /   / __ `/ ___/  / ___/ _ \/ __ \/ __/ __ `/ / 
    / /___/ /_/ / /     / /  /  __/ / / / /_/ /_/ / /  
    \____/\__,_/_/     /_/   \___/_/ /_/\__/\__,_/_/   
    )" << "\n";

    std::cout << "Cars available for rent: >> " << std::endl;

    std::ifstream openfile("Database.csv");
    std::string token{};
    int i{1};

    while (std::getline(openfile, token))
    {
        if (token.find("CAR") != std::string::npos && token.find("$") != std::string::npos)
        {
            std::cout << i << " > " << token << std::endl;
            ++i;
        }
    }
    std::cout<<"\n\n";

    std::string usermake{}, tokentwo{};
    bool found{false};
    int j{1}, counter{};

    std::cout << "What MAKE do you prefer? > ";
    std::cin.ignore();
    std::getline(std::cin, usermake);
    ToUpper(usermake);

    openfile.clear();
    openfile.seekg(0, std::ios::beg);

    while (std::getline(openfile, tokentwo))
    {
        if (tokentwo.find("CAR") != std::string::npos &&
            tokentwo.find("$") != std::string::npos &&
            tokentwo.find(usermake) != std::string::npos)
        {
            std::cout << j << " > " << tokentwo << std::endl;
            found = true;
            ++j;
        }
    }
    std::cout<<"\n\n";

    searcherrormodule(found);
    found = false;

    std::string usermodel{}, useryear{}, tokenthree{}, tokenextra{}, rate{}, noPlate{};
    std::cout << "what MODEL? > ";
    std::getline(std::cin, usermodel);
    std::cout << "what YEAR? > ";
    std::getline(std::cin, useryear);
    ToUpper(usermodel);
    ToUpper(useryear);

    openfile.clear();
    openfile.seekg(0, std::ios::beg);

    while (std::getline(openfile, tokenthree))
    {
        if (tokenthree.find("CAR") != std::string::npos &&
            tokenthree.find("$") != std::string::npos &&
            tokenthree.find(usermake) != std::string::npos &&
            tokenthree.find(usermodel) != std::string::npos &&
            tokenthree.find(useryear) != std::string::npos)
        {
            std::cout << j << " > " << tokenthree << std::endl;
            rate = tokenthree;
            found = true;
            ++counter;
            ++j;
        }
    }
    std::cout<<"\n\n";

    openfile.clear();
    openfile.seekg(0, std::ios::beg);
    searcherrormodule(found);
    bool counterfound{false};

    if (counter > 1)
    {
        std::cout << "Choose one (number plate) > ";
        std::getline(std::cin, noPlate);
        ToUpper(noPlate);

        while (std::getline(openfile, tokenextra))
        {
            if (tokenextra.find("CAR") != std::string::npos &&
                tokenextra.find("$") != std::string::npos &&
                tokenextra.find(usermake) != std::string::npos &&
                tokenextra.find(usermodel) != std::string::npos &&
                tokenextra.find(useryear) != std::string::npos &&
                tokenextra.find(noPlate) != std::string::npos)
            {
                std::cout << j << " > " << tokenextra << std::endl;
                counterfound = true;
                rate = tokenextra;
                ++j;
            }
        }
        searcherrormodule(counterfound);
    }
    std::cout<<"\n\n";

    openfile.close();

    std::stringstream readrate(rate);
    std::string tokenFour{};
    int rateiterator{};
    std::string stringrate{};

    while (std::getline(readrate, tokenFour, ','))
    {
        if (rateiterator == 8)
        {
            stringrate = tokenFour;
        }
        rateiterator++;
    }

    int actualrate{};
    try
    {
        actualrate = std::stoi(stringrate);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: rate is not a valid integer: >>  " << stringrate << "\n";
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Error: rate is out of range: >>  " << stringrate << "\n";
    }

    int rentdays{};
    std::cout << "How many days do you want to rent? > ";
    std::cin >> rentdays;

    Car *carobj = new Car();

    std::cout << "Your bill > " << carobj->calculatetotalrent(rentdays, actualrate) << "$" << std::endl;
    delete carobj;
    std::cout << "Press Enter to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return 0;
}

int truckmenu()
{

    std::cout << R"(      ______                __                      __        __
     /_  __/______  _______/ /__   ________  ____  / /_____ _/ /
      / / / ___/ / / / ___/ //_/  / ___/ _ \/ __ \/ __/ __ `/ / 
     / / / /  / /_/ / /__/ ,<    / /  /  __/ / / / /_/ /_/ / /  
    /_/ /_/   \__,_/\___/_/|_|  /_/   \___/_/ /_/\__/\__,_/_/   
    )" << "\n";

    std::cout << "Trucks available for rent: >> " << std::endl;

    std::ifstream openfile("Database.csv");
    std::string token{};
    int i{1};

    while (std::getline(openfile, token))
    {
        if (token.find("TRUCK") != std::string::npos && token.find("$") != std::string::npos)
        {
            std::cout << i << " > " << token << std::endl;
            ++i;
        }
    }
    std::cout<<"\n\n";

    std::string usermake{}, tokentwo{}, noPlate{}, tokenextra{};
    bool found{false};
    int j{1}, counter{};

    std::cout << "What MAKE do you prefer? > ";
    std::cin.ignore();
    std::getline(std::cin, usermake);
    ToUpper(usermake);

    openfile.clear();
    openfile.seekg(0, std::ios::beg);

    while (std::getline(openfile, tokentwo))
    {
        if (tokentwo.find("TRUCK") != std::string::npos &&
            tokentwo.find("$") != std::string::npos &&
            tokentwo.find(usermake) != std::string::npos)
        {
            std::cout << j << " > " << tokentwo << std::endl;
            found = true;
            ++j;
        }
    }
    std::cout<<"\n\n";

    searcherrormodule(found);
    found = false;

    std::string usermodel{}, useryear{}, tokenthree{}, rate{};
    std::cout << "what MODEL? > ";
    std::getline(std::cin, usermodel);
    std::cout << "what YEAR? > ";
    std::getline(std::cin, useryear);
    ToUpper(usermodel);
    ToUpper(useryear);

    openfile.clear();
    openfile.seekg(0, std::ios::beg);

    while (std::getline(openfile, tokenthree))
    {
        if (tokenthree.find("TRUCK") != std::string::npos &&
            tokenthree.find("$") != std::string::npos &&
            tokenthree.find(usermake) != std::string::npos &&
            tokenthree.find(usermodel) != std::string::npos &&
            tokenthree.find(useryear) != std::string::npos)
        {
            std::cout << j << " > " << tokenthree << std::endl;
            rate = tokenthree;
            found = true;
            counter++;
            ++j;
        }
    }
    std::cout<<"\n\n";

    openfile.clear();
    openfile.seekg(0, std::ios::beg);
    searcherrormodule(found);
    bool counterfound{false};

    if (counter > 1)
    {
        std::cout << "Choose one (number plate) > ";
        std::getline(std::cin, noPlate);
        ToUpper(noPlate);

        while (std::getline(openfile, tokenextra))
        {
            if (tokenextra.find("TRUCK") != std::string::npos &&
                tokenextra.find("$") != std::string::npos &&
                tokenextra.find(usermake) != std::string::npos &&
                tokenextra.find(usermodel) != std::string::npos &&
                tokenextra.find(useryear) != std::string::npos &&
                tokenextra.find(noPlate) != std::string::npos)
            {
                std::cout << j << " > " << tokenextra << std::endl;
                counterfound = true;
                rate = tokenextra;
                counter++;
                ++j;
            }
        }
        searcherrormodule(counterfound);
    }
    std::cout<<"\n\n";

    openfile.close();

    std::stringstream readrate(rate);
    std::string tokenFour{};
    int rateiterator{};
    std::string stringrate{};

    while (std::getline(readrate, tokenFour, ','))
    {
        if (rateiterator == 8)
        {
            stringrate = tokenFour;
        }
        rateiterator++;
    }

    int actualrate{};
    try
    {
        actualrate = std::stoi(stringrate);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: rate is not a valid integer: >>  " << stringrate << "\n";
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Error: rate is out of range: >>  " << stringrate << "\n";
    }

    int rentdays{};
    std::cout << "How many days do you want to rent? > ";
    std::cin >> rentdays;

    Truck *truckobj = new Truck();

    std::cout << "Your bill > " << truckobj->calculatetotalrent(rentdays, actualrate) << "$" << std::endl;
    delete truckobj;
    std::cout << "Press Enter to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return 0;
}

int bikemenu()
{

    std::cout << R"(        ____  _ __                           __        __
       / __ )(_) /_____     ________  ____  / /_____ _/ /
      / __  / / //_/ _ \   / ___/ _ \/ __ \/ __/ __ `/ / 
     / /_/ / / ,< /  __/  / /  /  __/ / / / /_/ /_/ / /  
    /_____/_/_/|_|\___/  /_/   \___/_/ /_/\__/\__,_/_/   
    )" << "\n";

    std::cout << "Bikes available for rent: >> " << std::endl;

    std::ifstream openfile("Database.csv");
    std::string token{};
    int i{1};

    while (std::getline(openfile, token))
    {
        if (token.find("BIKE") != std::string::npos && token.find("$") != std::string::npos)
        {
            std::cout << i << " > " << token << std::endl;
            ++i;
        }
    }

    std::cout<<"\n\n";

    std::string usermake{}, tokentwo{}, tokenextra{}, noPlate{};
    bool found{false};
    int j{1}, counter{};

    std::cout << "What MAKE do you prefer? > ";
    std::cin.ignore();
    std::getline(std::cin, usermake);
    ToUpper(usermake);

    openfile.clear();
    openfile.seekg(0, std::ios::beg);

    while (std::getline(openfile, tokentwo))
    {
        if (tokentwo.find("BIKE") != std::string::npos &&
            tokentwo.find("$") != std::string::npos &&
            tokentwo.find(usermake) != std::string::npos)
        {
            std::cout << j << " > " << tokentwo << std::endl;
            found = true;
            ++j;
        }
    }
    std::cout<<"\n\n";

    searcherrormodule(found);
    found = false;

    std::string usermodel{}, useryear{}, tokenthree{}, rate{};
    std::cout << "what MODEL? > ";
    std::getline(std::cin, usermodel);
    std::cout << "what YEAR? > ";
    std::getline(std::cin, useryear);
    ToUpper(usermodel);
    ToUpper(useryear);

    openfile.clear();
    openfile.seekg(0, std::ios::beg);

    while (std::getline(openfile, tokenthree))
    {
        if (tokenthree.find("BIKE") != std::string::npos &&
            tokenthree.find("$") != std::string::npos &&
            tokenthree.find(usermake) != std::string::npos &&
            tokenthree.find(usermodel) != std::string::npos &&
            tokenthree.find(useryear) != std::string::npos)
        {
            std::cout << j << " > " << tokenthree << std::endl;
            rate = tokenthree;
            found = true;
            counter++;
            ++j;
        }
    }
    std::cout<<"\n\n";

    openfile.clear();
    openfile.seekg(0, std::ios::beg);
    searcherrormodule(found);
    bool counterfound{false};

    if (counter > 1)
    {
        std::cout << "Choose one (number plate) > ";
        std::getline(std::cin, noPlate);
        ToUpper(noPlate);

        while (std::getline(openfile, tokenextra))
        {
            if (tokenextra.find("BIKE") != std::string::npos &&
                tokenextra.find("$") != std::string::npos &&
                tokenextra.find(usermake) != std::string::npos &&
                tokenextra.find(usermodel) != std::string::npos &&
                tokenextra.find(useryear) != std::string::npos &&
                tokenextra.find(noPlate) != std::string::npos)
            {
                std::cout << j << " > " << tokenextra << std::endl;
                counterfound = true;
                rate = tokenextra;
                ++j;
            }
        }
        searcherrormodule(counterfound);
    }
    openfile.close();
    std::cout<<"\n\n";

    std::stringstream readrate(rate);
    std::string tokenFour{};
    int rateiterator{};
    std::string stringrate{};

    while (std::getline(readrate, tokenFour, ','))
    {
        if (rateiterator == 8)
        {
            stringrate = tokenFour;
        }
        rateiterator++;
    }

    int actualrate{};
    try
    {
        actualrate = std::stoi(stringrate);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: rate is not a valid integer: >>  " << stringrate << "\n";
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Error: rate is out of range: >>  " << stringrate << "\n";
    }

    int rentdays{};
    std::cout << "How many days do you want to rent? > ";
    std::cin >> rentdays;

    Bike *bikeobj = new Bike();

    std::cout << "Your bill > " << bikeobj->calculatetotalrent(rentdays, actualrate) << "$" << std::endl;
    delete bikeobj;
    std::cout << "Press Enter to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return 0;
}

int Filesystem::printfile(std::ifstream &pfile)
{

    std::string printcontainer{};

    if (!pfile)
    {
        std::cerr << "ERROR! couldnt open print-file >> " << std::endl;
    }

    while (std::getline(pfile, printcontainer))
    {
        std::cout << printcontainer << std::endl;
    }
    std::cout << "\n";
    pfile.close();

    std::cout << "Press Enter to exit...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return 0;
}

int Filesystem::modifyfilemodule(int option, std::ifstream &modfile)
{

    Vehicle modsys1;

    if (option < 0 || option > 3)
    {
        std::cerr << "ERROR!, out-of-bounds on modifying file options >> " << std::endl;
    }
    else if (option == 1)
    {
        modfile.close();

        int tempavail{};

        std::string input[] = {"chasisID", "type", "license plate", "make", "model", "year", "fueltype", "renterID", "rental rate", "engine capacity"};

        std::string output[10]{};

        std::cin.ignore();
        for (size_t i{}; i < 10; ++i)
        {
            std::cout << input[i] << ":" << " ";
            std::getline(std::cin, output[i]);
        }

        for (size_t k{}; k < 10; ++k)
        {
            ToUpper(output[k]);
        }

        std::cout << "Availability? (1 for yes and 2 for no) > ";
        std::cin >> tempavail;
        if (tempavail < 0 || tempavail > 2)
        {
            std::cerr << "Error! out-of-bounds error on availiblity option >> ";
        }
        else if (tempavail == 1)
        {
            modsys1.setavailability("$");
        }
        else if (tempavail == 0)
        {
            modsys1.setavailability("@");
        }

        std::fstream writetomodfile("Database.csv", std::ios::app);
        if (!writetomodfile)
        {
            std::cerr << "ERROR!,failed to open write-to-modify-file >> " << std::endl;
        }
        for (size_t j{}; j < 10; ++j)
        {
            writetomodfile << output[j] << ",";
        }
        writetomodfile << modsys1.getavailability() << std::endl;
        writetomodfile.close();

        std::cout << "Press Enter to exit...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else if (option == 2)
    {

        modfile.close();
        std::string oldval{}, newval{};

        std::cout << "Enter old value to be modified > ";
        std::cin.ignore();
        std::getline(std::cin, oldval);
        ToUpper(oldval);
        std::cout << "Enter new value > ";
        std::getline(std::cin, newval);
        ToUpper(newval);

        std::ifstream mainfile("Database.csv");
        if (!mainfile)
        {
            std::cerr << "ERROR!,couldnt open mainfile for file update! >> " << std::endl;
        }

        std::ofstream bufferfile("buffile.csv");
        if (!bufferfile)
        {
            std::cerr << "ERROR!,couldnt open buffer file for file update. >> " << std::endl;
        }

        std::string tokenizer{};

        while (std::getline(mainfile, tokenizer))
        {
            std::stringstream stringtoken(tokenizer);
            std::string field;
            std::vector<std::string> row;

            while (std::getline(stringtoken, field, ','))
            {
                row.push_back(field);
            }

            for (auto &q : row)
            {
                if (q == oldval)
                {
                    q = newval;
                }
            }

            for (size_t t{}; t < row.size(); ++t)
            {
                bufferfile << row[t];
                if (t != row.size() - 1)
                {
                    bufferfile << ",";
                }
            }
            bufferfile << "\n";
        }
        mainfile.close();
        bufferfile.close();

        if (std::remove("Database.csv") != 0)
        {
            std::cerr << "ERROR! unable to delete original file >> " << std::endl;
        }

        if (std::rename("buffile.csv", "Database.csv") != 0)
        {
            std::cerr << "ERROR renmaing temp file >> " << std::endl;
        }

        std::cout << "Updated successfully >> " << std::endl;

        std::cout << "Press Enter to exit...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return 0;
    }
    else if (option == 3)
    {

        modfile.close();

        std::string search{}, tokenizer{};
        bool found{false};

        std::cout << "Enter Chasis ID > ";
        std::cin.ignore();
        std::getline(std::cin, search);

        std::ifstream readfile("Database.csv");
        if (!readfile)
        {
            std::cerr << "ERROR!, couldnt open main file for deletion >> " << std::endl;
        }
        std::ofstream bufferfile("buffile.csv");
        if (!bufferfile)
        {
            std::cerr << "ERROR!, couldnt open buffer file for deletion >> " << std::endl;
        }

        while (std::getline(readfile, tokenizer))
        {
            if (tokenizer.find(search) == std::string::npos)
            {
                bufferfile << tokenizer << std::endl;
                found = true;
            }
        }

        searcherrormodule(found);
        found = false;

        readfile.close();
        bufferfile.close();

        if (std::remove("Database.csv") != 0)
        {
            std::cerr << "ERORR!, couldnt delete main file for file update on deletion >> " << std::endl;
        }

        if (std::rename("buffile.csv", "Database.csv") != 0)
        {
            std::cerr << "ERORR!, couldnt rename buffer file to main file update on deletion >> " << std::endl;
        }

        std::cout << "Deleted successfully! " << std::endl;

        std::cout << "Press Enter to exit...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return 0;
    }
    return 0;
}
