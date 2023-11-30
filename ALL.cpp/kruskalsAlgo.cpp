#include <iostream>

using namespace std;

struct edge;

struct vertex
{
    char vertexName;
    vertex* next;
    edge* edgeStart;
    bool visited;
};

struct edge
{
    vertex* tovertex;
    int weight;
    edge* nextEdge;
};

struct vertex* vertexStart = nullptr;

struct vertexstack
{
    vertex* vertex;
    vertexstack *next;
}; struct vertexstack *top = NULL;

void push(vertex* vertex)
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

void ascendingWeights(vertex* start)
{
    vertex* current = start;

}
