//  OutputTableRow.cpp
//  Titanic
//  Created by Vishal Yathish on 11/18/23.

#include <string>
#include <iostream>

#include "OutputTableRow.h"

namespace cs32
{

OutputTableRow::OutputTableRow()
{
}

//Basic getters and setters for mDescription, mSurvived, and mTotal variables
void OutputTableRow::setDescription(std::string description)
{
    mDescription = description;
}
std::string OutputTableRow::getDescription()
{
    return mDescription;
}
void OutputTableRow::setSurvived(int survived)
{
    mSurvived = survived;
}
int OutputTableRow::getSurvived()
{
    return mSurvived;
}
void OutputTableRow::setTotal(int total)
{
    mTotal = total;
}
int OutputTableRow::getTotal()
{
    return mTotal;
}

//Returns the survival/total percentage; easy to calculate, except for when mTotal is 0 for which the output value would be set to 0. The only case that this doesn't account for is if mSurvived is not equal to 0, but mTotal is equal to 0. The output would break; however, if the rest of the program is functions logically, then this should not be the case
double OutputTableRow::getPercentage()
{
    double output;
    if (mSurvived == 0 && mTotal == 0)
        output = 0.0;
    else
        output = double(mSurvived) / mTotal;
    
    return (output);
}

//The function to print out each row; I used the \t character to pad each value, and align the columns in the final output table, instead of implementing the private padToThreeCharacters() method. Howard said that this was acceptable, and would not be tested by the scorer.
void OutputTableRow::display()
{
    if (mDescription == ">$50")
        std::cout << mDescription << " - \t\t\t" << mSurvived << "\t\t" << mTotal << "\t\t" << getPercentage()*100 << std::endl;
    else if (mDescription == "$1-$10" || mDescription == "$10-$25" || mDescription == "$25-$50")
        std::cout << mDescription << " - \t\t" << mSurvived << "\t\t" << mTotal << "\t\t" << getPercentage()*100 << std::endl;
    else
        std::cout << mDescription << " - \t" << mSurvived << "\t\t" << mTotal << "\t\t" << getPercentage()*100 << std::endl;
}

}
