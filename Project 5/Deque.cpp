//Vishal Yathish

#ifndef DEQUE_CPP
#define DEQUE_CPP

#include "Deque.h"
#include <string>
#include <sstream>

using namespace std;

namespace cs32 {

template <typename Type>
Deque<Type>::Deque()//: head(nullptr), tail(nullptr)
{
    head = nullptr;
    tail = nullptr;
}

//Copy constructor Deque object; very similar to copy constructor linked list, except have to set previous nodes for each element while incrementing
template <typename Type>
Deque<Type>::Deque( const Deque& rhs ) {
    if (rhs.head == nullptr)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = new DequeNode<Type>( rhs.head->getElement() );
        tail = head;
        DequeNode<Type> *q = head;
        DequeNode<Type> *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new DequeNode<Type>( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            q->getNext()->setPrevious( q );
            tail = q->getNext();
            p = p->getNext();
            q = q->getNext();
        }
    }
}

//Destructor for Deque object; calls the makeEmpty() function to safely delete all pointers
template <typename Type>
Deque<Type>::~Deque() {
	makeEmpty();
}

//Checks if the Deque is empty, or has no elements in the linked list; simply checks if the head is empty or is assigned to a node. If yes, then returns true. If not, then it returns false.
template <typename Type>
bool Deque<Type>::isEmpty() const {
    bool output = false;
    if (head == nullptr)
        output = true;
    return( output );
}

//Clears the Deque, deleting every pointer in the linked list; while the linked list is not empty (has a head), walks the head pointer and deletes the item at the front. Repeats until the list is empty.
template <typename Type>
void Deque<Type>::makeEmpty() 
{
    while (head != nullptr)
    {
        DequeNode<Type> *curr = head;
        head = head -> getNext();
        delete (curr);
    }
    tail = nullptr;
}

//Adds an input Type value as a node to the front of the list; if the list is empty, then it simply sets the head and tail to be that node. If the list is not empty, it assigns the new front node as the previous of the old front node, and the old front to be the new node's next value. Head is reassigned to the new front.
template <typename Type>
void Deque<Type>::addToFront( const Type & data )
{
    DequeNode<Type> *frontNode = new DequeNode<Type>(data);
    if (isEmpty())
    {
        head = frontNode;
        tail = frontNode;
    }
    else
    {
        frontNode -> setNext(head);
        head -> setPrevious(frontNode);
        head = frontNode;
    }
    
}
template <typename Type>
void Deque<Type>::addToRear( const Type & data )
{
    DequeNode<Type> *backNode = new DequeNode<Type>(data);
    if (isEmpty())
        addToFront(data);
    else
    {
        backNode -> setPrevious(tail);
        tail -> setNext(backNode);
        tail = backNode;
    }
}

//Adds an input Type value as a node to the back of the list. If the list is empty, it acts exactly like addToFront(). If it is not, then the new node is set as the next node to the current tail; the current tail is set as the previous of the new node. Tail is then walked one node next.


//Deletes the front node from the linked list. If the list is empty, then this method should do nothing. If the list has only one element, then it should render the list empty (can use the makeEmpty() function from before). Otherwise, it should walk the head pointer by one node; it should set the current head's previous to nullptr, and delete the old front node.
template <typename Type>
void Deque<Type>::deleteFront( )
{
    if (!isEmpty())
    {
        if (size() == 1)
            makeEmpty();
        else
        {
            DequeNode<Type> *frontNode = head;
            head = head -> getNext();
            head -> setPrevious(nullptr);
            delete(frontNode);
        }
    }
}
template <typename Type>
void Deque<Type>::deleteRear( )
{
    if (!isEmpty())
    {
        if (size() == 1)
            makeEmpty();
        else
        {
            DequeNode<Type> *backNode = tail;
            tail = tail -> getPrevious();
            tail -> setNext(nullptr);
            delete (backNode);
        }
    }
}

//Traverses the linked list, looking for a particular element. If it is in the list, the function deletes this node, and returns true. If not, it returns false.
template <typename Type>
bool Deque<Type>::deleteItem( const Type & data )
{
    bool output = false;
    
    //If the list is empty, then this function should simply return false, since the element data cannot be found in the list.
    if (!isEmpty())
    {
        //Special cases if the given element is either at the front or the back of the linked list.
        if (front() == data)
        {
            deleteFront();
            output = true;
        }
        else if (rear() == data)
        {
            deleteRear();
            output = true; 
        }
        
        //Otherwise, traverses the entire linked list to find the given element
        else
        {
            DequeNode<Type> *currNode = head;
            while (currNode != nullptr)
            {
                if (currNode ->getElement() == data)
                {
                    //Connects the two nodes on either side of the current node
                    currNode -> getNext() -> setPrevious(currNode -> getPrevious());
                    currNode -> getPrevious() -> setNext(currNode -> getNext());
                    
                    //Deletes the current node pointer; would not be able to walk the pointer if we want to continue searching for other occurences of the element data. Not the case for this function, since we break after this anyways
                    delete (currNode);
                    
                    output = true;
                    break;
                }
                currNode = currNode -> getNext();
            }
        }
    }
        
    return output;
}

