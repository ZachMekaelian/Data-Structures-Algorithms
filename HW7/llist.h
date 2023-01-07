
//CS311 Yoshii
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Zachary Mekaelian
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
typedef char el_t;  // int for now but can change later
using namespace std;
//a list node is defined here as a struct Node for now
struct Node
{
    el_t Elem;   // elem is the element stored
    Node* Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{

protected:
    Node* Front;       // pointer to the front node
    Node* Rear;        // pointer to the rear node
    int  Count;        // counter for the number of nodes
    //**************************************************************
    // utility function to move to a specified node position
    void moveTo(int, Node*&); //Node*& is a pointer to a node object allowing change of memory address pointed to by pointer
   //*************************************************************** 
public:

    // Exception handling classes 
    class Underflow {};
    class OutOfRange {};  // thrown when the specified Node is out of range

    llist();     // constructor to create a list object
    ~llist();     // destructor to destroy all nodes

    // checks to see if the list is empty
    bool isEmpty();

    // displays all elements in the list
    void displayAll();

    // adds an element to the front
    void addFront(el_t);

    // adds an element to the rear
    void addRear(el_t);

    // deletes an element from the front
    void deleteFront(el_t&);

    //---------------------------------------

    // deletes an element from the rear
    void deleteRear(el_t&);

    // deletes the "I"th element in the list which is specified
    void deleteIth(int, el_t&);  // calls moveTo

    // inserts an element into the Ith slot specified in the list    
    void insertIth(int, el_t);   // calls moveTo

    //Copy Constructor to allow pass by value and return by value of a llist
    llist(const llist&);

    //Overloading of = (returns a reference to a llist)
    llist& operator=(const llist&);

};
