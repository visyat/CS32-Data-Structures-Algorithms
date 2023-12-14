//Hand.cpp
#include "Hand.h"

namespace cs32
{

Hand::Hand(Card card1, Card card2): mCard1(card1), mCard2(card2) {}

Card Hand::getCard1() const { return( mCard1 ); }
Card Hand::getCard2() const { return( mCard2 ); }

// TODO Returns true when both of the Hand's cards have matching values
bool Hand::isPair() const
{
    if (mCard1.getFace() == mCard2.getFace())
        return true;
    return( false );
}

//TODO: Returns true when one or both of the Hand's cards are Aces
bool Hand::isSoft() const
{
    if (mCard1.getFace() == Face::ACE)
        return true;
    if (mCard2.getFace() == Face::ACE)
        return true;
    return( false );
}

//HELPER METHOD
int Hand::notAceCard() const
{
    if (mCard1.getFace() == Face::ACE)
        return mCard2.getValue();
    if (mCard2.getFace() == Face::ACE)
        return mCard1.getValue();
    return 0;
}


// TODO CS 32 students need to complete this operation
Choice Hand::evaluateHand( Card dealerCard ) const
{
    int dealerVal = dealerCard.getValue();
    // by default STAND
    Choice c = Choice::STAND;
    
    //all non-default options; strategy deck implemented
    //CASE 1: if the hand is soft, contains one or more Ace
    if (isSoft())
    {
        //CASE 1A: if the hand is 'AA'; is a pair of Aces
        if (isPair())
            c = Choice::SPLIT;
        
        //CASE 1B: if the hand is soft but not a pair
        else
        {
            int notAce = notAceCard();
            
            if (notAce == 2)
            {
                switch (dealerVal)
                {
                    case 1:
                        c = Choice::HIT;
                        break;
                    case 2:
                        c = Choice::HIT;
                        break;
                    case 3:
                        c = Choice::HIT;
                        break;
                    case 4:
                        c = Choice::HIT;
                        break;
                    case 5:
                        c = Choice::DOUBLEHIT;
                        break;
                    case 6:
                        c = Choice::DOUBLEHIT;
                        break;
                    case 7:
                        c = Choice::HIT;
                        break;
                    case 8:
                        c = Choice::HIT;
                        break;
                    case 9:
                        c = Choice::HIT;
                        break;
                    case 10:
                        c = Choice::HIT;
                        break;
                }
            }
            else if (notAce == 3)
            {
                switch (dealerVal)
                {
                    case 1:
                        c = Choice::HIT;
                        break;
                    case 2:
                        c = Choice::HIT;
                        break;
                    case 3:
                        c = Choice::HIT;
                        break;
                    case 4:
                        c = Choice::HIT;
                        break;
                    case 5:
                        c = Choice::DOUBLEHIT;
                        break;
                    case 6:
                        c = Choice::DOUBLEHIT;
                        break;
                    case 7:
                        c = Choice::HIT;
                        break;
                    case 8:
                        c = Choice::HIT;
                        break;
                    case 9:
                        c = Choice::HIT;
                        break;
                    case 10:
                        c = Choice::HIT;
                        break;
                }
            }
            else if (notAce == 4)
            {
                switch (dealerVal)
                {
                    case 1:
                        c = Choice::HIT;
                        break;
                    case 2:
                        c = Choice::HIT;
                        break;
                    case 3:
                        c = Choice::HIT;
                        break;
                    case 4:
                        c = Choice::DOUBLEHIT;
                        break;
                    case 5:
                        c = Choice::DOUBLEHIT;
                        break;
                    case 6:
                        c = Choice::DOUBLEHIT;
                        break;
                    case 7:
                        c = Choice::HIT;
                        break;
                    case 8:
                        c = Choice::HIT;
                        break;
                    case 9:
                        c = Choice::HIT;
                        break;
                    case 10:
                        c = Choice::HIT;
                        break;
                }
            }
            else if (notAce == 5)
            {
                switch (dealerVal)
                {
                    case 1:
                        c = Choice::HIT;
                        break;
                    case 2:
                        c = Choice::HIT;
                        break;
                    case 3:
                        c = Choice::HIT;
                        break;
                    case 4:
                        c = Choice::DOUBLEHIT;
                        break;
                    case 5:
                        c = Choice::DOUBLEHIT;
                        break;
                    case 6:
                        c = Choice::DOUBLEHIT;
                        break;
                    case 7:
                        c = Choice::HIT;
                        break;
                    case 8:
                        c = Choice::HIT;
                        break;
                    case 9:
                        c = Choice::HIT;
                        break;
                    case 10:
                        c = Choice::HIT;
                        break;
                }
            }
            else if (notAce == 6)
            {
                switch (dealerVal)
                {
                    case 1:
                        c = Choice::HIT;
                        break;
                    case 2:
                        c = Choice::HIT;
                        break;
                    case 3:
                        c = Choice::DOUBLEHIT;
                        break;
                    case 4:
                        c = Choice::DOUBLEHIT;
                        break;
                    case 5:
                        c = Choice::DOUBLEHIT;
                        break;
                    case 6:
                        c = Choice::DOUBLEHIT;
                        break;
                    case 7:
                        c = Choice::HIT;
                        break;
                    case 8:
                        c = Choice::HIT;
                        break;
                    case 9:
                        c = Choice::HIT;
                        break;
                    case 10:
                        c = Choice::HIT;
                        break;
                }
            }
            else if (notAce == 7)
            {
                switch (dealerVal)
                {
                    case 1:
                        c = Choice::HIT;
                        break;
                    case 2:
                        c = Choice::STAND;
                        break;
                    case 3:
                        c = Choice::DOUBLESTAND;
                        break;
                    case 4:
                        c = Choice::DOUBLESTAND;
                        break;
                    case 5:
                        c = Choice::DOUBLESTAND;
                        break;
                    case 6:
                        c = Choice::DOUBLESTAND;
                        break;
                    case 7:
                        c = Choice::STAND;
                        break;
                    case 8:
                        c = Choice::STAND;
                        break;
                    case 9:
                        c = Choice::HIT;
                        break;
                    case 10:
                        c = Choice::HIT;
                        break;
                }
            }
            else if (notAce == 8)
            {
                c = Choice::STAND;
            }
            else
            {
            }
        }
    }
    
    //CASE 2: if the hand is a pair, but contains no Aces
    else if (isPair())
    {
        int pairVal = mCard1.getValue();
        if (pairVal == 2)
        {
            switch (dealerVal)
            {
                case 1:
                    c = Choice::HIT;
                    break;
                case 2:
                    c = Choice::SPLITHIT;
                    break;
                case 3:
                    c = Choice::SPLITHIT;
                    break;
                case 4:
                    c = Choice::SPLIT;
                    break;
                case 5:
                    c = Choice::SPLIT;
                    break;
                case 6:
                    c = Choice::SPLIT;
                    break;
                case 7:
                    c = Choice::SPLIT;
                    break;
                case 8:
                    c = Choice::HIT;
                    break;
                case 9:
                    c = Choice::HIT;
                    break;
                case 10:
                    c = Choice::HIT;
                    break;
            }
        }
        else if (pairVal == 3)
        {
            switch (dealerVal)
            {
                case 1:
                    c = Choice::HIT;
                    break;
                case 2:
                    c = Choice::SPLITHIT;
                    break;
                case 3:
                    c = Choice::SPLITHIT;
                    break;
                case 4:
                    c = Choice::SPLIT;
                    break;
                case 5:
                    c = Choice::SPLIT;
                    break;
                case 6:
                    c = Choice::SPLIT;
                    break;
                case 7:
                    c = Choice::SPLIT;
                    break;
                case 8:
                    c = Choice::HIT;
                    break;
                case 9:
                    c = Choice::HIT;
                    break;
                case 10:
                    c = Choice::HIT;
                    break;
            }
        }
        else if (pairVal == 4)
        {
            switch (dealerVal)
            {
                case 1:
                    c = Choice::HIT;
                    break;
                case 2:
                    c = Choice::HIT;
                    break;
                case 3:
                    c = Choice::HIT;
                    break;
                case 4:
                    c = Choice::HIT;
                    break;
                case 5:
                    c = Choice::SPLITHIT;
                    break;
                case 6:
                    c = Choice::SPLITHIT;
                    break;
                case 7:
                    c = Choice::HIT;
                    break;
                case 8:
                    c = Choice::HIT;
                    break;
                case 9:
                    c = Choice::HIT;
                    break;
                case 10:
                    c = Choice::HIT;
                    break;
            }
        }
        else if (pairVal == 5)
        {
            switch (dealerVal)
            {
                case 1:
                    c = Choice::HIT;
                    break;
                case 2:
                    c = Choice::DOUBLEHIT;
                    break;
                case 3:
                    c = Choice::DOUBLEHIT;
                    break;
                case 4:
                    c = Choice::DOUBLEHIT;
                    break;
                case 5:
                    c = Choice::DOUBLEHIT;
                    break;
                case 6:
                    c = Choice::DOUBLEHIT;
                    break;
                case 7:
                    c = Choice::DOUBLEHIT;
                    break;
                case 8:
                    c = Choice::DOUBLEHIT;
                    break;
                case 9:
                    c = Choice::DOUBLEHIT;
                    break;
                case 10:
                    c = Choice::HIT;
                    break;
            }
        }
        else if (pairVal == 6)
        {
            switch (dealerVal)
            {
                case 1:
                    c = Choice::HIT;
                    break;
                case 2:
                    c = Choice::SPLITHIT;
                    break;
                case 3:
                    c = Choice::SPLIT;
                    break;
                case 4:
                    c = Choice::SPLIT;
                    break;
                case 5:
                    c = Choice::SPLIT;
                    break;
                case 6:
                    c = Choice::SPLIT;
                    break;
                case 7:
                    c = Choice::HIT;
                    break;
                case 8:
                    c = Choice::HIT;
                    break;
                case 9:
                    c = Choice::HIT;
                    break;
                case 10:
                    c = Choice::HIT;
                    break;
            }
        }
        else if (pairVal == 7)
        {
            switch (dealerVal)
            {
                case 1:
                    c = Choice::HIT;
                    break;
                case 2:
                    c = Choice::SPLIT;
                    break;
                case 3:
                    c = Choice::SPLIT;
                    break;
                case 4:
                    c = Choice::SPLIT;
                    break;
                case 5:
                    c = Choice::SPLIT;
                    break;
                case 6:
                    c = Choice::SPLIT;
                    break;
                case 7:
                    c = Choice::SPLIT;
                    break;
                case 8:
                    c = Choice::HIT;
                    break;
                case 9:
                    c = Choice::HIT;
                    break;
                case 10:
                    c = Choice::HIT;
                    break;
            }
        }
        else if (pairVal == 8)
        {
            c = Choice::SPLIT;
        }
        else if (pairVal == 9)
        {
            switch (dealerVal)
            {
                case 1:
                    c = Choice::STAND;
                    break;
                case 2:
                    c = Choice::SPLIT;
                    break;
                case 3:
                    c = Choice::SPLIT;
                    break;
                case 4:
                    c = Choice::SPLIT;
                    break;
                case 5:
                    c = Choice::SPLIT;
                    break;
                case 6:
                    c = Choice::SPLIT;
                    break;
                case 7:
                    c = Choice::STAND;
                    break;
                case 8:
                    c = Choice::SPLIT;
                    break;
                case 9:
                    c = Choice::SPLIT;
                    break;
                case 10:
                    c = Choice::STAND;
                    break;
            }
        }
        else if (pairVal == 10)
        {
            c = Choice::STAND;
        }
        else
        {
        }
    }
    
    //CASE 3: if the hand is neither a pair nor is soft
    else
    {
        int handTotal = mCard1.getValue() + mCard2.getValue();
        if (handTotal == 8)
        {
            c = Choice::HIT;
        }
        else if (handTotal == 9)
        {
            switch (dealerVal)
            {
                case 1:
                    c = Choice::HIT;
                    break;
                case 2:
                    c = Choice::HIT;
                    break;
                case 3:
                    c = Choice::DOUBLEHIT;
                    break;
                case 4:
                    c = Choice::DOUBLEHIT;
                    break;
                case 5:
                    c = Choice::DOUBLEHIT;
                    break;
                case 6:
                    c = Choice::DOUBLEHIT;
                    break;
                case 7:
                    c = Choice::HIT;
                    break;
                case 8:
                    c = Choice::HIT;
                    break;
                case 9:
                    c = Choice::HIT;
                    break;
                case 10:
                    c = Choice::HIT;
                    break;
            }
        }
        else if (handTotal == 10)
        {
            switch (dealerVal)
            {
                case 1:
                    c = Choice::HIT;
                    break;
                case 2:
                    c = Choice::DOUBLEHIT;
                    break;
                case 3:
                    c = Choice::DOUBLEHIT;
                    break;
                case 4:
                    c = Choice::DOUBLEHIT;
                    break;
                case 5:
                    c = Choice::DOUBLEHIT;
                    break;
                case 6:
                    c = Choice::DOUBLEHIT;
                    break;
                case 7:
                    c = Choice::DOUBLEHIT;
                    break;
                case 8:
                    c = Choice::DOUBLEHIT;
                    break;
                case 9:
                    c = Choice::DOUBLEHIT;
                    break;
                case 10:
                    c = Choice::HIT;
                    break;
            }
        }
        else if (handTotal == 11)
        {
            c = Choice::DOUBLEHIT;
        }
        else if (handTotal == 12)
        {
            switch (dealerVal)
            {
                case 1:
                    c = Choice::HIT;
                    break;
                case 2:
                    c = Choice::HIT;
                    break;
                case 3:
                    c = Choice::HIT;
                    break;
                case 4:
                    c = Choice::STAND;
                    break;
                case 5:
                    c = Choice::STAND;
                    break;
                case 6:
                    c = Choice::STAND;
                    break;
                case 7:
                    c = Choice::HIT;
                    break;
                case 8:
                    c = Choice::HIT;
                    break;
                case 9:
                    c = Choice::HIT;
                    break;
                case 10:
                    c = Choice::HIT;
                    break;
            }
        }
        else if (handTotal == 13)
        {
            switch (dealerVal)
            {
                case 1:
                    c = Choice::HIT;
                    break;
                case 2:
                    c = Choice::STAND;
                    break;
                case 3:
                    c = Choice::STAND;
                    break;
                case 4:
                    c = Choice::STAND;
                    break;
                case 5:
                    c = Choice::STAND;
                    break;
                case 6:
                    c = Choice::STAND;
                    break;
                case 7:
                    c = Choice::HIT;
                    break;
                case 8:
                    c = Choice::HIT;
                    break;
                case 9:
                    c = Choice::HIT;
                    break;
                case 10:
                    c = Choice::HIT;
                    break;
            }
        }
        else if (handTotal == 14)
        {
            switch (dealerVal)
            {
                case 1:
                    c = Choice::HIT;
                    break;
                case 2:
                    c = Choice::STAND;
                    break;
                case 3:
                    c = Choice::STAND;
                    break;
                case 4:
                    c = Choice::STAND;
                    break;
                case 5:
                    c = Choice::STAND;
                    break;
                case 6:
                    c = Choice::STAND;
                    break;
                case 7:
                    c = Choice::HIT;
                    break;
                case 8:
                    c = Choice::HIT;
                    break;
                case 9:
                    c = Choice::HIT;
                    break;
                case 10:
                    c = Choice::HIT;
                    break;
            }
        }
        else if (handTotal == 15)
        {
            switch (dealerVal)
            {
                case 1:
                    c = Choice::HIT;
                    break;
                case 2:
                    c = Choice::STAND;
                    break;
                case 3:
                    c = Choice::STAND;
                    break;
                case 4:
                    c = Choice::STAND;
                    break;
                case 5:
                    c = Choice::STAND;
                    break;
                case 6:
                    c = Choice::STAND;
                    break;
                case 7:
                    c = Choice::HIT;
                    break;
                case 8:
                    c = Choice::HIT;
                    break;
                case 9:
                    c = Choice::HIT;
                    break;
                case 10:
                    c = Choice::SURRENDERHIT;
                    break;
            }
        }
        else if (handTotal == 16)
        {
            switch (dealerVal)
            {
                case 1:
                    c = Choice::SURRENDERHIT;
                    break;
                case 2:
                    c = Choice::STAND;
                    break;
                case 3:
                    c = Choice::STAND;
                    break;
                case 4:
                    c = Choice::STAND;
                    break;
                case 5:
                    c = Choice::STAND;
                    break;
                case 6:
                    c = Choice::STAND;
                    break;
                case 7:
                    c = Choice::HIT;
                    break;
                case 8:
                    c = Choice::HIT;
                    break;
                case 9:
                    c = Choice::SURRENDERHIT;
                    break;
                case 10:
                    c = Choice::SURRENDERHIT;
                    break;
            }
        }
        else if (handTotal == 17)
        {
            c = Choice::STAND;
        }
        else
        {
        }
    }
    
    return( c );
}


}
