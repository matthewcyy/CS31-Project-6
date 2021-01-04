//
//  SlotMachine.hpp
//  SlotMachine
//
//

#ifndef SlotMachine_h
#define SlotMachine_h

#include "Bank.h"
#include "Screen.h"
#include "RewardsCard.h"
#include <string>

// The purpose of this class is to implement a SlotMachine game
class SlotMachine
{
public:
    SlotMachine( std::string seq="AKQJ9876" );
    
    void play( Bank & bank );

    void play( Bank & bank, char wheel1, char wheel2, char wheel3 );  // cheating...
    
    // trivial getters
    char getWheel1() const;
    char getWheel2() const;
    char getWheel3() const;
    
    void showDisplay();
    void noDisplay();
    int getPlaysBeforewins() const;

private:
    char        wheel1, wheel2, wheel3;    // the three wheels of this machine
    std::string sequence;                  // the total set of values to show when these wheels are spun
    bool        display;                   // is generated output desired for each round of play?
    
    // spin the wheels
    void spinWheels(  );
    // show the wager after one round of play
    void displayWager( int wager, int before, int after );
    // update the bank for one round of play
    void updateBankFromSpinAndDisplay( Bank & b );
    //int playsBeforeWins;
};


#endif
