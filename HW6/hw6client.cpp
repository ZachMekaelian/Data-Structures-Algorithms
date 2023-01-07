// CS311 Yoshii FALL21
// HW6 Client file 
// INSTRUCTION: Complete this file and comment using How to Comment file.
//---------------------------------------------

// ================================================
// HW#: HW6 dgraph client 
// Name: Zachary Mekaelian
// File type:  hw6client.cpp  (tester)
// ================================================

 //** includes
#include <iostream>
#include <ctype.h>
#include "dgraph.h"
using namespace std;
void AdjList(dgraph& myGraph);
void Degree(dgraph& myGraph);

 //** comments
int main()
{   
    
    //0.Declare dgraph object
    //1.fillTable()
    //2.displayGraph()
    //while (the user does not want to stop)
    //a.the user will specify which vertex     
    //b.findOutDegree of the vertex and display the result
    //b.findAdjacency of the vertex and display the result (see Hint)
    //c.catch exception to display error mesg but do not exit
    //end of while**
    dgraph myGraph = dgraph();
    cout << "Opening table.txt" << endl;
    myGraph.fillTable(); 
    myGraph.displayGraph();
    int choice; 
    while (choice != 4) {

        try {
                cout << "What do you want to do?:" << endl
                    << "1. Pick a vertex" << endl
                    << "2. Find the out degree of the vertex" << endl
                    << "3. Find Adjacency of the vertex and display the result" << endl
                    << "4. Exit" << endl
                    << "Enter 1, 2, 3, or 4: ";
                cin >> choice;
                switch (choice)
                {
                case 1:
                    AdjList(myGraph);
                    break;
                case 2:
                    Degree(myGraph);
                    break;
                case 3:
                    cout << "Vertex\tDegree\tAdjacencyList" << endl;
                    myGraph.displayGraph();
                    break;
                case 4:
                    choice = 4;
                    break;
                default:
                    cout << "Invalid input, try again." << endl;
                    break;
                }
           
         }  catch( const std::exception & ex ) {
                cerr << ex.what() << endl;
         }

    }
    return(0);
}

void AdjList(dgraph& myGraph)
{
    slist adj_list = slist();
    string input;
    cout << "What vertex would you like to search for?: ";
    cin >> input;

    char vertex = toupper(input[0]);

    cout << "Searching for vertex " << vertex << endl;
    try
    {
        adj_list = myGraph.findAdjacency(vertex);
        cout << "The adjacency list for that vertex is:" << endl;
        adj_list.displayAll();
    }
    catch (dgraph::BadVertex)
    {
        cout << "Couldn't find that vertex in the graph." << endl;
    }
}
void Degree(dgraph& myGraph)
{
    string input;
    cout << "What vertex would you like to search for?: ";
    cin >> input;

    char vertex = toupper(input[0]);

    cout << "Searching for vertex " << vertex << endl;
    try
    {
        cout << "The out degree for that vertex is: " << myGraph.findOutDegree(vertex) << endl;
    }
    catch (dgraph::BadVertex)
    {
        cout << "Couldn't find the vertex in the graph." << endl;
    }
}
/*
Hint:
  slist l1;
  l1 = G.findAdjacency('a');
  // how do you display l1?  Hint: it is an slist from HW3.

*/
