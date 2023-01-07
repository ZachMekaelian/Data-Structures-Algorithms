//CS311 Yoshii FALL21 Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  You can copy from a Word document to emacs (contrl-right click)
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//  NEVER delete my comments!!!!
//EMACS HINT:
//  cntr-K cuts and cntr-Y pastes. 
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Zachary Mekaelian
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist() // constructor 
{
	cout << "... in Allist constructor..." << endl;
	Front = Rear = NULL;
	Count = 0;
}

llist::~llist() // destructor
{
	cout << ".... in llist destructor..." << endl;
	while (!isEmpty()) {
		el_t x;
		deleteRear(x);
	}
}
//PURPOSE: return true if Front and Rear are both pointing to NULL and Count is 0.  
//PARAMETER: the parameter is empty
bool llist::isEmpty() {
	if (Front == NULL && Rear == NULL && Count == 0) {
		return true;
	}
	else { return false; }
} // be sure to check all 3 data members

//PURPOSE:display each element of the list starting from Front, enclosed in  [ ] followed by endl.
//E.g.[1 2 3]  blanks between elements horizontally
//   (special case: if the list is empty, display[empty]).
//PARAMETER: the parameter is empty
void llist::displayAll() {
	cout << "[";
	if (!isEmpty()) {
		Node* t = Front;
		while (t != NULL) {
			cout << t->Elem << " ";
			t = t->Next; // move t pointer to the next node
		}
	}
	else {
		cout << " empty ";
	}
	cout << "]" << endl;
}

// be sure to display horizontally in [  ] with
// blanks between elements e.g. [ 1 2 3 4 ]
// You MUST use while (P != NULL) loop or you will not get the credit!

//PURPOSE: special case: if this is going to be the very first node, you must
/*create a new nodeand make Frontand Rear point to it.Put NewNum in the Elem field
of this new node.Count is updated.
regular case:  add a new node at the rearand puts NewNum in the Elem field
	of this new node.Count is updated.*/
	//PARAMETER: the param is el_t, a generic typedef data type passing NewNum
void llist::addRear(el_t NewNum) {
	if (isEmpty()) {// if list is empty create first node and make front and rear point to it
		Node* t = new Node; //instantiate new node object 
		Front = Rear = t; // set rear and front to new node
		t->Elem = NewNum;
		Rear->Next = NULL;
	}
	else {
		Rear->Next = new Node; //creates node after rear pointer
		Rear = Rear->Next; // goes to the next node Rear->Next
		Rear->Elem = NewNum; //allows NewNum
		Rear->Next = NULL; // 
	}
	Count++;
} // comment the 2 cases

//PURPOSE:
//PARAMETER: the param is el_t, a generic typedef data type passing NewNum
void llist::addFront(el_t NewNum) {
	if (isEmpty()) {
		Node* p = new Node;
		Front = Rear = p;
		p->Elem = NewNum;
		p->Next = NULL;

	}
	else {
		Node* p; // declare p
		p = new Node; // instantiate new p object
		p->Elem = NewNum;
		p->Next = Front;
		Front = p;
	}
	Count++;
}  // comment the 2 cases

/*PURPOSE:void deleteFront(el_t& OldNum) – 3 cases
	error case: if the List is empty, throw an exception.
	special case: if this is going to make the list empty, give back the front node element through OldNum
				(pass by reference) and also remove the front node.Count is updated.
		Make sure both Frontand Rear both become NULL.
	regular case:  give back the front node element through OldNum(pass by reference)
		and also remove the front node.Count is updated.
//PARAMETER: the param is el_t&, a generic typedef data type passing OldNum*/
void llist::deleteFront(el_t& OldNum) {
	if (isEmpty()) {
		throw Underflow();
	}

	else if (Front->Next == NULL) {
		OldNum = Front->Elem;//give back the front node element through OldNum(pass by reference)
		delete Front;
		Front = Rear = NULL;
		Count--;
	}
	else {
		OldNum = Front->Elem;//give back the front node element through OldNum(pass by reference)
		Node* Second = Front->Next;
		delete Front;
		Front = Second;
		Count--;
	}
} // comment the 3 cases

