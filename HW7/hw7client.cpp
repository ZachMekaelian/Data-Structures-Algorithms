// CS311 YOSHII FALL21

//==========================================
// HW#: HW7 DFS client using dgraph.h
// Name: Zachary Mekaelian
// File type: client hw7client.cpp 
//==========================================

// ** Be sure to include both dgraph  and stack
#include "dgraph.h"
#include "stack.h"
using namespace std;
// This client uses the dgraph class and stack class
// to do depth first traversal of the graph stored in table.txt
int main()
{
  // ** copy here the algorithm (read carefully) in the HW7
  // assignment sheet and use that for the comments. 

  /*  Display the graph before DFS begins.
        Push A onto the stack to start.
        While the stack is not empty do:
    {
        Remove a vertex v from the stack.
            Display the vertex name.E.G.“Removed B from stack”
            If v is not marked yet(visit number is 0) then
            •	mark it(visit it**) and inform the user E.G.“Visit B as 2”
            •	get its adjacency list(slist)
            o	if no adjacent ones inform the user E.G.“Deadend reached – backup”
            o	else put adjacent ones on the stack(delete from the rearand push) informing the user
else inform the user E.G.“B had been visited already - backup.”
Display the stack clearly labeling it as the current stack
    }
    Display the Graph nicely with visit numbers for all vertices.
*/
    dgraph myGraph = dgraph();
    stack myStack = stack();

    cout << "Opening table.txt" << endl;
    myGraph.fillTable();


    cout << "Graph data:" << endl;
    myGraph.displayGraph();
    slist vertexAdjList = slist();
    char A;
    myStack.push(A);
    cout << "Finding adjacency list for vertex '" << vertex << "'" << endl;
    vertexAdjList = myGraph.findAdjacency(vertex);

    int count = 1; //this count will be used for tracking order of tree
    myGraph.visit(count, vertex);

    // Add the contents of this vertex's adjacency list to our stack
    while (!vertexAdjList.isEmpty())
    {
        vertexAdjList.deleteRear(vertex);
        myStack.push(vertex);
    }
    myStack.displayAll();
    while (!myStack.isEmpty())
    {

        myStack.pop(vertex);
        cout << "Visiting vertex '" << vertex << "'" << endl;
        if (!myGraph.isMarked(vertex))
        {
            cout << "Vertex '" << vertex << "' has not been visited." << endl;
            cout << "Finding adjacency list for vertex '" << vertex << "'" << endl;
            count++;
            myGraph.visit(count, vertex); //fills this vertex's order field
            vertexAdjList = myGraph.findAdjacency(vertex);
            char adjVertex;

            while (!vertexAdjList.isEmpty())
            {
                vertexAdjList.deleteRear(adjVertex);
                myStack.push(adjVertex);
            }
            cout << "Stack contents after adding the adjacency list of vertex '" << vertex << "':" << endl;
            myStack.displayAll();
        }
        else
        {
            cout << "Vertex '" << vertex << "' has already been visited." << endl;
        }
    }
    cout << "Graph data, visited:" << endl;
    myGraph.displayGraph();
    return(0);
}
