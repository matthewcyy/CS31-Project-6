//
//  RewardsCard.cpp
//  SlotMachine
//
//  Created by Matthew Yoshida on 8/11/20.
//  Copyright © 2020 Howard Stahl. All rights reserved.
//

#include <stdio.h>
#include "RewardsCard.h"
#include "Bank.h"

RewardsCard::RewardsCard()
{
    bonusRewards = 0;
}

void RewardsCard::calculateRewards( Bank b )
{
    bonusRewards += 0.01 * b.getWager();
}
