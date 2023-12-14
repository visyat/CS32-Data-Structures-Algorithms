//Vishal Yathish

#ifndef DEQUENODE_CPP
#define DEQUENODE_CPP

#include "DequeNode.h"
using namespace std;

namespace cs32 {

template <typename Type>
DequeNode<Type>::DequeNode( const Type& v,
                      DequeNode * node,
                      DequeNode * pre )//: value(v), next(node), previous(pre)
{
    value = v;
    next = node;
    previous = pre;
}

//Getter method for value private variable
template <typename Type>
Type DequeNode<Type>::getElement() const {
	return( value );
}

//Getter and setter method for pointer to next node in deque; returns nullptr when it is the last node
template <typename Type>
DequeNode<Type> * DequeNode<Type>::getNext() const 
{
    DequeNode<Type> *nextNode = next;
	return( nextNode );
}
template <typename Type>
void DequeNode<Type>::setNext( DequeNode<Type> * node ) 
{
    next = node;
}

//Getter and setter method for pointer to previous node in deque; returns nullptr when it is the first node in deque
template <typename Type>
DequeNode<Type> * DequeNode<Type>::getPrevious() const 
{
    DequeNode<Type> *prevNode = previous;
    return( prevNode );
}
template <typename Type>
void DequeNode<Type>::setPrevious( DequeNode<Type> * node ) {
    previous = node;
}

}

#endif
