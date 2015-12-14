//
//  main.cpp
//  AdventOfCode12
//
//  Created by Jeroen Sack on 13/12/15.
//  Copyright © 2015 Jeroen Sack. All rights reserved.
//

#include <iostream>

FILE* file;

int parseObject();

int parseArray()
{
    char abc;
    char number[6];
    int count = 0;
    int total = 0;
    while(fread(&abc, 1, 1, file) && abc != ']')
    {
        if(abc == '[')
        {
            total += parseArray();
        }
        if(abc == '{')
        {
            total += parseObject();
        }
        if(abc == '-' || isdigit(abc))
        {
            number[count] = abc;
            number[count+1] = '\0';
            count++;
        }
        else
        {
            total += atoi(number);
            count = 0;
            number[count] = '\0';
        }
    }
    total += atoi(number);
    printf("add total array %d\n", total);
    return total;
}

int parseObject()
{
    char abc;
    char number[6];
    int count = 0;
    int total = 0;
    char *redString = "red";
    int red = 0;
    bool containsRed = false;
    while(fread(&abc, 1, 1, file) && abc != '}')
    {
        if(abc == redString[red])
        {
            red++;
            if(red == 3)
            {
                containsRed = true;
            }
        }
        else
        {
            red = 0;
        }
        
        if(abc == '[')
        {
            total += parseArray();
        }
        
        if(abc == '{')
        {
            total += parseObject();
        }
        
        if(abc == '-' || isdigit(abc))
        {
            number[count] = abc;
            number[count+1] = '\0';
            count++;
        }
        else
        {
            total += atoi(number);
            count = 0;
            number[count] = '\0';
        }
    }
    if(containsRed)
    {
        printf("contains red\n");
        return 0;
    }
    else
    {
        total += atoi(number);
        printf("add total %d\n", total);
        return total;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    file = fopen("/Users/jeroensack/Downloads/input-8.txt", "r");
    char abc;
    char number[6];
    int count = 0;
    int total = 0;
    while(fread(&abc, 1, 1, file))
    {
        if(abc == '{')
        {
            total += parseObject();
        }
        if(abc == '[')
        {
            total += parseArray();
        }
        if(abc == '-' || isdigit(abc))
        {
            number[count] = abc;
            number[count+1] = '\0';
            count++;
        }
        else
        {
            total += atoi(number);
            count = 0;
            number[count] = '\0';
        }
    }
    
    printf("total %d\n", total);
    return 0;
}
