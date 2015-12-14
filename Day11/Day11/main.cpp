//
//  main.cpp
//  AdventOfCode11
//
//  Created by Jeroen Sack on 12/12/15.
//  Copyright © 2015 Jeroen Sack. All rights reserved.
//

#include <iostream>

bool validPassword(char *password)
{
    bool valid1 = false;
    bool valid2 = true;
    int countDouble = 0;
    char alreadyUsed = 0xFF;
    for(int i = 0; i < strlen(password); i++)
    {
        if(i < strlen(password) - 2 && (password[i] + 2 == password[i+1] + 1 && password[i+1] + 1 == password[i+2]))
        {
            valid1 = true;
        }
        switch(password[i])
        {
            case 'i':
            case 'o':
            case 'l':
                valid2 = false;
                break;
        }
        if(password[i] == password[i+1] && i != alreadyUsed)
        {
            alreadyUsed = i+1;
            countDouble++;
        }
    }
    
    return valid1 && valid2 && (countDouble >= 2);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char password[9] = "hxbxxzaa";
    bool done = false;
    while(!done)
    {
        for(int i = 7; i; i--)
        {
            if(password[i] != 'z')
            {
                password[i] += 1;
                break;
            }
            else
            {
                password[i] = 'a';
            }
        }
        done = validPassword(password);
    }
    printf("%s" , password);
    return 0;
}
