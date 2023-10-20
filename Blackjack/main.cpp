//
//  main.cpp
//  Blackjack 
//
// Vishal Yathish
// COM SCI 32

#include <iostream>
#include <cassert>
#include "Enums.h"
#include "Card.h"
#include "Hand.h"

using namespace std;
using namespace cs32;

int main() {
    Card c;
    
    //All cards, with alternating suits; are not relevant and are not called
    Card ace( Suit::HEARTS, Face::ACE );
    Card two( Suit::CLUBS, Face::DEUCE );
    Card three( Suit::SPADES, Face::THREE );
    Card four( Suit::DIAMONDS, Face::FOUR );
    Card five( Suit::HEARTS, Face::FIVE );
    Card six( Suit::CLUBS, Face::SIX );
    Card seven( Suit::SPADES, Face::SEVEN );
    Card eight( Suit::DIAMONDS, Face::EIGHT );
    Card nine( Suit::HEARTS, Face::NINE );
    Card ten( Suit::CLUBS, Face::TEN );
    Card jack( Suit::SPADES, Face::JACK );
    Card queen( Suit::DIAMONDS, Face::QUEEN );
    Card king( Suit::HEARTS, Face::KING );
   
    Hand h1( two, six );
    assert( h1.evaluateHand(two) == Choice::HIT );
    assert( h1.evaluateHand(three) == Choice::HIT );
    assert( h1.evaluateHand(four) == Choice::HIT );
    assert( h1.evaluateHand(five) == Choice::HIT );
    assert( h1.evaluateHand(six) == Choice::HIT );
    assert( h1.evaluateHand(seven) == Choice::HIT );
    assert( h1.evaluateHand(eight) == Choice::HIT );
    assert( h1.evaluateHand(nine) == Choice::HIT );
    assert( h1.evaluateHand(ten) == Choice::HIT );
    assert( h1.evaluateHand(jack) == Choice::HIT );
    assert( h1.evaluateHand(queen) == Choice::HIT );
    assert( h1.evaluateHand(king) == Choice::HIT );
    assert( h1.evaluateHand(ace) == Choice::HIT );
    
    Hand h2( six, ace );
    assert( h2.evaluateHand(two) == Choice::HIT );
    assert( h2.evaluateHand(three) == Choice::DOUBLEHIT );
    assert( h2.evaluateHand(four) == Choice::DOUBLEHIT );
    assert( h2.evaluateHand(five) == Choice::DOUBLEHIT );
    assert( h2.evaluateHand(six) == Choice::DOUBLEHIT );
    assert( h2.evaluateHand(seven) == Choice::HIT );
    assert( h2.evaluateHand(eight) == Choice::HIT );
    assert( h2.evaluateHand(nine) == Choice::HIT );
    assert( h2.evaluateHand(ten) == Choice::HIT );
    assert( h2.evaluateHand(jack) == Choice::HIT );
    assert( h2.evaluateHand(queen) == Choice::HIT );
    assert( h2.evaluateHand(king) == Choice::HIT );
    assert( h2.evaluateHand(ace) == Choice::HIT );
    
    Hand h3( jack, king );
    assert( h3.evaluateHand(two) == Choice::STAND );
    assert( h3.evaluateHand(three) == Choice::STAND );
    assert( h3.evaluateHand(four) == Choice::STAND );
    assert( h3.evaluateHand(five) == Choice::STAND );
    assert( h3.evaluateHand(six) == Choice::STAND );
    assert( h3.evaluateHand(seven) == Choice::STAND );
    assert( h3.evaluateHand(eight) == Choice::STAND );
    assert( h3.evaluateHand(nine) == Choice::STAND );
    assert( h3.evaluateHand(ten) == Choice::STAND );
    assert( h3.evaluateHand(jack) == Choice::STAND );
    assert( h3.evaluateHand(queen) == Choice::STAND );
    assert( h3.evaluateHand(king) == Choice::STAND );
    assert( h3.evaluateHand(ace) == Choice::STAND );
    
    Hand h4( ace, king );
    assert( h4.evaluateHand(two) == Choice::STAND );
    assert( h4.evaluateHand(three) == Choice::STAND );
    assert( h4.evaluateHand(four) == Choice::STAND );
    assert( h4.evaluateHand(five) == Choice::STAND );
    assert( h4.evaluateHand(six) == Choice::STAND );
    assert( h4.evaluateHand(seven) == Choice::STAND );
    assert( h4.evaluateHand(eight) == Choice::STAND );
    assert( h4.evaluateHand(nine) == Choice::STAND );
    assert( h4.evaluateHand(ten) == Choice::STAND );
    assert( h4.evaluateHand(jack) == Choice::STAND );
    assert( h4.evaluateHand(queen) == Choice::STAND );
    assert( h4.evaluateHand(king) == Choice::STAND );
    assert( h4.evaluateHand(ace) == Choice::STAND );
    
    cout << "All test passed!" << endl;
    return( 0 );
}
