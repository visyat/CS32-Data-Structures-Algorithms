//  PassengerOutputTable.cpp
//  Titanic
//  Created by Vishal Yathish on 11/18/23.

#include <iostream>

#include "PassengerOutputTable.h"
#include "OutputTableRow.h"

namespace cs32
{

PassengerOutputTable::PassengerOutputTable(std::vector< Passenger * > passengers): mPassengerList(passengers)
{
}

//Basic getters and setters for mField and mDescription variables
void PassengerOutputTable::setOutputField(Field f)
{
    mField = f;
}
Field PassengerOutputTable::getOutputField()
{
    return mField;
}
void PassengerOutputTable::setDescription(std::string description)
{
    mDescription = description;
}
std::string PassengerOutputTable::getDescription()
{
    return mDescription;
}

//Primary method of this class; produces the final output table
void PassengerOutputTable::display()
{
    std::cout << mDescription << std::endl;
    //I used the \t character to align columns
    std::cout << "\t\t\t Survived / Total \tPercentage(%)" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    
    //NEED TO CLEAR mRows SO THAT ROWS FROM PREVIOUS CALLS DO NOT REMAIN
    mRows.clear();
    
    //Got summary statistics/counts of survival and totals by class, embarcation, and fare
    //SUMMARY STATISTICS BY CLASS
    int first_class_survived = 0;
    int first_class_total = 0;
    
    int second_class_survived = 0;
    int second_class_total = 0;
    
    int third_class_survived = 0;
    int third_class_total = 0;
    
    int NK_class_survived = 0;
    int NK_class_total = 0;
    
    //SUMMARY STATISTICS BY EMBARCATION
    int C_embarked_survived = 0;
    int C_embarked_total = 0;
    
    int Q_embarked_survived = 0;
    int Q_embarked_total = 0;
    
    int S_embarked_survived = 0;
    int S_embarked_total = 0;
    
    int NK_embarked_survived = 0;
    int NK_embarked_total = 0;
    
    //SUMMARY STATISTICS BY FARE
    int less_10_fare_survived = 0;
    int less_10_fare_total = 0;
    
    int less_25_fare_survived = 0;
    int less_25_fare_total = 0;
    
    int less_50_fare_survived = 0;
    int less_50_fare_total = 0;
    
    int greater_50_fare_survived = 0;
    int greater_50_fare_total = 0;
    
    int NK_fare_survived = 0;
    int NK_fare_total = 0;
    
    std::vector< Passenger * >::iterator iter = mPassengerList.begin();
    while (iter != mPassengerList.end())
    {
        //GET SUMMARY STATS BY CLASS
        if ((*iter)->getClass() == Class::FIRST)
        {
            if ((*iter)->getSurvived() == true)
                first_class_survived++;
            first_class_total++;
        }
        else if ((*iter)->getClass() == Class::SECOND)
        {
            if ((*iter)->getSurvived() == true)
                second_class_survived++;
            second_class_total++;
        }
        else if ((*iter)->getClass() == Class::THIRD)
        {
            if ((*iter)->getSurvived() == true)
                third_class_survived++;
            third_class_total++;
        }
        else
        {
            if ((*iter)->getSurvived() == true)
                NK_class_survived++;
            NK_class_total++;
        }
        
        //GET SUMMARY STATISTICS BY EMBARCATION
        if ((*iter)->getEmbarcation() == Embarcation::CHERBOURG)
        {
            if ((*iter)->getSurvived() == true)
                C_embarked_survived++;
            C_embarked_total++;
        }
        else if ((*iter)->getEmbarcation() == Embarcation::QUEENSTOWN)
        {
            if ((*iter)->getSurvived() == true)
                Q_embarked_survived++;
            Q_embarked_total++;
        }
        else if ((*iter)->getEmbarcation() == Embarcation::SOUTHHAMPTON)
        {
            if ((*iter)->getSurvived() == true)
                S_embarked_survived++;
            S_embarked_total++;
        }
        else
        {
            if ((*iter)->getSurvived() == true)
                NK_embarked_survived++;
            NK_embarked_total++;
        }
        
        //GET SUMMARY STATISTICS BY FARE
        if ((*iter)->getFare() > 0 && (*iter)->getFare()<= 10)
        {
            if ((*iter)->getSurvived() == true)
                less_10_fare_survived++;
            less_10_fare_total++;
        }
        else if ((*iter)->getFare() > 10 && (*iter)->getFare() <= 25)
        {
            if ((*iter)->getSurvived() == true)
                less_25_fare_survived++;
            less_25_fare_total++;
        }
        else if ((*iter)->getFare() > 25 && (*iter)->getFare() <= 50)
        {
            if ((*iter)->getSurvived() == true)
                less_50_fare_survived++;
            less_50_fare_total++;
        }
        else if ((*iter)->getFare() > 50)
        {
            if ((*iter)->getSurvived() == true)
                greater_50_fare_survived++;
            greater_50_fare_total++;
        }
        else
        {
            if ((*iter)->getSurvived() == true)
                NK_fare_survived++;
            NK_fare_total++;
        }
        iter++;
    }
    
    //Summary statistics have been fully filled; now have to assign row values by mField and within these, assign specific row descriptions for each value within the field
    switch (mField)
    {
        case Field::BYCLASS:
            
            for (int i = 0; i < 4; i++)
            {
                OutputTableRow row;
                
                if (i == 0)
                {
                    row.setDescription("First Class");
                    row.setTotal(first_class_total);
                    row.setSurvived(first_class_survived);
                }
                else if (i == 1)
                {
                    row.setDescription("Second Class");
                    row.setTotal(second_class_total);
                    row.setSurvived(second_class_survived);
                }
                else if (i == 2)
                {
                    row.setDescription("Third Class");
                    row.setTotal(third_class_total);
                    row.setSurvived(third_class_survived);
                }
                else if (i == 3)
                {
                    row.setDescription("Not Known");
                    row.setTotal(NK_class_total);
                    row.setSurvived(NK_class_survived);
                }
                
                mRows.push_back(row);
            }
            
            break;
        case Field::BYEMBARCATION:
            
            for (int i = 0; i < 4; i++)
            {
                OutputTableRow row;
                if (i == 0)
                {
                    row.setDescription("Cherbourg");
                    row.setTotal(C_embarked_total);
                    row.setSurvived(C_embarked_survived);
                }
                else if (i == 1)
                {
                    row.setDescription("Queenstown");
                    row.setTotal(Q_embarked_total);
                    row.setSurvived(Q_embarked_survived);
                }
                else if (i == 2)
                {
                    row.setDescription("Southhampton");
                    row.setTotal(S_embarked_total);
                    row.setSurvived(S_embarked_survived);
                }
                else if (i == 3)
                {
                    row.setDescription("Not Known");
                    row.setTotal(NK_embarked_total);
                    row.setSurvived(NK_embarked_survived);
                }
                mRows.push_back(row);
            }
            
            break;
        case Field::BYFARE:
            
            for (int i = 0; i < 5; i++)
            {
                OutputTableRow row;
                if (i == 0)
                {
                    row.setDescription("Not Known");
                    row.setTotal(NK_fare_total);
                    row.setSurvived(NK_fare_survived);
                }
                else if (i == 1)
                {
                    row.setDescription("$1-$10");
                    row.setTotal(less_10_fare_total);
                    row.setSurvived(less_10_fare_survived);
                }
                else if (i == 2)
                {
                    row.setDescription("$10-$25");
                    row.setTotal(less_25_fare_total);
                    row.setSurvived(less_25_fare_survived);
                }
                else if (i == 3)
                {
                    row.setDescription("$25-$50");
                    row.setTotal(less_50_fare_total);
                    row.setSurvived(less_50_fare_survived);
                    
                }
                else if (i == 4)
                {
                    row.setDescription(">$50");
                    row.setTotal(greater_50_fare_total);
                    row.setSurvived(greater_50_fare_survived);
                }
                
                mRows.push_back(row);
            }
            
            break;
            
        case Field::NOVALUE:
            break;
    }

    for (int i = 0; i < rowCount(); i++)
        getRow(i).display();
    
}

//Basic helper methods now that the mRows vector has been populated by display()
//Returns the number of rows in the mRows vector
size_t PassengerOutputTable::rowCount()
{
    return mRows.size();
}
//Gets the vector at a specific index within the mRows vector
OutputTableRow PassengerOutputTable::getRow(int index)
{
    OutputTableRow row = mRows.at(index);
    return row;
}

}
