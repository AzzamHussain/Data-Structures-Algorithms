#include <iostream>
#include <cstdlib>

using namespace std;

int array[20];
int main()
{
    int i = 0;
    array[2] = 1;
    for (int arrayElement : array)
    {
        cout << "Value of element: " << i << " is " << arrayElement << endl;
        i++;
    } 
}