//
//  Bank.cpp
//  SlotMachine
//
//

#include "Bank.h"


// The purpose of this class is to implement a bank of funds and a wager than can be won or lost
Bank::Bank( int amount )
{
    bankAmount = amount;
    wager = 0;
}
    
void Bank::win( int amount )
{
    bankAmount += amount;
    wager = 0;
    // add to the balance and set the wager to zero
}
    
void Bank::lose( int amount )
{
    bankAmount -= amount;
    wager = 0;
    // subtract from the balance and set the wager to zero
}

void Bank::deposit( int amount )
{
    bankAmount += amount;
    // add to the balance
}
 
// trivial getter
int Bank::balance() const
{
    return( bankAmount );
}
    
int Bank::cashOut( )
{
    int cashedOut(0);
    cashedOut = bankAmount;
    wager = 0;
    bankAmount = 0;
    // return the balance
    // set both the wager and the balance to zero
    // for now...
    return( cashedOut );
}

// **TODO: can the amount be wagered??
bool Bank::canWager( int amount ) const
{
    bool result(true);
    if ( amount > bankAmount )
    {
        result = false;
    }
    // can the bank balance allow this amount to be wagered??
    // for now...
    return( result );
}
    
// trivial setter
void Bank::setWager( int amount )
{
    wager = amount;
}
 
// trivial getter
int Bank::getWager() const
{
    return( wager );
}
