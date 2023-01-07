#include<iostream>
using namespace std;

// CS311 YOSHII FALL21
// You may not change my code in any manner.  0 pts if you do!!!!!!
// Simply add your code for **
//  NEVER delete my comments!!
//----------------------------------------
//CS311 HW2P2 Partition
//Name: Zach Mekaelian
//Compiler: g++
//-----------------------------------------

// partitions the array a into smaller than pivot and others.
// f is the beginning of the section to be partitioned
// r is the end of the section to be partitioned
// return the first slot of the Large section
int partition( int a[], int f, int r)
{
  int pivot = a[f];  // pivot is the first element
  int small = f; // pointer from the left
  int large = r; // pointer from the right 
  int i = (small-1);

  while (small <= large)//until they cross
    {
      // loop for finding out of place pairs and swap them
      //    until the small and large cross
      //    if small OK, move left
      //    if large OK, move right
      //    if both are bad, swap and then move
      if (a[small] <= pivot) {
          i++;
          int t = a[i];
          a[i] = a[small];
          a[small] = t;
      }
      small++;
   }//end of while
   
   // return the partition point where
   // those smaller than pivot are before what is returned
   // there is a special cases and a regular case
  int st = a[i+1];
  a[i+1] = a[large];
  a[large] = st;
  return (i+1);
}

int main()
{
  int x;  // number of elements
  int nums[10];
  cout << "How many elements? (must be less than 10) "; 
  cin >> x;
  cout << "Enter elements one per line.." << endl;
  for (int i = 0; i < x; i++)
    { 
      cin >> nums[i]; 
  }

  // the pivot is always the first element
  cout << "Ok the pivot is " << nums[0] << endl;

  int part = partition(nums, 0, x-1);

  cout << "Results..." << endl;
  // display up to the partition without endl
  for (int i = 0; i < part; i++)
    cout << nums[i];

  cout << "|";
  // display from the partition on.. without endl
  for (int i = part; i < x; i++)
    cout << nums[i];

  cout << endl;

}
