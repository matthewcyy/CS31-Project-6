//
//  RewardsCard.h
//  SlotMachine
//
//  Created by Matthew Yoshida on 8/11/20.
//  Copyright © 2020 Howard Stahl. All rights reserved.
//
#include "Bank.h"

#ifndef RewardsCard_h
#define RewardsCard_h

class RewardsCard
{
private:
    double bonusRewards;
public:
    RewardsCard();
    void calculateRewards( Bank b );
};

#endif /* RewardsCard_h */
