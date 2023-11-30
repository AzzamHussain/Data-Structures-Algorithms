#include <cstdlib>
#include <string>

using namespace std;

int stringToNum(string numericString) 
{
    int intValue = stoi(numericString);
    return intValue;
}

// #include <string>
// #include <cstdlib>

// int stringToNum(std::string numericString)
// {
//     // Convert the string to an integer using std::stoi
//     int num = std::stoi(numericString);
//     return num;
// }
