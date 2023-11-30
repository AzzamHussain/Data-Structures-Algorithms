#include <iostream>
#include <cstring>
using namespace std;

struct edgeList;

struct Vertex
{
    char vertexName;
    Vertex* next;
    edgeList* edgeStart;
    bool visited;
};

struct edgeList
{
    Vertex* toVertex;
    edgeList* nextEdge;
};

struct Vertex* vertexStart = nullptr;

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

bool stackempty() {
    return top == NULL;
}

void resetVisitedFlag() {
    Vertex* current = vertexStart;
    while (current != nullptr) {
        current->visited = false;
        current = current->next;
    }
}

void addVertex()
{
    char vertexName;
    cout << "Enter Vertex Name: ";
    cin >> vertexName;

    Vertex* curr = vertexStart;
    while (curr != nullptr)
    {
        if (curr->vertexName == vertexName)
        {
            cout << "Vertex already exists." << endl;
            return;
        }
        curr = curr->next;
    }

    Vertex* temp = new Vertex;
    temp->vertexName = vertexName;
    temp->next = nullptr;
    temp->edgeStart = nullptr;
    temp->visited = false;

    if (vertexStart == nullptr)
    {
        vertexStart = temp;
    }
    else
    {
        curr = vertexStart;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }

    cout << "Vertex Entered Successfully!!" << endl;
}

void addEdge()
{
    char toVertex, fromVertex;
    cout << "Enter vertex from which edge starts: ";
    cin >> fromVertex;
    cout << "Enter vertex to which edge ends: ";
    cin >> toVertex;

    Vertex* curr = vertexStart;
    Vertex* fromV = nullptr;
    Vertex* toV = nullptr;

    while (curr != nullptr)
    {
        if (curr->vertexName == fromVertex)
        {
            fromV = curr;
        }
        if (curr->vertexName == toVertex)
        {
            toV = curr;
        }

        if (fromV != nullptr && toV != nullptr)
        {
            break;
        }

        curr = curr->next;
    }

    if (fromV != nullptr && toV != nullptr)
    {
        edgeList* tempEdge = new edgeList;
        tempEdge->toVertex = toV;
        tempEdge->nextEdge = nullptr;

        if (fromV->edgeStart == nullptr)
        {
            fromV->edgeStart = tempEdge;
        }
        else
        {
            edgeList* currEdge = fromV->edgeStart;
            while (currEdge->nextEdge != nullptr)
            {
                currEdge = currEdge->nextEdge;
            }
            currEdge->nextEdge = tempEdge;
        }

        cout << "Edge Added Successfully!!" << endl;
    }
    else
    {
        cout << "One or both of the specified vertices were not found." << endl;
    }
}

void findOutDegree(char vertex)
{
    int degree = 0;
    Vertex* curr = vertexStart;

    while (curr != nullptr)
    {
        if (curr->vertexName == vertex)
        {
            edgeList* eCurr = curr->edgeStart;
            while (eCurr != nullptr)
            {
                degree++;
                eCurr = eCurr->nextEdge;
            }
        }
        curr = curr->next;
    }

    cout << "Degree of the vertex is " << degree << endl;
}

int findInDegree(char vertex)
{
    int inDegree = 0;
    Vertex* curr = vertexStart;

    while (curr != nullptr)
    {
        // Skip the vertex itself
        if (curr->vertexName == vertex)
        {
            curr = curr->next;
            continue;
        }

        edgeList* eCurr = curr->edgeStart;
        while (eCurr != nullptr)
        {
            if (eCurr->toVertex->vertexName == vertex)
            {
                // Found an incoming edge to the specified vertex
                inDegree++;
            }
            eCurr = eCurr->nextEdge;
        }

        curr = curr->next;
    }

    return inDegree;
}

void deleteVertex()
{
    int err = 0;
    char toDelete;
    cout << "Enter the Vertex you want to delete: ";
    cin >> toDelete;

    Vertex* current = vertexStart;
    Vertex* prev = nullptr;

    // Iterate through the vertices to find the one to delete
    while (current != NULL) {
        if (current->vertexName == toDelete) {
            // Delete all the edges of the current vertex
            edgeList* currentEdge = current->edgeStart;
            while (currentEdge != NULL) {
                edgeList* temp = currentEdge;
                currentEdge = currentEdge->nextEdge;
                delete temp;
                err++;
            }

            // Update the previous vertex's next pointer or vertexStart
            if (current == vertexStart) {
                vertexStart = current->next;
            } else {
                prev->next = current->next;
            }

            // Delete the current vertex and break out of the loop
            delete current;
            err++;
            break;
        }
        prev = current;
        current = current->next;
    }
    if (err == 0)
    {
        cout << "Vertex " << toDelete << " does not exist." << endl;
    }

    // Iterate through the remaining vertices to remove edges pointing to the deleted vertex
    current = vertexStart;
    while (current != NULL) {
        edgeList* currentEdge = current->edgeStart;
        edgeList* prevEdge = NULL;
        while (currentEdge != NULL) {
            if (currentEdge->toVertex != NULL && currentEdge->toVertex->vertexName == toDelete) {
                if (currentEdge == current->edgeStart) {
                    current->edgeStart = currentEdge->nextEdge;
                    delete currentEdge;
                    currentEdge = current->edgeStart;
                } else {
                    prevEdge->nextEdge = currentEdge->nextEdge;
                    delete currentEdge;
                    currentEdge = prevEdge->nextEdge;
                }
            } else {
                prevEdge = currentEdge;
                currentEdge = currentEdge->nextEdge;
            }
        }
        current = current->next;
    }
    if (err != 0)
    {
        cout << "Vertex " << toDelete << " deleted successfully!!" << endl;
    }
}

