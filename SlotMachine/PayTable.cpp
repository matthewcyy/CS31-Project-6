//
//  PayTable.cpp
//  SlotMachine
//
//

#include "PayTable.h"


PayTable::PayTable( char wheel1, char wheel2, char wheel3 )
{
    mWheel1 = wheel1;
    mWheel2 = wheel2;
    mWheel3 = wheel3;
}

PayTable::Multiplier PayTable::calculateMultiplier( )
{ // Order in which I set the multiplier is important
    // For now...
    Multiplier result = ZERO;
    if ( mWheel1 == 'A' || mWheel2 == 'A' || mWheel3 == 'A' )
    {
        result = ONETIME; // Checking for single A first. Should be first because other multipliers rely on A, such as having 2 of them or having a straight. So, I am having this first. If this were last, and there was a straight multiplier calculation before it, this would mess things up.
    }
    if ( mWheel1 == mWheel2 || mWheel1 == mWheel3 || mWheel2 == mWheel3 )
    {
        result = THREETIME;
        if ( mWheel1 == 'A' || mWheel2 == 'A' || mWheel3 == 'A' )
        {
            result = FOURTIME;
        }
    }
    if ( (mWheel1 == 'A' && mWheel2 == 'A') || (mWheel1 == 'A' && mWheel3 == 'A') || (mWheel2 == 'A' && mWheel3 == 'A') )
    {
        result = FIVETIME;
    }
    if ( mWheel1 == mWheel2 && mWheel2 == mWheel3 )
    {
        result = SEVENTIME; // If 3 of a kind, and one of them is an 'A', then it should change to 10 from 7 times
        if ( mWheel3 == 'A' )
        {
            result = TENTIME;
        }
    }
    if ( mWheel1 == 'Q' && mWheel2 == 'K' && mWheel3 == 'A'  )
    {
        result = FIVETIME;
    }
    if ( mWheel1 == 'Q' && mWheel2 == 'A' && mWheel3 == 'K'  )
    {
        result = FIVETIME;
    }
    if ( mWheel1 == 'K' && mWheel2 == 'A' && mWheel3 == 'Q'  )
    {
        result = FIVETIME;
    }
    if ( mWheel1 == 'K' && mWheel2 == 'Q' && mWheel3 == 'A'  )
    {
        result = FIVETIME;
    }
    if ( mWheel1 == 'A' && mWheel2 == 'K' && mWheel3 == 'Q'  )
    {
        result = FIVETIME;
    }
    if ( mWheel1 == 'A' && mWheel2 == 'Q' && mWheel3 == 'K'  )
    {
        result = FIVETIME; // Just going through all the possible straights
    }
    return( result );
}

void PayTable::manageWager( Bank & bank )
{
    // for the wager, adjust the Bank balance based on the pay multiplier
    double amount = bank.getWager();
    Multiplier multiplier = calculateMultiplier();
    int numMult;
    switch (multiplier)
    {
        case ZERO:
            numMult = 0;
            break;
        case ONETIME:
            numMult = 1;
            break;
        case TWOTIME:
            numMult = 2;
            break;
        case THREETIME:
            numMult = 3;
            break;
        case FOURTIME:
            numMult = 4;
            break;
        case FIVETIME:
            numMult = 5;
            break;
        case SIXTIME:
            numMult = 6;
            break;
        case SEVENTIME:
            numMult = 7;
            break;
        case TENTIME:
            numMult = 10;
            break;
    }
    bank.win( amount*numMult );
    
    if ( numMult == 0 )
    {
        bank.lose( amount );
    }
}


