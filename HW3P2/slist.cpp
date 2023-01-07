// CS311 Yoshii FALL21 Complete all functions with their comments
// NEVER delete my comments!!
// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: **
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
    cout << "slist constructor: "<< endl;}


        // positions always start at 1

        int slist::search(el_t key) {} 

    // don't forget to throw OutOfRange for bad pos 
    // You must use moveTo to go to the pos
    void slist::replace(el_t element, int pos) {}

    bool slist::operator==(const slist & OtherOne) 
    {
        // if not the same length, return false immediately
        // if the same lengths,
        check each node to see if the elements are the same
    }
