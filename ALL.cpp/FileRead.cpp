#include <fstream>
#include<iostream>
using namespace std;
int main() {
   //initialie the array size
   int arr[30];
   ifstream is("TestCase_01.txt");
   int cnt= 0;
   int x;
   // check that array is not already full
   while (cnt < arr[30] && is >> x)
   // and read integer from file
   arr[cnt++] = x;
   // print the integers stored in the array
   cout<<"The integers are:"<<"\n";
   for (int i = 0; i < cnt; i++) {
      cout << arr[i] <<' ';
   }
   //close the file
   is.close();
}