//deleteItem(), but deletes all duplicates
//iterative traversal ...
template <typename Type>
bool Deque<Type>::deleteAllItemsIterative 
 ( const Type & data )
{
    bool output = false;
    
    DequeNode<Type> * curr = head;
    while (curr != nullptr)
    {
        if (curr -> getElement() == data)
        {
            if (curr == head)
            {
                deleteFront();
                output = true;
            }
            else if (curr == tail)
            {
                deleteRear();
                output = true;
            }
            else
            {
                curr -> getNext() -> 
                    setPrevious (curr -> getPrevious());
                curr -> getPrevious() -> 
                    setNext (curr -> getNext());
                DequeNode<Type> *temp = curr;
                curr = curr->getNext();
                delete(temp);
                
                output = true;
            }
        }
        else
            curr = curr->getNext();
    }
    return output;
}

//recursive traversal ...
template <typename Type>
bool Deque<Type>::deleteAllItemsRecursive ( const Type & data)
{
    bool output = false;
    
    size_t sizeBeforeDeletion = size();
    deleteAllItemsRecursive(data, head);
    size_t sizeAfterDeletion = size();
    
    if (sizeBeforeDeletion != sizeAfterDeletion)
        output = true;
    
    return output;
}
template <typename Type>
void Deque<Type>::deleteAllItemsRecursive 
 ( const Type & data, DequeNode<Type>* currNode)
{
    if (currNode == nullptr)
    {
    }
    else
    {
        if (currNode -> getElement() == data)
        {
            if (currNode == head)
                deleteFront();
            else if (currNode == tail)
                deleteRear();
            else
            {
                currNode -> getNext() 
                    -> setPrevious(currNode -> getPrevious());
                currNode -> getPrevious() 
                    -> setNext(currNode -> getNext());
                
                DequeNode<Type> * temp = currNode;
                currNode = currNode -> getNext();
                delete(temp);
            }
        }
        else
            currNode = currNode->getNext();
        deleteAllItemsRecursive(data, currNode);
    }
}

//Functions return the elements of head and tail respectively if the linked list is non-empty. If it is empty, it returns the default value of the class Type -- assumes that for all objects Type, there is a default, no argument constructor.
template <typename Type>
Type Deque<Type>::front( ) const
{
    Type output = Type();
    if (!isEmpty())
        output = head -> getElement();
    return output;
}
template <typename Type>
Type Deque<Type>::rear( ) const
{
    Type output = Type();
    if (!isEmpty())
        output = tail -> getElement();
    return output;
}

//Deletes the rear node from the linked list. If the list is empty, then this method should do nothing. If the list has only one element, then it should render the list empty (can use the makeEmpty() function from before). Otherwise, it should walk back the tail pointer by one node; it should set the current tail's next to nullptr, and delete the old rear node.


// Howard is supplying code to convert a Type to a string using its operator <<
template <typename Type>
std::string Deque<Type>::to_string( const Type & value ) const
{
    stringstream s;
    // call the Type's operator <<
    s << value;
    return( s.str() );
}

//Returns a string representation of all the objects in the linked list, using the Type->string conversion method provided to us above. Iterates through all nodes in the linked list, and adds the string representation of each element to our output string, with a separator comma and space for easy reading in output.
template <typename Type>
std::string Deque<Type>::printItems( ) const
{
    DequeNode<Type> *currNode = head;
    std::string output = "";
    
    while (currNode != nullptr)
    {
        output += to_string(currNode -> getElement()) + ", ";
        currNode = currNode -> getNext();
    }
    return output;
}


// Deep copy of linked list
template <typename Type>
const Deque<Type> & Deque<Type>::operator =( const Deque<Type> & rhs ) {
    if (this != &rhs)
    {
        makeEmpty();
        
        DequeNode<Type> *right = rhs.head;
        while (right != nullptr)
        {
            addToRear(right->getElement());
            right = right -> getNext();
        }
    }
	return( *this );
}

//Function that returns the size/number of elements of the linked list. Iterates once through the linked list, and increments a counter for each element.
template <typename Type>
size_t Deque<Type>::size() const
{
    DequeNode<Type> *currNode = head;
    size_t output = 0;
    while (currNode != nullptr)
    {
        output++;
        currNode = currNode -> getNext();
    }
    return output;
}

//Function that goes to a given index of the linked list, and copies its element into the given Type parameter "data." Iterates through the list w/ a while loop, incrementing a counter to keep track of index. If the counter reaches the index before we hit the end of the linked list, it assigns the element of the current node to data and breaks the loop. The function returns true if we were able to do this successfully. Returns false if not, such as if the given index was not present in the linked list.
template <typename Type>
bool  Deque<Type>::get( int i, Type & data ) const
{
    int counter = 0;
    DequeNode<Type> *currNode = head;
    bool output = false;
    
    while (currNode != nullptr)
    {
        if (counter == i)
        {
            data = currNode -> getElement();
            output = true;
            break;
        }
        counter++;
        currNode = currNode -> getNext();
    }
    
    return output;
}

}


#endif
