//  Passenger.h
//  Titanic
//  Created by Vishal Yathish on 11/18/23.

#ifndef Passenger_h
#define Passenger_h

#include <string>
#include "Enums.h"

namespace cs32
{

class Passenger
{
public:
    Passenger();
    void setName(std::string name);
    std::string getName();
    
    void setEmbarcation(std::string embarked);
    void setClass(std::string classOfFare);
    void setSurvived(std::string survived);
    void setFare(std::string fare);
    
    Embarcation getEmbarcation();
    Class getClass();
    bool getSurvived();
    double getFare();
    
private:
    Class mClass;
    Embarcation mEmbarked;
    std::string mName;
    bool mSurvived;
    double mFare;
    
};

}

#endif /* Passenger_h */
