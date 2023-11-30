#include <iostream>
#include <cstdlib>

using namespace std;

int calculateDegree(int adjacencyMatrix[][10], int arrays, int vertex) {
    int degree = 0;

    if (vertex < 0 || vertex >= arrays) {
        cerr << "Invalid vertex index!" << endl;
        return -1;
    }

    for (int i = 0; i < arrays; ++i) {
        degree += adjacencyMatrix[vertex][i];
    }

    return degree;
}


int main()
{
    int arrays;
    cout << "Enter number of rows and columns: ";
    cin >> arrays;
    int adjacencyMatrix[10][10];
    for (int i = 0; i < arrays; ++i) {
        // Access columns of the array
        for (int j = 0; j < arrays; ++j) {
            bool validInput = false;
            int check;
            char rowLabel = 'A' + i;
            char columnLabel = 'A' + j;

            while (validInput == 0) {
                cout << "Enter element for cell [" << rowLabel << "][" << columnLabel << "]: ";
                cin >> check;

                if (check == 0 || check == 1) {
                    adjacencyMatrix[i][j] = check;
                    validInput = true;  // Set validInput to true to exit the loop
                } else {
                    cerr << "INVALID INPUT!! Please enter 0 or 1." << endl;
                }
            }
        }
    }

    for (int i = 0; i < arrays; ++i) {

        // access columns of the array
        for (int j = 0; j < arrays; ++j) {
            char rowLabel = 'A' + i;
            char columnLabel = 'A' + j;
            cout << "Cell [" << rowLabel << "][" << columnLabel << "] = " << adjacencyMatrix[i][j] << endl;
        }
    }
    int vertexToCalculateDegree = 'A';
    int degree = calculateDegree(adjacencyMatrix, arrays, vertexToCalculateDegree);

    if (degree != -1) {
        cout << "Degree of vertex A is: " << degree << endl;
    
    return 0;
    }
}