//  PassengerOutputTable.h
//  Titanic
//  Created by Vishal Yathish on 11/18/23.

#ifndef PassengerOutputTable_h
#define PassengerOutputTable_h

#include <string>
#include <vector>
#include <iterator>

#include "Passenger.h"
#include "PassengerDatabase.h"
#include "OutputTableRow.h"

namespace cs32
{

class PassengerOutputTable
{
public:
    PassengerOutputTable(std::vector< Passenger * > passengers);
    void setOutputField(Field f);
    void setDescription(std::string description);
    Field getOutputField();
    std::string getDescription();
    
    void display();
    size_t rowCount();
    OutputTableRow getRow(int index);
    
private:
    std::vector< Passenger * > mPassengerList;
    std::vector< OutputTableRow > mRows;
    Field mField;
    std::string mDescription; 
    
};

}

#endif /* PassengerOutputTable_h */
