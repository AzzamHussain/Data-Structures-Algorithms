#include <iostream>

using namespace std;

struct Edge;

struct Vertex {
    char vertexName;
    Edge* edgeList;
    bool visited;

    Vertex(char name) : vertexName(name), edgeList(nullptr), visited(false) {}
};

struct Edge {
    Vertex* toVertex;
    Edge* nextEdge;

    Edge(Vertex* to) : toVertex(to), nextEdge(nullptr) {}
};

void addNeighbor(Vertex* vertex, Vertex* neighbor) {
    Edge* newEdge = new Edge(neighbor);
    newEdge->nextEdge = vertex->edgeList;
    vertex->edgeList = newEdge;
}

// Custom array-based data structures for paths and visited vertices
const int len = 50; // Adjust as needed
Vertex* path[len];
int pathLength = 0;
bool visitedVertices[len]; // Assumes a limited number of vertices

// Modified DFS function to find the path between fromVertex and toVertex
bool findPath(Vertex* fromVertex, Vertex* toVertex) {
    // Initialize the pathLength
    pathLength = 0;

    // Create a custom stack to track the DFS traversal
    Vertex* stack[len]; // Assumes a limited number of vertices
    int top = -1;

    // Initialize the visited vertices array
    for (int i = 0; i < len; ++i) {
        visitedVertices[i] = false;
    }

    // Push the starting vertex onto the stack
    stack[++top] = fromVertex;

    // Custom array to store the parent of each vertex
    Vertex* parents[len];

    while (top >= 0) {
        Vertex* current = stack[top--];

        if (current == toVertex) {
            // Build the path by backtracking from the destination to the source
            Vertex* node = toVertex;
            while (node != fromVertex) {
                path[pathLength++] = node;
                node = parents[node->vertexName]; // Use the character as an index
            }
            path[pathLength++] = fromVertex;
            return true;
        }

        if (!visitedVertices[current->vertexName]) {
            visitedVertices[current->vertexName] = true;

            Edge* edge = current->edgeList;
            while (edge) {
                if (!visitedVertices[edge->toVertex->vertexName]) {
                    parents[edge->toVertex->vertexName] = current;
                    stack[++top] = edge->toVertex;
                }
                edge = edge->nextEdge;
            }
        }
    }

    // If no path is found, set pathLength to 0
    pathLength = 0;
    return false;
}

int main() {
    // Create vertices
    Vertex* A = new Vertex('A');
    Vertex* B = new Vertex('B');
    Vertex* C = new Vertex('C');
    Vertex* D = new Vertex('D');
    Vertex* E = new Vertex('E');

    // Define the graph's edges by adding neighbors
    addNeighbor(A, B);
    addNeighbor(A, C);
    addNeighbor(B, D);

    // char startVertex;
    // cout<< "Enter the starting vertex";
    // cin>>startVertex;
    // char endVertex;
    // cout <<"Enter the ending vertex";
    // cin >>endVertex;
    // Find and print the path from vertex A to vertex E
    if (findPath(C, D)) {
        cout << "Path from C to D: ";
        for (int i = 0; i < pathLength; ++i) {
            cout << path[i]->vertexName << " ";
        }
        cout << endl;
    } else {
        cout << "No path found from C to D." << endl;
    }

    // Clean up memory
    delete A;
    delete B;
    delete C;
    delete D;
    delete E;

    return 0;
}