bool hasCycle(Vertex* currentVertex, Vertex* parent) {
    currentVertex->visited = true;

    edgeList* currentEdge = currentVertex->edgeStart;
    while (currentEdge != NULL) {
        if (currentEdge->toVertex->visited == false) {
            if (hasCycle(currentEdge->toVertex, currentVertex)) {
                return true;
            }
        } else if (currentEdge->toVertex != parent) {
            return true;
        }
        currentEdge = currentEdge->nextEdge;
    }

    return false;
}

bool isCyclic() {
    resetVisitedFlag();
    Vertex* current = vertexStart;

    while (current != NULL) {
        if (current->visited == false) {
            if (hasCycle(current, nullptr)) {
                return true; // A cycle is found
            }
        }
        current = current->next;
    }
    return false; // No cycles found
}


Vertex* DFS(Vertex* start, Vertex* end) {
    cout << "START:" << start->vertexName<< endl;
    cout << "END: "<< end->vertexName<< endl;
    Vertex* result = nullptr;
    push(start);

    while (stackempty() == false) {
        Vertex* current = top->vertex;
        pop();

        if (current->visited == false) {
            current->visited = true;
            cout << current->vertexName << " ";

            if (current == end) {
                cout << endl;
                return result;
            }

            edgeList* Edge = current->edgeStart;
            while (Edge != NULL) {
                if (Edge->toVertex->visited == false) {
                    push(Edge->toVertex);
                }
                Edge = Edge->nextEdge;
            }
        }
    }
    cout << endl;
    return result;
}

bool findPathDFS(char fromVertex, char toVertex) {
    resetVisitedFlag();
    Vertex* endingVertex = nullptr; // Initialize it to nullptr
    Vertex* currentVertex = vertexStart;

    while (currentVertex != nullptr) {
        if (toVertex == currentVertex->vertexName) {
            endingVertex = currentVertex;
        }
        currentVertex = currentVertex->next;
    }
    if (endingVertex == nullptr)
    {
        cout << "Ending vertex does not exist!" << endl;
        return false;
    }

    Vertex* startingVertex = vertexStart;
    while (startingVertex != nullptr) {
        if (startingVertex->vertexName == fromVertex) {
            DFS(startingVertex, endingVertex); // Call DFS for its side effect (printing the path)
            return true;
        }
        startingVertex = startingVertex->next;
    }
    cout << "Starting vertex does not exist!" << endl;
    return false; // Starting vertex not found
}


void Print()
{
    if (vertexStart == NULL)
    {
        cout << "No Vertices!!\n";
        return;
    }
    
    Vertex* vertexCurrent = vertexStart;
    while (vertexCurrent != NULL)
    {
        cout << "Vertex Name: " << vertexCurrent->vertexName << ":";

        edgeList* currentEdge = vertexCurrent->edgeStart;
        if (currentEdge == NULL)
        {
            cout << "\n" << "There are currently no edges in vertex " << vertexCurrent->vertexName << "\n";
        }
        else
        {
            while (currentEdge != NULL)
            {
                cout << " -> " << currentEdge->toVertex->vertexName;
                currentEdge = currentEdge->nextEdge;
            }
            cout << "\n";
        }
        
        vertexCurrent = vertexCurrent->next;
    }
}


int main() {
    int opt = -1; //Initializing opt to a non zero value
    while (opt != 0) {
        cout << "1: Add Vertex" << endl;
        cout << "2: Add Edge" << endl;
        cout << "3: Delete Vertex" << endl;
        cout << "4: Print" << endl;
        cout << "5: Find Path" << endl;
        cout << "6: Check for Cycles" << endl;
        cout << "0: Exit" << endl;
        cin >> opt;
        switch (opt) {
            case 1:
                addVertex();
                break;
            case 2:
                addEdge();
                break;
            case 3:
                deleteVertex();
                break;
            case 4:
                Print();
                break;
            case 5:
                char vertexFrom, vertexTo;
                cout << "Enter the starting vertex: ";
                cin >> vertexFrom;
                cout << "Enter the ending vertex: ";
                cin >> vertexTo;
                findPathDFS(vertexFrom, vertexTo);
                break;
            case 6:
                if (isCyclic() == true) {
                    cout << "The graph contains a cycle." << endl;
                } else {
                    cout << "The graph does not contain a cycle." << endl;
                }
                break;
            case 0:
                break;
            default:
                cout << "Invalid Option!" << endl;
                break;
        }
    }

    return 0;
}

