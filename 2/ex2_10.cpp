#include <iostream>
#include <string>
std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_str;
    std::cout << "global_str: "<< global_str << std::endl;
    std::cout << "local_int: " << local_int << std::endl;
    std::cout << "local_str: "<< local_str << std::endl;
    std::cout << "global_int: "<< global_int << std::endl;
    return 0;
}

/*
-output

global_str: 
local_int: 22057
local_str: 
global_int: 0
*/

