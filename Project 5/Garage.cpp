//Vishal Yathish

#include "Garage.h"

namespace cs32
{

Garage::Garage( size_t capacity ): mCapacity(capacity)
{
    //Assigns a default, empty Deque object to the attribute variable mDeque
    mDeque = Deque<std::string>();
}

//Function inserts an object into the garage; adds an element to the front of the mDeque linked list. If the mDeque has reached its set capacity, then it deletes the last element of the list -- the one used least -- to make space for the new object. Returns true if this deletion has to occur. Returns false otherwise.
bool Garage::tossIn( std::string s )
{
    bool output = false;
    
    //Checks if the number of elements in the list has reached the upper bound/capacity
    if (size() < mCapacity)
        mDeque.addToFront(s);
    else
    {
        mDeque.deleteRear();
        mDeque.addToFront(s);
        output = true;
    }
    return( output );
}

//Deletes an object with a specific name/element from the linked list; calls the deleteItem() function from mDeque, since the Type is std::string, and the element of each node is its name.
bool Garage::tossOut( std::string s )
{
    return( mDeque.deleteItem(s) );
}

//Function tries to find an object in the linked list. If it can be found, it is used and brought to the front of the linked list. The function returns true. If it cannot be found, the function returns false.
bool Garage::use( std::string s )
{
    bool output = false;
    if (find(s))
    {
        mDeque.deleteItem(s);
        mDeque.addToFront(s);
        output = true;
    }
    return( output );
}

//Function checks if object can be found in the linked list; iterates through all indices of the list, using the get function to extract the element of each node. Checks if the element is equal to the given string parameter. If the parameter can be found in the list, returns true. If not, returns false.
bool Garage::find( std::string s )
{
    bool output = false;
    for (int i = 0; i < size(); i++)
    {
        std::string currVal;
        mDeque.get(i, currVal);
        
        if (currVal == s)
        {
            output = true;
            break;
        }
    }
    return( output );
}

//Function returns the capacity of the linked list; can be found in the variable mCapacity
size_t Garage::capacity()
{
    return( mCapacity );
}
//Function returns the number of elements currently in the linked list; calls the size() function written in mDeque
size_t Garage::size( )
{
    return(mDeque.size());
}

//Prints the items from the linked list; calls mDeque's printItems() method, and adds a description/title for additional context.
std::string Garage::printItems( )
{
    std:: string output = "Items in Garage: " + mDeque.printItems();
    return(output);
}

}
