// slotmachine.cpp

// Portions you are to complete are marked with a TODO: comment.
// We've provided some incorrect return statements (so indicated) just
// to allow this skeleton program to compile and run, albeit incorrectly.
// The first thing you probably want to do is implement the trivial
// functions (marked TRIVIAL).  
// As you finish implementing each TODO: item, remove its TODO: comment.

#include "SlotMachine.h"
#include "Bank.h"
#include "PayTable.h"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;



int main()
{
    Bank bank;
    SlotMachine s;
    
    Bank b;
    assert( b.balance() == 0 ); // starting balance should be 0
    assert( b.getWager() == 0 ); // starting wager should be 0
    assert( !b.canWager( 100 ) ); // can't wager more than balance
    b.deposit( 50 );
    assert( b.balance() == 50 ); // making sure deposit went through
    assert( !b.canWager( 100 ) ); // can't wager more than balance
    assert( b.canWager( 50 ) ); // can wager less than or equal to balance
    b.deposit( 50 );
    b.setWager(100);
    
    SlotMachine s2;
    s2.noDisplay();
    s2.play(b, '1', '2', '3');
    assert(b.balance() == 0); // checking to make sure properly loses wager on loss
    
    
    PayTable p( 'A', '1', 'A' );
    PayTable::Multiplier m = p.calculateMultiplier( );
    assert( m == PayTable::Multiplier::FIVETIME ); // checking to see if wheel1 and wheel3 as ace have right 5x multiplier
    PayTable p1( 'A', 'A', '1' );
    PayTable::Multiplier m1 = p1.calculateMultiplier( );
    assert( m1 == PayTable::Multiplier::FIVETIME ); // checking to see if wheel1 and wheel3 as ace have right 5x multiplier
    PayTable p2( '1', 'A', 'A' );
    PayTable::Multiplier m2 = p2.calculateMultiplier( );
    assert( m2 == PayTable::Multiplier::FIVETIME ); // checking to see if wheel1 and wheel3 as ace have right 5x multiplier
    PayTable a ( '1', '1', 'J' );
    PayTable::Multiplier am = a.calculateMultiplier( );
    assert ( am == PayTable::Multiplier::THREETIME ); // checking to make sure pair multiplier is correct
    PayTable a1 ( '1', 'J', 'J' );
    PayTable::Multiplier am1 = a1.calculateMultiplier( );
    assert ( am1 == PayTable::Multiplier::THREETIME );// checking to make sure pair multiplier is correct
    PayTable a2 ( 'J', '1', 'J' );
    PayTable::Multiplier am2 = a2.calculateMultiplier( );
    assert ( am2 == PayTable::Multiplier::THREETIME );// checking to make sure pair multiplier is correct
    PayTable four( 'A', '9', '8');
    PayTable::Multiplier fourm = four.calculateMultiplier();
    assert( fourm == PayTable::Multiplier::ONETIME ); // checking to make sure single ace multipiler is correct
    PayTable four1( '9', 'A', '8');
    PayTable::Multiplier fourm1 = four1.calculateMultiplier(); // checking to make sure single ace multipiler is correct
    assert( fourm1 == PayTable::Multiplier::ONETIME );
    PayTable four2( '9', '1', 'A');
    PayTable::Multiplier fourm2 = four2.calculateMultiplier();
    assert( fourm2 == PayTable::Multiplier::ONETIME ); // checking to make sure single ace multipiler is correct
    PayTable straight( 'Q', 'K', 'A');
    PayTable::Multiplier straightM = straight.calculateMultiplier();
    assert( straightM == PayTable::Multiplier::FIVETIME ); // checking to make sure straight multiplier is correct
    PayTable straight1( 'K', 'Q', 'A');
    PayTable::Multiplier straightM1 = straight1.calculateMultiplier();
    assert( straightM1 == PayTable::Multiplier::FIVETIME ); // checking to make sure straight multiplier is correct
    PayTable straight2( 'Q', 'A', 'K');
    PayTable::Multiplier straightM2 = straight2.calculateMultiplier();
    assert( straightM2 == PayTable::Multiplier::FIVETIME );// checking to make sure straight multiplier is correct
    PayTable straight3( 'K', 'A', 'Q');
    PayTable::Multiplier straightM3 = straight3.calculateMultiplier();
    assert( straightM3 == PayTable::Multiplier::FIVETIME );// checking to make sure straight multiplier is correct
    PayTable straight4( 'A', 'Q', 'K');
    PayTable::Multiplier straightM4 = straight4.calculateMultiplier();
    assert( straightM4 == PayTable::Multiplier::FIVETIME );// checking to make sure straight multiplier is correct
    PayTable straight5( 'A', 'K', 'Q');
    PayTable::Multiplier straightM5 = straight5.calculateMultiplier();
    assert( straightM5 == PayTable::Multiplier::FIVETIME );// checking to make sure straight multiplier is correct
    PayTable TOK('1', '1', '1');
    PayTable::Multiplier TOKm = TOK.calculateMultiplier();
    assert( TOKm == PayTable::Multiplier::SEVENTIME ); // checking to make sure three of a kind multiplier is 7
    PayTable pairA('1', '1', 'A');
    PayTable::Multiplier pairAm = pairA.calculateMultiplier();
    assert( pairAm == PayTable::Multiplier::FOURTIME); // checking to make sure pair plus ace multiplier is correct
  PayTable pair('1', '1', '2');
  PayTable::Multiplier pairm = pair.calculateMultiplier();
  assert( pairm == PayTable::Multiplier::THREETIME); // checking to make sure pair multiplier is correct
    
    
    
    Bank b1;
    b1.deposit( 100 );
    SlotMachine s1( "AKQJ987" ); // cheating...
    s1.noDisplay();
    b1.setWager( 100 );
    s1.play( b1, 'A', 'A', 'A' );
    assert( b1.balance( ) == 1100 ); // 3 Aces is 10-1 winner and a round of play adjusts the bank

    cerr << "all tests passed" << endl;
    
    using namespace std;
    do
    {
         cout << endl;
         cout << "Move (d#/b#/p/c/q): ";
         string action;
         string message;
         int amount;
         getline(cin,action);
         if (action.size() == 0)
         {
             return( 0 );
         }
         else
         {
             switch (action[0])
             {
                 default:   // if bad move, nothing happens
                     cout << '\a' << endl;  // beep
                     continue;
                 case 'q':
                     return( 0 );
                     break;
                     
                 case 'b':  // get
                     amount = atoi( action.substr(1).c_str() );
                     if (amount == 0)
                         amount = 1;
                     if (bank.canWager(amount))
                     {
                         bank.setWager(amount);
                         cout << "$" << amount << " Bet Accepted!" << endl;
                     }
                     else
                     {
                         cout << "Invalid Bet" << endl;
                     }
                     break;
                 case 'p':
                     if (bank.getWager() == 0)
                     {
                         cout << "You Must Bet First Before Playing" << endl;
                     }
                     else
                     {
                         s.play( bank );
                     }
                     break;
                 case 'd':
                     amount = atoi( action.substr(1).c_str() );
                     if (amount == 0)
                     {
                         cout << "Invalid Bank Deposit" << endl;
                     }
                     else
                     {
                         bank.deposit( amount );
                         cout << "$" << bank.balance() << " Available To Bet" << endl;
                     }
                     break;
                 case 'c':
                     amount = bank.cashOut();
                     cout << "$" << amount << " Returned To You!" << endl;
                     amount = 0;
                     break;
             }
         }
         
    } while ( true );
    
    
    return( 0 );
}