//PURPOSE:while loop that goes through list until P point to the node right before the rear node
//PARAMETER: the param is el_t&, a generic typedef data type passing OldNum
void llist::deleteRear(el_t& OldNum) {
	if (isEmpty()) {
		throw Underflow();
	}
	else if (Count == 1) {
		OldNum = Rear->Elem;
		delete Rear;
		Front = Rear = NULL;
		Count--;
	}
	else {
		Node* p = Front;
		while (p->Next != Rear) {//Make p go to the orear (using while)
			p = p->Next;
		}
		OldNum = Rear->Elem;
		delete Rear;
		Rear = p;
		Rear->Next = NULL;
		Count--;
	}
} // comment the 3 cases



/* --- harder ones for case 2 and 3 follow -- */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& p)
{ // moves temp J-1 times to go to the Jth node  
  // for ( int K = ... ) temp = temp->Next;
	p = Front;
	for (int i = 1; i <= (J - 1); i++) {

		p = p->Next; //moves j-1 times
	}
}

//PURPOSE:
//PARAMETER:
void llist::deleteIth(int I, el_t& OldNum) {
	if (I > Count || I < 1) { // the function call needs to be in range
		throw OutOfRange();
	}
	else if (I == 1) {
		deleteFront(OldNum);

	}
	else if (I == Count) {
		deleteRear(OldNum);

	}
	else {
		Node* p;// create to pointers
		Node* t;
		moveTo(I - 1, p);// move them both to the position just before and after the list slot specified
		moveTo(I + 1, t);
		OldNum = p->Next->Elem;// the slot after the p pointer is going to be the elem targeted by oldnum
		delete p->Next; //deletet element after p->next
		p->Next = t; // the pointer after the one deleted is now the deleted node
		Count--;
	}
}// must use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum. 



	   //PURPOSE: insert element into specified node position
	   //PARAMETER: int I is for the position specified, el_t newNum is for the element to be placed inside said node
void llist::insertIth(int I, el_t NewNum) { // newnum specified by user/ main to be the new num in the elem node, I is the slot in the linked list to put newnum
	if (I > Count + 1 || I < 1) {//create boundries
		throw OutOfRange();
	}
	else if (I == 1) {// if the slot is the first in list, add newnum to the front
		addFront(NewNum);
	}
	else if (I == Count + 1) {
		addRear(NewNum); //if the slot specified is the slot after the last node, add a new one to the back/rear
	}
	else {
		Node* p; //pointers
		Node* t;
		Node* x = new Node;
		x->Elem = NewNum;
		moveTo(I - 1, p);
		moveTo(I, t);
		p->Next = x;
		x->Next = t;
		Count++;
	} // must use moveTo to move local pointers. Be sure to comment to which node you are moving them.
}



//PURPOSE:
//PARAMETER:
llist::llist(const llist& Original) {
	//  this->'s data members need to be initialized here first
	Front = NULL; Rear = NULL; Count = 0;
	//  this-> object has to be built up by allocating new cells
	//  and copying the values from Original into each cell as we did with 
	//  operator= above. To do this,
	//copy here the(**) lines in Operator Overloading of = but note that it is Original and not OtherOne.
	Node* P;  // local pointer for OtherOne
	P = Original.Front;
	while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
	{
		this->addRear(P->Elem);     //P’s element is added to this->
		P = P->Next;                         // Go to the next node in OtherOne   
	}
	// end of if              

	   //  Nothing to return because this is a constructor.
}// use my code


//PURPOSE:
//PARAMETER:
llist& llist::operator=(const llist& OtherOne) {
	el_t x;
	// First make sure this-> and OtherOne are not the same object.
	// To do this, compare the pointers to the objects .
	if (&OtherOne != this)  // if not the same
	{
		// this-> object has to be emptied first.
		while (!this->isEmpty())
			this->deleteRear(x);


		// this-> object has to be built up by allocating new cells with OtherOne elements (**)
		Node* P;  // local pointer for OtherOne
		P = OtherOne.Front;
		while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
		{
			this->addRear(P->Elem);     //P’s element is added to this->
			P = P->Next;                // Go to the next node in OtherOne   
		}
	}// end of if              
	return *this;    // return the result unconditionally.  Note that the result is returned by reference.
}

// use my code 

