// CS311 Yoshii FALL21 - Hash Table - complete all ** parts.
// Note: this class does not know the parts of element except for key
// so that it would work even if each element in the hash table changed
//  NEVER delete my comments!!
//-----------------------------------------------------

// ============================================
// HW#: HW8 Hash Table
// Name: Zachary Mekaelian
// File Type: implementation htable.cpp
// =============================================
#include <iostream>
#include "htable.h"

using namespace std;

htable::htable()
{}

htable::~htable()
{}

// a simple hash function that uses % TSIZE simply
int htable::hash(int key) {
  return key % TSIZE;   
}

// adds the element to the table and returns slot#
int htable::add(el_t element )
{
  int slot = this->hash(element.getkey());  // hash with the key part
  // Note that this means adding the element to a slist in the slot (call addRear)
  table[slot].addRear(element);
  return slot;
}

// finds element using the skey and returns the found element itself
// or a blank element  -- there is no cout in here
el_t htable::find(int skey)
{ 
 int slot = this->hash(skey); // hash with skey
 el_t selement;  // this is the element to look for in slist
 selement.setkey(skey); // initialize selement with just the skey (call setkey)
 selement = this->table[slot].search2(selement); // call slist's search2 with selement which returns the found element 
 return selement; // return the found element from here (it could be blank)
}

// finds the element given the key  and deletes it from the table.
//  Returns the slot number.
int htable::deleteIt(int skey)
{
 int slot = this->hash(skey); // hash with skey
 el_t selement;  // this is the element to look for in slist
 selement.setkey(skey); //  initialize selement with just the skey
 int index = this->table[slot].search(selement); //  call slist's search which gives you the location I and then deleteIth
 if (index > 0) {
   this->table[slot].deleteIth(index, selement);
 }
 return index;//  return the slot number
}

// fills the table using the specified input file 
void htable::fillTable(istream& fin)
{
  //  model this after HW6 to get data from the file the user specified
  //  which elem and slist functions do you call? List them here first.
  // **
  int key;
  string name;
  string type;
  int age;
  while(fin >> key >> name >> type >> age) {
    el_t element(key, name, type, age);
    add(element);
  }
}

// displays the entire table with slot#s too
void htable::displayTable()
{
  for (int i = 0; i < 37; i++)
    { 
      cout << i << ":" ;   
       // call slist's displayAll
      this->table[i].displayAll();
    }
}

// saves into the specified file in the same format as the input file
void htable::saveTable(ostream& fout) 
{  
  el_t elem;
  for (int i = 0; i < 37; i++) {   
      while (!this->table[i].isEmpty()) {
        this->table[i].deleteFront(elem);
        fout << elem << endl;
      }
      
  }
}
