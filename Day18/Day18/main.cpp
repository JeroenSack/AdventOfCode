//
//  main.cpp
//  Day18
//
//  Created by Jeroen Sack on 21/12/15.
//  Copyright © 2015 Jeroen Sack. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

#define SIZE_X 100
#define SIZE_Y 100

#define PART2

char lightmap[SIZE_Y + 2][SIZE_X + 3];
char targetmap[SIZE_Y + 2][SIZE_X + 3];

void printMap()
{
    for(int i = 0; i < SIZE_Y + 2; i++)
    {
        for(int j = 0; j < SIZE_X + 2; j++)
        {
            putchar(lightmap[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

int getOnNeighbors(int x, int y)
{
    int count = 0;
    for(int i = x - 1; i <= x + 1; i++)
    {
        for(int j = y - 1; j <= y + 1; j++)
        {
            if(lightmap[i][j] == '#' && (i != x || j != y))
            {
                count++;
            }
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    std::ifstream fileStream("/Users/jeroensack/Downloads/input-16.txt", std::ios_base::in);
    std::string line;
    int i = 0;
    
    memset(lightmap[i],'@',SIZE_Y + 2);
    i++;
    
    while(!fileStream.eof())
    {
        std::getline(fileStream, line);
        if(!fileStream.eof())
        {
            sprintf(lightmap[i], "@%s@",line.c_str());
            i++;
        }
    }
    memset(lightmap[i],'@',SIZE_Y + 2);
    
#ifdef PART2
    lightmap[1][1] = '#';
    lightmap[1][100] = '#';
    lightmap[100][1] = '#';
    lightmap[100][100] = '#';
#endif
    
    printMap();
    for(int x = 0; x < 100; x++)
    {
        for(int i = 0; i < SIZE_Y + 2; i++)
        {
            for(int j = 0; j < SIZE_X + 2; j++)
            {
                int onCount = getOnNeighbors(i,j);
                if(lightmap[i][j] == '#')
                {
                    if(onCount != 2 && onCount != 3)
                    {
                        targetmap[i][j] = '.';
                    }
                    else
                    {
                        targetmap[i][j] = '#';
                    }
                }
                if(lightmap[i][j] == '.')
                {
                    if(onCount == 3)
                    {
                        targetmap[i][j] = '#';
                    }
                    else
                    {
                        targetmap[i][j] = '.';
                    }
                }
                if(lightmap[i][j] == '@')
                {
                    targetmap[i][j] = '@';
                }
            }
        }
        memcpy(lightmap,targetmap,sizeof(targetmap));
#ifdef PART2
        lightmap[1][1] = '#';
        lightmap[1][100] = '#';
        lightmap[100][1] = '#';
        lightmap[100][100] = '#';
#endif
        printMap();
    }
    
    int count = 0;
    for(int i = 0; i < SIZE_Y + 2; i++)
    {
        for(int j = 0; j < SIZE_X + 2; j++)
        {
            if(lightmap[i][j] == '#')
            {
                count++;
            }
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}
