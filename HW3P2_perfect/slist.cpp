// CS311 Yoshii FALL21 Complete all functions with their comments
// NEVER delete my comments!!
// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Zachary Mekaelian
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 

// ** Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist()
{
    cout << "slist constructor: " << endl;
}


// positions always start at 1
//search through the list to see if any node contains Key.
//If so, return its position(>= 1).Otherwise, return 0.
int slist::search(el_t key) {
    Node* P = Front;
    int index = 1;
    while (P != NULL) {
        if (P->Elem == key)
            return index;
        P = P->Next;
        index++;
    }
    return 0;
}

// don't forget to throw OutOfRange for bad pos 
// You must use moveTo to go to the pos

//go to the Ith node(I is between 1 and Count) and replace the element there with Elem.
//If I was an illegal value, throw an exception(OutOfRange).MUST USE MOVETO
void slist::replace(el_t element, int pos) {
    if (pos <= 0 || pos > Count) {
        throw OutOfRange();
    }
    else {
        Node* I = Front;
        moveTo(pos, I);
        I->Elem = element;
    }
}
/*compare two slist object to see if they look the same.
•	If this->Count and OtherOne.Count are not the same, false.
•	Else go through the lists Count times comparing->Elem’s, and as soon as they are different, return false.
•	If the loop completes, return true.*/

bool slist::operator==(const slist& OtherOne)
{
    // if not the same length, return false immediately
    // if the same lengths,
    // check each node to see if the elements are the same
    // Case 1
    // if they are both empty, they're the same (contents identical)
    // Note that the case where one is empty but the other is not is covered by case 3
    // Compare the lengths
    if (this->Count != OtherOne.Count) {
        return false;
    }
    else {
        Node* P1 = this->Front;
        Node* P2 = OtherOne.Front;

        // Iterate over elements
        for (int i = 0; i < this->Count; i++) {

            // If elements not equal return false
            if (P1->Elem != P2->Elem)
                return false;
            else {
                // Change P1, P2 so that they correspond to 
                // pointer to next values
                P1 = P1->Next;
                P2 = P2->Next;
            }
        }
        return true;
    }
}