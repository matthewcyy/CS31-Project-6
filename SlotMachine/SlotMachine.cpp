//
//  SlotMachine.cpp
//  SlotMachine
//
//


#include <cstdlib>
#include <iostream>
#include <string>
#include "SlotMachine.h"
#include "RandomNumber.h"
#include "Bank.h"
#include "PayTable.h"
#include "RewardsCard.h"


SlotMachine::SlotMachine( std::string seq )
{
    wheel1 = ' ';
    wheel2 = ' ';
    wheel3 = ' ';
    sequence = seq;
    display = true;
    //playsBeforeWins = 0;
}

void SlotMachine::play( Bank & bank, char w1, char w2, char w3 )  // cheating
{
    wheel1 = w1;
    wheel2 = w2;
    wheel3 = w3;
    
    if (display)
    {
        spinWheels();
    }
    
    //card.calculateRewards( bank );
    
    
    updateBankFromSpinAndDisplay( bank );
}

void SlotMachine::play( Bank & bank )
{
    RandomNumber spin (0, sequence.length()-1);
    wheel1 = sequence.at(spin.random());
    wheel2 = sequence.at(spin.random());
    wheel3 = sequence.at(spin.random());
    
    if ( display )
    {
        spinWheels();
    }
    
    /*if ( playsBeforeWins == 50 )
    {
        wheel1 = 'A';
        wheel2 = 'A';
        wheel3 = 'A';   
    }
     */
    
    updateBankFromSpinAndDisplay( bank );

}

// spin the wheels
void SlotMachine::spinWheels( )
{
    // Draw the machine
    if (display)
    {
        Screen screen;
        screen.displayScreen(wheel1, wheel2, wheel3, sequence);
    }
}

// show the wager after one round of play
void SlotMachine::displayWager( int wager, int before, int after )
{
    // Show the wager information
    if (display)
    {
        Screen screen;
        screen.displayWager( wager, before, after );
    }
}

// update the bank for one round of play
void SlotMachine::updateBankFromSpinAndDisplay( Bank & b )
{
    int balanceBefore = b.balance();
    int wager = b.getWager( );
    
    PayTable p( wheel1, wheel2, wheel3 );
    p.manageWager( b );
    
    int balanceAfter = b.balance();
    
    /*
    if ( balanceBefore < balanceAfter )
    {
        playsBeforeWins++;
    }
     */
    // Display the wager lines
    displayWager( wager, balanceBefore, balanceAfter );
}

// trivial getter
char SlotMachine::getWheel1() const
{
    return( wheel1 );
}

// trivial getter
char SlotMachine::getWheel2() const
{
    return( wheel2 );
}

// trivial getter
char SlotMachine::getWheel3() const
{
    return( wheel3 );
}

void SlotMachine::showDisplay()
{
    display = true;
}

void SlotMachine::noDisplay()
{
    display = false;
}

/* int SlotMachine::getPlaysBeforewins() const
{
    int p = playsBeforeWins;
    return (p);
}
 */
