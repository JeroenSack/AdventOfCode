//
//  main.cpp
//  Day17
//
//  Created by Jeroen Sack on 21/12/15.
//  Copyright © 2015 Jeroen Sack. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
#include <math.h>

int main(int argc, const char * argv[]) {
    std::vector<unsigned int> list;
    std::vector<unsigned int> numberOfContainersList;
    int count = 0;
    
    
    std::ifstream fileStream("/Users/jeroensack/Downloads/input-15.txt", std::ios_base::in);
    std::string line;
    while(!fileStream.eof())
    {
        std::getline(fileStream, line);
        if(!fileStream.eof())
        {
            list.push_back(std::stoi(line));
        }
    }
    
    size_t numberOfIter = pow(2,list.size());
    for(size_t i = 0; i < numberOfIter; i++)
    {
        std::bitset<20> useItemOrNot(i);
        int total = 0;
        int numberOfContainers = 0;
        for(int j = 0; j < list.size(); j++)
        {
            if(useItemOrNot[j])
            {
                numberOfContainers++;
                total += list[j];
            }
            else
            {
                continue;
            }
        }
        
        if(total == 150)
        {
            count++;
            numberOfContainersList.push_back(numberOfContainers);
        }
    }
    
    std::sort(numberOfContainersList.begin(),numberOfContainersList.end());
    int i = 0;
    while(numberOfContainersList[i] == numberOfContainersList[i+1])
    {
        i++;
    }
    i++;
    printf("%d\n",count);
    printf("%d\n",i);
    return 0;
}
