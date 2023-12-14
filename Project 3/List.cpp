#include "List.h"

using namespace std;

namespace cs32 {

List::List() {
	head = nullptr;
}

List::List( const List& rhs ) {
    if (rhs.head == nullptr) head = nullptr;
    else {
        head = new ListNode( rhs.head->getElement() );
        ListNode *q = head;
        ListNode *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new ListNode( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            p = p->getNext( );
            q = q->getNext( );
        }
    }
}

List::~List() {
	makeEmpty();
}

bool List::isEmpty() const {
	return( head == nullptr );
}

void List::makeEmpty() {
	while (!isEmpty()) {
        deleteItem( head->getElement( ) );
	}
}

void List::addToFront( const std::string & data )
{
    ListNode * newnode = new ListNode( data );
    newnode->setNext( head );
    head = newnode;
}

void List::addToRear( const std::string & data )
{
    if (head == nullptr)
    {
        addToFront( data );
    }
    else
    {
        ListNode * node = head;
        while( node->getNext() != nullptr )
        {
            node = node->getNext();
        }
        ListNode * newnode = new ListNode( data );
        newnode->setNext( nullptr );
        node->setNext( newnode );
    }
}

void List::deleteItem( const std::string & data )
{
    ListNode * node = head;
    ListNode * priornode = nullptr;

    while( node != nullptr )
    {
        if (node->getElement() == data)
        {
            if (priornode != nullptr)
                priornode->setNext( node->getNext( ) );
            else
                head = node->getNext();
            delete( node );
            node = nullptr;
            break;
        }
        priornode = node;
        node = node->getNext();
    }
}

bool List::findItem( const std::string & data )
{
    bool result = false;
    ListNode * node = head;
    while( node != nullptr )
    {
        if (node->getElement() == data)
        {
            result = true;
            break;
        }
        node = node->getNext();
    }
    return( result );
}

std::string List::printItems( )
{
    string s = "";
    if (isEmpty())
    {
        s += "---> empty list";
    }
    else
    {
        s += "head:";
        ListNode * node = head;
        while( node != nullptr )
        {
            s += " -> ";
            s += node->getElement();
            node = node->getNext();
        }
        s += " -> nullptr ";
    }
    return( s );
}


// Deep copy of linked list
const List& List::operator =( const List& rhs ) {
	if (this != &rhs) {
		makeEmpty();

        ListNode * right = rhs.head;

		while( right != nullptr )
        {
            addToRear( right->getElement() );
            right = right->getNext();
		}
	}

	return( *this );
}

//return the number of total data values found on the List
size_t List::size() const
{
    size_t output = 0;
    
    if (!isEmpty())
    {
        ListNode * node = head;
        while (node != nullptr)
        {
            output++;
            node = node->getNext();
        }
    }
    return output;
}

//Counting from zero (like an array index), return the location of the first occurrence of data found in the List.  If the data occurs multiple times on the List, you should return the location of the first occurrence.  If the data is not found, return minus one.
int List::position(const std::string& data ) const
{
    int output = -1;
    int counter = 0;
    
    ListNode * node = head;
    while (node != nullptr)
    {
        if (node->getElement() == data)
        {
            output = counter;
            break;
        }
        counter++;
        node = node->getNext();
    }
    
    return output;
}

//If the before value is found on List at a position less than the after value, return true; otherwise, return false.
bool List::before( const std::string& before, const std::string& after ) const
{
    bool output = false;
    if (position(before) != -1 && position(after) != -1)
    {
        if (position(before) < position(after))
            output = true;
    }
    return output;
}

//Sets the value of the parameter data to be the element located at position i of the List (if that position exists) and return true if the position exists; otherwise, return false.
bool List::get( int i, std::string& data ) const
{
    bool output = false;
    
    int counter = 0;
    ListNode *node = head;
    
    while (node != nullptr)
    {
        if (counter == i)
        {
            output = true;
            data = node -> getElement();
            break;
        }
        
        counter++;
        node = node -> getNext();
    }
    return output;
}

//Returns the smallest item on the list.  If the list is empty, the empty string should be returned.
std::string List::min() const
{
    std:: string output = "";
    if (!isEmpty())
    {
        ListNode *node = head;
        output = node -> getElement();
        
        while (node != nullptr)
        {
            if (node -> getElement() < output)
                output = node -> getElement();
            node = node -> getNext();
        }
        
    }
    
    return output;
}

//Alters the list by removing all the items bigger than data that were originally on the list.
void List::removeAllBiggerThan(const std::string & data )
{
    ListNode *node = head;
    
    while (node != nullptr)
    {
        std::string currentValue = node->getElement();
        if (currentValue > data)
        {
            //cout << "REGISTERS:" << currentValue << endl;
            ListNode *temp = node->getNext();
            deleteItem(currentValue);
            node = temp;
        }
        else
            node = node -> getNext();
    }
}

}


