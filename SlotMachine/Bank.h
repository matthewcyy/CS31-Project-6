//
//  Bank.hpp
//  SlotMachine
//
//

#ifndef Bank_h
#define Bank_h

// The purpose of this class is to implement a bank of funds and a wager than can be won or lost
class Bank
{
public:
    Bank( int amount = 0 );
    
    void win( int amount );
    void lose( int amount );
    
    void deposit( int amount );
    // trivial getter
    int balance() const;
    int cashOut( );
    bool canWager( int amount ) const;
    // trivial setter
    void setWager( int amount );
    // trivial getter
    int getWager() const;
    
private:
    int bankAmount;  // the current bank balance
    int wager;       // what is currently being wagered in this round of play
    
};


#endif
