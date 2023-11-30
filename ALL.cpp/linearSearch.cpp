#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int toFind) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == toFind) {
            return i;
        }
    }
    return -1; 
}

int main() {
    int arr[] = {2, 4, 6, 8, 16, 10, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int toFind = 16;

    int result = linearSearch(arr, n, toFind);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array" << endl;
    }

    return 0;
}
