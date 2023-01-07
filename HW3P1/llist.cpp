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
{ cout << "... in llist constructor..." << endl; 
Front = Rear = NULL;
Count = 0;
}

llist::~llist() // destructor
{
	cout << ".... in llist destructor..." << endl;
	while (!isEmpty()) {
		delete(Front);
	}
}
//PURPOSE: return true if Front and Rear are both pointing to NULL and Count is 0.  
//PARAMETER: the parameter is empty
bool llist::isEmpty() { 
	if (Front == NULL && Rear == NULL && Count == 0) {
		return true; 
	}
	else { return false }
} // be sure to check all 3 data members

//PURPOSE:display each element of the list starting from Front, enclosed in  [ ] followed by endl.
//E.g.[1 2 3]  blanks between elements horizontally
//   (special case: if the list is empty, display[empty]).
//PARAMETER: the parameter is empty
void llist::displayAll() { 
	cout << "[";
	if (!isEmpty()) {
		Node* temp = Front;
		while (temp != NULL) {
			cout << temp->Elem << " ";
			temp = temp->Next;
		} else {
			cout << " empty ";
	}
	cout << "]" << endl;
}

}  // be sure to display horizontally in [  ] with
// blanks between elements e.g. [ 1 2 3 4 ]
// You MUST use while (P != NULL) loop or you will not get the credit!
  
//PURPOSE: special case: if this is going to be the very first node, you must
/*create a new nodeand make Frontand Rear point to it.Put NewNum in the Elem field
of this new node.Count is updated.
regular case:  add a new node at the rearand puts NewNum in the Elem field
	of this new node.Count is updated.*/
//PARAMETER: the param is el_t, a generic typedef data type passing NewNum
void llist::addRear(el_t NewNum) { 
	Node* t = new Node;
	t->Elem = NewNum;
	t->Next = NULL;

	if (isEmpty())
		Front = Rear = t;
	else {
		Rear->Next = t;
		Rear = t;
	}
	Count++;
} // comment the 2 cases

//PURPOSE:
//PARAMETER: the param is el_t, a generic typedef data type passing NewNum
void llist::addFront(el_t NewNum) { 
	Node* x = new Node;
	x->Elem = NewNum;
	x->Next = NULL;
	if (isEmpty())
		Front = Rear = x;
	else
	{
		x->Next = Front;
		Front = x;
	}
	Count++;
}} // comment the 2 cases

//PURPOSE:
//PARAMETER: the param is el_t&, a generic typedef data type passing OldNum
void llist::deleteFront(el_t& OldNum) { 
	if (isEmpty()){ 
		throw Underflow();
}
		OldNum = Front->Elem;
		if (Front->Next == NULL) {
			delete Front;
			Front = Rear = NULL;
			Count--;
		} else {
		Node* Second = Front->Next;
		cout << Second->Elem << endl;
		delete Front;
		Front = Second;
		Count--;
	}
} // comment the 3 cases

//PURPOSE:while loop that goes through list until P point to the node right before the rear node
//PARAMETER: the param is el_t&, a generic typedef data type passing OldNum
void llist::deleteRear(el_t& OldNum){
	if (isEmpty())
		throw Underflow();
	else
	{
		OldNum = Rear->Elem;
		Node* p = Front;
		//Make p go to the one right before rear (using while)
		while (p->Next != Rear) {
			p = p->Next;
		}
		delete Rear;
		Rear = p;
		Rear->Next = NULL;
	}
} // comment the 3 cases



/* --- harder ones for case 2 and 3 follow -- */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp)
{ // moves temp J-1 times to go to the Jth node  
  // for ( int K = ... ) temp = temp->Next;
	for(int = 1; I <= J - 1; i++) {
		p = p->next; //moves j-1 times
	}
}

//PURPOSE:
//PARAMETER:
void llist::deleteIth(int I, el_t& OldNum) {
	if (I > Count && I < 1){
		throw OutOfRange();
 } else {
	if (I < Count && I>1)
	{
		Node* p = Front;
		int j = 0;
		
		while (p->Next != NULL && j < I) {
			p = p->Next;
			j++;
		}
		OldNum = p->Next->Elem;
		p->Next = p->Next->Next;
		Count--;
	}
} // must use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  

//PURPOSE:
//PARAMETER:
void llist::insertIth(int I, el_t newNum) {
	if (I < Count && I>1)
	{
		Node* p = Front;
		int j = 0;
		//Make p go to the one right before rear (using while)
		while (p->Next != NULL && j < I)
		{
			p = p->Next;
			j++;
		}
		Node* x;
		x = new Node;
		x->Elem = newNum;
		x->Next = p->Next;
		p->Next = x;
		Count++;
	} else{
		throw OutOfRange();
  }
} // must use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE:
//PARAMETER:
llist::llist(const llist& Original) {
	//  this->'s data members need to be initialized here first
	Front = NULL; Rear = NULL; Count = 0;
	//  this-> object has to be built up by allocating new cells
	//  and copying the values from Original into each cell as we did with 
	//  operator= above. To do this,
	//copy here the(**) lines in Operator Overloading of = but note that it is Original and not OtherOne.
	const llist&;  
		//  Nothing to return because this is a constructor.
}
// use my code

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
			this->addRear(P->elem);    //P’s element is added to this->
			P = P->Next;                         // Go to the next node in OtherOne   
		}
	}// end of if              
	return *this;    // return the result unconditionally.  Note that the result is returned by reference.
}
} // use my code 

