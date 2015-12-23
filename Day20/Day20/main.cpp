//
//  main.cpp
//  Day20
//
//  Created by Jeroen Sack on 23/12/15.
//  Copyright © 2015 Jeroen Sack. All rights reserved.
//

#include <iostream>
#include <vector>

#define PART_TWO

#ifdef PART_TWO
#define PRESENT_MULTIPLIER 11
#else
#define PRESENT_MULTIPLIER 10
#endif

#define TRY_NUMBER_OF_HOUSES 1000000

int main(int argc, const char * argv[]) {
    std::vector<unsigned long> amountOfPresents;
    amountOfPresents.resize(TRY_NUMBER_OF_HOUSES);
    
    for(int elfNumber = 1; elfNumber < TRY_NUMBER_OF_HOUSES; elfNumber++)
    {
        int houseNumber = elfNumber;
        unsigned int numberOfHousesDelivered = 0;
#ifdef PART_TWO
        while(houseNumber < TRY_NUMBER_OF_HOUSES && numberOfHousesDelivered < 50)
#else
        while(houseNumber < TRY_NUMBER_OF_HOUSES)
#endif
        {
            amountOfPresents[houseNumber] += elfNumber * PRESENT_MULTIPLIER;
            houseNumber += elfNumber;
            numberOfHousesDelivered++;
        }
    }
    
    for(int houseNumber = 1; houseNumber < TRY_NUMBER_OF_HOUSES; houseNumber++)
    {
        if(amountOfPresents[houseNumber] > 34000000)
        {
            printf("houseNumber %d [%lu]\n", houseNumber, amountOfPresents[houseNumber]);
            break;
        }
    }
    return 0;
}
