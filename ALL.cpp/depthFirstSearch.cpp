//Depth First Search by using Stack

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

struct vertexstack
{
    Vertex* vertex;
    vertexstack *next;
}; struct vertexstack *top = NULL;

void push(Vertex* vertex)
{
    vertexstack *temp = new vertexstack;
    temp->vertex = vertex;
    temp->next = top;
    top = temp;
}

void pop()
{
    if (top == NULL) {
        return;
    }
    vertexstack *temp = top;
    top = top->next;
    delete temp;
}

void addNeighbor(Vertex* vertex, Vertex* neighbor) {
    Edge* newEdge = new Edge(neighbor);
    newEdge->nextEdge = vertex->edgeList;
    vertex->edgeList = newEdge;
}

bool stackempty() {
    return top == NULL;
}

void DFS(Vertex* start) {
    push(start);

    while (!stackempty()) {
        Vertex* current = top->vertex;
        pop();

        if (!current->visited) {
            current->visited = true;
            cout << current->vertexName << " ";

            Edge* edge = current->edgeList;
            while (edge) {
                if (!edge->toVertex->visited) {
                    push(edge->toVertex);
                }
                edge = edge->nextEdge;
            }
        }
    }
}

int main() {
    // Creatig a new vertices
    Vertex* A = new Vertex('A');
    Vertex* C = new Vertex('C');
    Vertex* B = new Vertex('B');
    Vertex* D = new Vertex('D');
    Vertex* E = new Vertex('E');

    // Defining the graph's edges by adding neighbors
    addNeighbor(A, C);
    addNeighbor(A, B);
    addNeighbor(B, A);
    addNeighbor(B, D);
    addNeighbor(B, E);
    addNeighbor(C, A);

    // Perform DFS starting from vertex A
    cout << "DFS starting from vertex: ";
    DFS(A);
    cout << endl;

    // Clean up memory (don't forget to deallocate the memory when done)
    delete A;
    delete B;
    delete C;
    delete D;
    delete E;

    return 0;
}
