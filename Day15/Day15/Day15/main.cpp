//
//  main.cpp
//  Day15
//
//  Created by Jeroen Sack on 20/12/15.
//  Copyright © 2015 Jeroen Sack. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <string>
#include <cstdio>

#define PART_ONE 0

int main(int argc, const char * argv[]) {
    std::ifstream fileStream("/Users/jeroensack/Downloads/input-13.txt", std::ios_base::in);
    int dataArray[4][5];
    int i = 0;
    while(!fileStream.eof())
    {
        std::string line;
        std::getline(fileStream, line);
        sscanf(line.c_str(), "%*s capacity %d, durability %d, flavor %d, texture %d, calories %d",&dataArray[i][0],&dataArray[i][1],&dataArray[i][2],&dataArray[i][3],&dataArray[i][4]);
        i++;
    }
    int maxTotal = 0;
    for(int i = 0; i <= 100; i++)
    {
        for(int j=0; j <= 100; j++)
        {
            for(int k = 0; k <= 100; k++)
            {
                for(int l = 0; l <= 100; l++)
                {
                    if((i + j + k + l) == 100)
                    {
                        int capacity   = (dataArray[0][0] * i) + (dataArray[1][0] * j) + (dataArray[2][0] * k) + (dataArray[3][0] * l);
                        int durability = (dataArray[0][1] * i) + (dataArray[1][1] * j) + (dataArray[2][1] * k) + (dataArray[3][1] * l);
                        int flavor     = (dataArray[0][2] * i) + (dataArray[1][2] * j) + (dataArray[2][2] * k) + (dataArray[3][2] * l);
                        int texture    = (dataArray[0][3] * i) + (dataArray[1][3] * j) + (dataArray[2][3] * k) + (dataArray[3][3] * l);
                        int calory     = (dataArray[0][4] * i) + (dataArray[1][4] * j) + (dataArray[2][4] * k) + (dataArray[3][4] * l);
                        if(calory == 500 || PART_ONE)
                        {
                            int total = 0;
                            if(capacity < 0 || durability < 0 || flavor < 0 || texture < 0)
                            {
                                total = 0;
                            }
                            else
                            {
                                total = capacity * durability * flavor * texture;
                            }
                            
                            if(maxTotal <= total)
                            {
                                maxTotal = total;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("max = %d\n", maxTotal);
    return 0;
}
