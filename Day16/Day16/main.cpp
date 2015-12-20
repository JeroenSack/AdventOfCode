//
//  main.cpp
//  Day16
//
//  Created by Jeroen Sack on 20/12/15.
//  Copyright © 2015 Jeroen Sack. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <map>

struct value
{
    char name[20];
    int count;
};

#define PART_TWO

int main(int argc, const char * argv[]) {
    std::map<std::string, int> auntSue;
    
    auntSue["children"] = 3;
    auntSue["cats"] = 7;
    auntSue["samoyeds"] = 2;
    auntSue["pomeranians"] = 3;
    auntSue["akitas"] = 0;
    auntSue["vizslas"] = 0;
    auntSue["goldfish"] = 5;
    auntSue["trees"] = 3;
    auntSue["cars"] = 2;
    auntSue["perfumes"] = 1;
    
    std::ifstream fileStream("/Users/jeroensack/Downloads/input-14.txt", std::ios_base::in);
    std::string line;
    while(!fileStream.eof())
    {
        std::getline(fileStream, line);
        line.erase(std::remove(line.begin(), line.end(), ':'), line.end());
        int number = 0;
        value values[3];
        sscanf(line.c_str(), "Sue %d %s %d, %s %d, %s %d", &number, values[0].name, &values[0].count, values[1].name, &values[1].count, values[2].name, &values[2].count);
        
        bool possible = true;
        
        for(int i = 0; i < 3; i++)
        {
            if(auntSue.find(values[i].name) != auntSue.end())
            {
#ifdef PART_TWO
                if(strcmp(values[i].name, "cats") == 0 || strcmp(values[i].name, "trees") == 0)
                {
                    if(auntSue[values[i].name] >= values[i].count)
                    {
                        possible = false;
                    }
                }
                else if(strcmp(values[i].name, "pomeranians") == 0 || strcmp(values[i].name, "goldfish") == 0)
                {
                    if(auntSue[values[i].name] <= values[i].count)
                    {
                        possible = false;
                    }
                }
                else
#endif
                {
                    if(auntSue[values[i].name] != values[i].count)
                    {
                        possible = false;
                    }
                }
            }
        }
        if(possible)
        {
            printf("%d\n", number);
        }
    }
    
    return 0;
}
