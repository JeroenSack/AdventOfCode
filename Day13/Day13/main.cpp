//
//  main.cpp
//  AdventOfCode13
//
//  Created by Jeroen Sack on 13/12/15.
//  Copyright © 2015 Jeroen Sack. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>

std::vector<std::string> visitors;
std::map<std::string, std::map<std::string, int> > happinessMap;
std::vector<int> final;


std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

void addIfNotThere(std::string input)
{
    if(std::find(visitors.begin(),visitors.end(),input) == visitors.end())
    {
        visitors.push_back(input);
    }
}

void putPerson(std::string name, std::vector<std::string> seatedVisitors)
{
    seatedVisitors.push_back(name);
    for(auto visitor : visitors)
    {
        if(std::find(seatedVisitors.begin(), seatedVisitors.end(), visitor) == seatedVisitors.end())
        {
            //havent been here, so lets go
            putPerson(visitor, seatedVisitors);
        }
        else if(seatedVisitors.size() == visitors.size())
        {
            //done, so add it to final
            int total = 0;
            
            for(int i = 0; i < seatedVisitors.size();i++)
            {
                if(i == 0)
                {
                    total += happinessMap[seatedVisitors[i]][seatedVisitors[i+1]];
                    total += happinessMap[seatedVisitors[i]][seatedVisitors[seatedVisitors.size()-1]];
                }
                else if(i == seatedVisitors.size()-1)
                {
                    total += happinessMap[seatedVisitors[i]][seatedVisitors[0]];
                    total += happinessMap[seatedVisitors[i]][seatedVisitors[i-1]];
                }
                else
                {
                    total += happinessMap[seatedVisitors[i]][seatedVisitors[i+1]];
                    total += happinessMap[seatedVisitors[i]][seatedVisitors[i-1]];
                }
            }
            final.push_back(total);
        }
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::ifstream fileStream("/Users/jeroensack/Downloads/input-12.txt", std::ios_base::in);
    while(!fileStream.eof())
    {
        std::string line;
        std::vector<std::string> splitted;
        std::vector<std::string> splitted2;
        std::getline(fileStream,line);
        int amount;
        
        split(line, ' ', splitted);
        if(splitted.size() >= 11)
        {
            if(splitted[2].compare("lose") == 0)
            {
                amount = -1 * atoi(splitted[3].c_str());
            }
            else
            {
                amount = atoi(splitted[3].c_str());
            }
            
            
            
            std::string source = splitted[0];
            std::string target = split(splitted[10],'.',splitted2)[0];
            
            
            happinessMap[source][target] = amount;
            addIfNotThere(target);
            addIfNotThere(source);
        }
    }
    std::vector<std::string> emptyList;
    for(auto i : visitors)
    {
        putPerson(i, emptyList);
    }
    
    int min = 0;
    for(int j : final)
    {
        if(min < j)
        {
            min = j;
        }
    }
    
    printf("output %d\n", min);
    return 0;
}
