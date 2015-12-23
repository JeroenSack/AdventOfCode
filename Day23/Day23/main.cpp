//
//  main.cpp
//  Day23
//
//  Created by Jeroen Sack on 23/12/15.
//  Copyright © 2015 Jeroen Sack. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <fstream>

#define PART_TWO

std::vector<std::string> codeList;
std::map<std::string, long long> variables;

int main(int argc, const char * argv[]) {
    std::ifstream fileStream("/Users/jeroensack/Downloads/input-18.txt", std::ios_base::in);
    std::string line;
    
    while(!fileStream.eof())
    {
        std::getline(fileStream, line);
        if(!fileStream.eof())
        {
            codeList.push_back(line);
        }
    }
    
    int lineNumber = 0;
#ifdef PART_TWO
    variables["a"] = 1;
#else
    variables["a"] = 0;
#endif
    variables["b"] = 0;
    while(lineNumber < codeList.size())
    {
        printf("var a %d b %d line %d\n", variables["a"], variables["b"], lineNumber);
        std::string line = codeList[lineNumber];
        std::string task = line.substr(0,3);
        if(task == "hlf")
        {
            std::string varName = line.substr(4,1);
            variables[varName] = variables[varName] / 2;
            lineNumber++;
        }
        else if(task == "tpl")
        {
            std::string varName = line.substr(4,1);
            variables[varName] = variables[varName] * 3;
            lineNumber++;
        }
        else if(task == "inc")
        {
            std::string varName = line.substr(4,1);
            variables[varName] = variables[varName] + 1;
            lineNumber++;
        }
        else if(task == "jmp")
        {
            int offset;
            sscanf(line.c_str(), "jmp %d",&offset);
            lineNumber += offset;
        }
        else if(task == "jie")
        {
            int offset;
            std::string varName = line.substr(4,1);
            sscanf(line.c_str(), "jie %*s %d", &offset);
            
            if(variables[varName] % 2 == 0)
            {
                lineNumber += offset;
            }
            else
            {
                lineNumber++;
            }
        }
        else if(task == "jio")
        {
            int offset;
            std::string varName = line.substr(4,1);
            sscanf(line.c_str(), "jio %*s %d", &offset);
            
            if(variables[varName] == 1)
            {
                lineNumber += offset;
            }
            else
            {
                lineNumber++;
            }
        }
    }
    return 0;
}
