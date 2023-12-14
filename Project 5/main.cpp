//Vishal Yathish
// Menu.cpp : Defines the entry point for the console application.

#include <iostream>
#include <string>
#include <cassert>
#include "Deque.h"
#include "Deque.cpp"
#include "DequeNode.h"
#include "DequeNode.cpp"
#include "Garage.h"

int main()
{
    using namespace std;
    using namespace cs32;
    /*
    // TODO: CS 32 students should add testing code here
    DequeNode< int > sampleNode( 5 );
    Deque< string > sampleDeque;
    Deque< int > otherDeque;
    Garage g;
    Garage otherg( 12 );*/
    
    // Deque Tests
    /*
    Deque< int > dInt;
    int x;

    dInt.deleteFront( );
    dInt.deleteRear( );
    x = 12;
    assert( dInt.deleteItem( x ) == false );
    assert( dInt.size( ) == 0 );
    assert( dInt.get( -10, x ) == false );
    assert( dInt.isEmpty( )  );*/
    
    Deque< std::string > dString1;
    std::string s;
    std::string s1;
    std::string s2;

    s1 = "Hello";
    dString1.addToFront( s1 );
    s2 = "World!";
    dString1.addToRear( s2 );
    
    Deque< std::string > dString = Deque<std::string>();
    
    dString.addToRear("F");
    dString.addToRear("R");
    dString.addToRear("O");
    dString.addToRear("L");
    dString.addToRear("I");
    dString.addToRear("C");
    dString.addToRear("K");
    dString.addToRear("I");
    dString.addToRear("N");
    dString.addToRear("G");
    
    cout << dString.printItems() << endl;
    
    //dString.deleteAllItemsIterative("I");
    dString.deleteAllItemsRecursive("I");
    
    cout << dString.printItems() << endl;
    
    /*
    s = "Howard";
    //cout << dString.printItems() << endl; //Hello -> World!
    assert( dString.deleteItem( s ) == false );
    assert( dString.size( ) == 2 );
    assert( dString.get( -10, s ) == false );
    assert( dString.isEmpty( ) == false );
    assert( dString.get( 0, s ) && s == "Hello" );
    assert( dString.get( 1, s ) && s == "World!" );
    dString.deleteFront( );
    
    //cout << dString.printItems() << endl;
    s = "Hello";
    assert( dString.deleteItem( s ) == false );
    assert( dString.size( ) == 1 );
    assert( dString.get( 0, s ) && s == "World!" );
    assert( dString.isEmpty( ) == false );
    
    dString.deleteRear( );
    s = "World!";
    assert( dString.deleteItem( s ) == false );
    
    assert( dString.size( ) == 0 );
    assert( dString.get( 0, s ) == false );
    assert( dString.isEmpty( ) );
    
    // Garage Tests
    Garage g;
    Garage gSix( 6 );
    assert( g.size( ) == 0 );
    assert( g.capacity( ) == 10 );
    
    assert( gSix.size( ) == 0 );
    assert( gSix.capacity( ) == 6 );
    gSix.tossIn( "shoes" );
    gSix.tossIn( "shirts" );
    gSix.tossIn( "books" );
    assert( gSix.size( ) == 3 );
    assert( gSix.capacity( ) == 6 );
    gSix.tossIn( "suitcases" );
    assert( gSix.tossIn( "tables" ) == false );  // nothing thrown away
    assert( gSix.tossIn( "chairs" ) == false );  // nothing thrown away
    assert( gSix.size( ) == 6 );
    assert( gSix.capacity( ) == 6 );
    assert( gSix.find( "shoes" ) );
    assert( gSix.find( "shirts" ) );
    assert( gSix.find( "books" ) );
    assert( gSix.find( "suitcases" ) );
    assert( gSix.find( "tables" ) );
    assert( gSix.find( "chairs" ) );
    
    cout << gSix.printItems() << endl;
    
    assert( gSix.tossIn( "boxes" ) );  // shoes thrown away...
    assert( gSix.size( ) == 6 );
    assert( gSix.capacity( ) == 6 );
    assert( gSix.find( "boxes" ) );
    //cout << gSix.printItems() << endl;
    assert( gSix.find( "shoes" )  == false );
    assert( gSix.find( "shirts" ) );
    assert( gSix.find( "books" ) );
    //cout << gSix.printItems() << endl;
    assert( gSix.find( "suitcases" ) );
    assert( gSix.find( "tables" ) );
    assert( gSix.find( "chairs" ) );
    assert( gSix.tossOut( "shoes" ) == false );   // shoes not found...
    assert( gSix.use( "shoes" ) == false );       // shoes not found...
    
    cout << gSix.printItems() << endl;
    assert( gSix.use( "tables" ) );
    
    cout << gSix.printItems() << endl;
    assert( gSix.tossIn( "records" ) );     // shirts thrown away...
    assert( gSix.size( ) == 6 );
    assert( gSix.capacity( ) == 6 );
    assert( gSix.find( "records" ) );
    assert( gSix.find( "tables" ) );
    assert( gSix.find( "boxes" ) );
    assert( gSix.find( "shoes" ) == false );
    assert( gSix.find( "shirts" ) == false );
    assert( gSix.find( "books" ) );
    assert( gSix.find( "suitcases" ) );
    
    cout << gSix.printItems() << endl;
    assert( gSix.tossOut( "books" ) );
    assert( gSix.tossOut( "records" ) );
    assert( gSix.tossOut( "shoes" ) == false);
    
    cout << gSix.printItems() << endl;
    assert( gSix.size( ) == 4 );
    assert( gSix.capacity( ) == 6 );
    assert( gSix.find( "records" ) == false );
    assert( gSix.find( "tables" ) );
    assert( gSix.find( "chairs" ) );
    assert( gSix.find( "boxes" ) );
    assert( gSix.find( "shoes" ) == false );
    assert( gSix.find( "shirts" ) == false );
    assert( gSix.find( "books" ) == false );
    assert( gSix.find( "suitcases" ) );

    cout << gSix.printItems() << endl;
    assert( gSix.tossOut( "tables" ) );
    assert( gSix.tossOut( "boxes" ) );
    assert( gSix.tossOut( "suitcases" ) );
    
    cout << gSix.printItems() << endl;
    assert( gSix.size( ) == 1 );
    assert( gSix.capacity( ) == 6 );
    assert( gSix.find( "records" ) == false );
    assert( gSix.find( "tables" ) == false );
    assert( gSix.find( "boxes" ) == false );
    assert( gSix.find( "shoes" ) == false );
    assert( gSix.find( "shirts" ) == false );
    assert( gSix.find( "books" ) == false );
    assert( gSix.find( "suitcases" ) == false );
    assert( gSix.find( "chairs" ) );
    */
    cout << "all tests passed!" << endl;
    
    return( 0 );
}
