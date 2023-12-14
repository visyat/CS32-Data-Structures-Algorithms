//  PassengerDatabase.cpp
//  Created by Vishal Yathish on 11/18/23.

#include <iostream>

#include "Passenger.h"
#include "PassengerDatabase.h"
#include "CSVFile.h"

namespace cs32
{

PassengerDatabase::PassengerDatabase()
{
}
//Destructor calls the clearAllPassengers() method; they have the same effect of deleting all pointer elements of the vector
PassengerDatabase::~PassengerDatabase()
{
    clearAllPassengers();
}

//Loads the csv file from filepath to CSVFile object; readfile loads each row into map object - DataCollectorCallback instance uses PassengerDatabase's csvData() method, which loads row into a Passenger object and filling each attribute value
int PassengerDatabase::load (std::string filepath)
{
    CSVFile file(this);
    int recordCount = file.readFile(filepath);
    return(recordCount);
}

//Clears the passenger vector; while the passenger is not empty, pops the last pointer off the vector and deletes it (to prevent memory leaks). Clears the passengers vector for good measure.
void PassengerDatabase::clearAllPassengers()
{
    while (!passengers.empty()) //iterator object would not work in this case; iterator breaks when pointer is deleted
    {
        Passenger *p = passengers.back();
        passengers.pop_back();
        delete(p);
    }
    passengers.clear();
}

//Checks to see if the data has been loaded into passengers vector. I wanted to see if I could check the output of the load() function and see if it matched the passengers.size() value, but this is both unnecessary and impractical. There doesn't appear to be a way to access this result without calling the load() function again, potentially resulting in repeat values.
//There also doesn't seem a way to call the load function again, since the filepath is a parameter only within the scope of that function
bool PassengerDatabase::loaded()
{
    bool output;
    if (!passengers.empty())
        output = true;
    else
        output = false;
    
    return output;
}

//Getter function returning the whole passengers vector
std::vector< Passenger * > PassengerDatabase::getPassengers()
{
    return passengers;
}
//Getter function that iterates through passengers vector, checks if each passenger has the same name as the input string, and if so, it returns that Passenger pointer object.
Passenger* PassengerDatabase::getPassenger_byName(std::string name)
{
    Passenger* output = nullptr;
    std::vector < Passenger * >::iterator iter = passengers.begin();
    
    while (iter != passengers.end())
    {
        //finds the first passenger that has the same name as input string; may have issues with passengers w/ duplicate, common names (e.g. John Smith, etc.)
        if ((*iter)->getName() == name)
        {
            output = *iter;
            break;
        }
        ++iter;
    }
    return output;
}

//Getter functions that iterates through the passengers vector, sees if each element has the chosen attributes (Class, Embarcation, etc.), and if so, pushes it to an output vector. The resulting vector will be a filtered subset of the passengers vector with the chosen attributes
std::vector< Passenger * > PassengerDatabase::getPassengers_byClass(Class paidClass, bool survived, double minimumFare)
{
    std::vector< Passenger * > output;
    std::vector< Passenger * >::iterator iter = passengers.begin();
    
    while (iter != passengers.end())
    {
        if ((*iter)->getClass() == paidClass && (*iter)->getFare() >= minimumFare && (*iter)->getSurvived() == survived)
            output.push_back(*iter);
        iter++;
    }
    
    return output;
}
std::vector<Passenger*> PassengerDatabase::getPassengers_byEmbarcation (Embarcation embarked, bool survived, double minimumFare)
{
    std::vector< Passenger * > output;
    std::vector< Passenger * >::iterator iter = passengers.begin();
    
    while (iter != passengers.end())
    {
        if ((*iter)->getEmbarcation() == embarked && (*iter)->getFare() >= minimumFare && (*iter)->getSurvived() == survived)
            output.push_back(*iter);
        ++iter;
    }
    
    return output;
}
std::vector<Passenger*> PassengerDatabase::getPassengersFromCherbourg()
{
    std::vector< Passenger * > output;
    std::vector< Passenger * >::iterator iter = passengers.begin();
    while (iter != passengers.end())
    {
        if ( (*iter)->getEmbarcation() == Embarcation::CHERBOURG )
            output.push_back(*iter);
        ++iter;
    }
    return output;
}
//PassengerDatabase version of the inherited csvData() method from DataCollectorCallback class; creates a new Passenger pointer, and uses the setter methods from Passenger class to assign attribute values from the map from CSVFile
void PassengerDatabase::csvData(std::map<std::string, std::string> row)
{
    Passenger* p = new Passenger();
    p -> setClass(row["pclass"]);
    p -> setEmbarcation(row["embarked"]);
    p -> setName(row["name"]);
    p -> setSurvived(row["survived"]);
    p -> setFare(row["fare"]);
    
    passengers.push_back(p);
}

}
