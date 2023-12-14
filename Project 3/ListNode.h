#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>
#include <string>

namespace cs32 {

class ListNode {
public:
	ListNode( std::string data = "", ListNode * node = nullptr );
	bool nextIsNull() const;

	std::string getElement() const;
	ListNode* getNext() const;
	void setNext( ListNode * node );
    
    //created a method to set the value of the ListNode during runtime
    //void setElement(std:: string data);

private:
	std::string    value;
	ListNode* next;

};

}
#endif
