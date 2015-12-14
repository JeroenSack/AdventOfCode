//
//  main.cpp
//  AdventOfCode14
//
//  Created by Jeroen Sack on 14/12/15.
//  Copyright © 2015 Jeroen Sack. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdio>

struct Reindeer
{
    int speed;
    int flyTime;
    int rest;
    int distance;
    int timeCounter;
    bool flying;
    int score;
};

int main(int argc, const char * argv[])
{
    std::ifstream fileStream("/Users/jeroensack/Downloads/input-11.txt", std::ios_base::in);
    std::vector<Reindeer> reindeers;
    while (!fileStream.eof())
    {
        std::string line;
        std::getline(fileStream,line);
        Reindeer reindeer;
        
        sscanf(line.c_str(),
               "%*s can fly %d km/s for %d seconds, but then must rest for %d seconds.",
               &reindeer.speed,
               &reindeer.flyTime,
               &reindeer.rest);
        reindeer.distance = 0;
        reindeer.timeCounter = 0;
        reindeer.flying = true;
        reindeers.push_back(reindeer);
    }
    
    for(int i = 0; i < 2503; i++)
    {
        for(auto& reindeer : reindeers)
        {
            if(reindeer.flying)
            {
                reindeer.distance += reindeer.speed;
                if(++reindeer.timeCounter >= reindeer.flyTime)
                {
                    reindeer.timeCounter = 0;
                    reindeer.flying = false;
                }
            }
            else
            {
                if(++reindeer.timeCounter >= reindeer.rest)
                {
                    reindeer.timeCounter = 0;
                    reindeer.flying = true;
                }
            }
        }
        
        int maxDistance = 0;
        for(auto &reindeer : reindeers)
        {
            if(reindeer.distance >= maxDistance)
            {
                maxDistance = reindeer.distance;
            }
        }
        
        for(auto &reindeer : reindeers)
        {
            if(reindeer.distance == maxDistance)
            {
                reindeer.score++;
            }
        }
    }
    
    int maxScore = 0;
    int maxDistance = 0;
    for(auto &reindeer : reindeers)
    {
        if(maxScore < reindeer.score)
        {
            maxScore = reindeer.score;
        }
        
        if(maxDistance < reindeer.distance)
        {
            maxDistance = reindeer.distance;
        }
    }
    
    printf("maxDistance = %d\n", maxDistance);
    printf("maxScore = %d\n", maxScore);
    return 0;
}
