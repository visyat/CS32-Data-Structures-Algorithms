//  PassengerDatabase.h
//  Titanic
//  Created by Vishal Yathish on 11/18/23.

#ifndef PassengerDatabase_h
#define PassengerDatabase_h

#include <string>
#include <vector>
#include <iterator>
#include <map>

#include "Enums.h"
#include "Passenger.h"
#include "DataCollectorCallback.h"

namespace cs32
{

class PassengerDatabase : public DataCollectorCallback
{
public:
    PassengerDatabase();
    ~PassengerDatabase();
    
    int load (std::string filepath);
    void clearAllPassengers();
    bool loaded();
    
    Passenger* getPassenger_byName(std::string name);
    std::vector<Passenger*> getPassengers();
    std::vector< Passenger * > getPassengers_byClass(Class paidClass, bool survived, double minimumFare);
    std::vector<Passenger*> getPassengers_byEmbarcation (Embarcation embarked, bool survived, double minimumFare);
    
    //part of the DataCollectorCallback interface
    void virtual csvData(std::map<std::string, std::string> row);

private:
    std::vector<Passenger*> passengers;
    bool isLoaded;
    
};

}

#endif /* PassengerDatabase_h */
