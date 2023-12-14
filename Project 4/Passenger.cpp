//  Passenger.cpp
//  Titanic
//  Created by Vishal Yathish on 11/18/23.

#include "Passenger.h"

namespace cs32
{

//Constructor for Passenger object; do not think I need to set anything particular here; all private variables assigned values by setter methods
Passenger::Passenger()
{
    mName = "";
    mEmbarked = Embarcation::NOTKNOWN;
    mClass = Class::NOTKNOWN;
    mSurvived = false;
    mFare = 0.0;
}

//Basic getter and setter methods for mName variable
void Passenger::setName(std::string name)
{
    mName = name;
}
std::string Passenger::getName()
{
    return mName;
}

//Getter and setter for mEmbarked variable; assigns Embarcation object from Enum choices based on string input
void Passenger::setEmbarcation(std::string embarked)
{
    if (embarked == "C")
        mEmbarked = Embarcation::CHERBOURG;
    else if (embarked == "Q")
        mEmbarked = Embarcation::QUEENSTOWN;
    else if (embarked == "S")
        mEmbarked = Embarcation::SOUTHHAMPTON;
    else
        mEmbarked = Embarcation::NOTKNOWN;
}
Embarcation Passenger::getEmbarcation()
{
    return mEmbarked;
}

//Getter and setter for mClass variable; assigns Class object from Enum choices based on string input, either the class number or the first letter of the class name (should not make a difference to the final output)
void Passenger::setClass(std::string classOfFare)
{
    if (classOfFare == "1" || classOfFare == "F")
        mClass = Class::FIRST;
    else if (classOfFare == "2" || classOfFare == "S")
        mClass = Class::SECOND;
    else if (classOfFare == "3" || classOfFare == "T")
        mClass = Class::THIRD;
    else
        mClass = Class::NOTKNOWN;
}
Class Passenger::getClass()
{
    return mClass;
}

//Getter and setter for mSurvived variable; boolean value based on string inputs 1 (survived - true) or 0 (did not survive - false)
void Passenger::setSurvived(std::string survived)
{
    if (survived == "1")
        mSurvived = true;
    else if (survived == "0")
        mSurvived = false;
    else
        mSurvived = false;
}
bool Passenger::getSurvived()
{
    return mSurvived;
}

//Getter and setter for mFare variable; used stof() method to convert string input to float value, except when no fare is known (default value is 0)
void Passenger::setFare(std::string fare)
{
    if (fare == "")
        mFare = 0.0;
    else
        mFare = std::stof(fare);
}
double Passenger::getFare()
{
    return mFare;
}

}
