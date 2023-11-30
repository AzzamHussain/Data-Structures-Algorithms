#include <iostream>
using namespace std;

const int arraySize = 50; // Define the size of the array

int main() {
    int array[arraySize]; // Create an array to store values

    // Initialize the array with values
    for (int i = 0; i < arraySize; i++) {
        array[i] = i + 1; // You can initialize the values as needed
    }

    // Allow the user to search for a specific index
    int num;
    cout << "Enter index to search: ";
    cin >> num;

    if (num >= 0 && num < arraySize) {
        cout << "Index: " << num << "\t" << "Value: " << array[num] << endl;
    } else {
        cout << "Invalid index. Please enter an index within the range [0, " << arraySize - 1 << "]." << endl;
    }
    return 0;
}
