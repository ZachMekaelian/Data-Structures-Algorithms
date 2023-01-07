
#include<iostream>
using namespace std;

// partitions the array a into smaller than pivot and others.
int partition(int a[], int f, int r)
{
    int pivot = a[f];  // pivot is the first element
    int small = f; // pointer from the left
    int large = r; // pointer from the right 
    int i = (small - 1);
    while (small <= large)//until they cross
    {
     cout << ".. Partition called with " << "front " << f << " and rear " << r << endl;
      if (a[small] <= pivot) {
          i++;
          int t = a[i];
          a[i] = a[small];
          a[small] = t;
      }
      small++;
   }//end of while


int st = a[i+1];
  a[i+1] = a[large];
  a[large] = st;
  return (i+1);
}



// sorting a's section starting at f and ending at r
void quicksort(int a[], int f, int r) { 
  if (f >= r) return;
  
  cout << "QuickSort front is " << f << " and rear is " << r << endl;

  int beg = partition(a, f, r);

  quicksort(a, f, beg-1);  // sort the small section in place
  quicksort(a, beg, r);    // sort the large section in place
 
}

  int main(){

  int x;
  int nums[10];
  cout << "How many elements? (must be less than 10) "; 
  cin >> x;
  cout << "Enter elements one per line.." << endl;
  for (int i = 0; i < x; i++)
    { cin >> nums[i]; }

  quicksort(nums, 0, x-1);

  cout << "FINAL RESULT:" << endl;
  for (int i = 0; i < x; i++) // up to the partition
      {cout << nums[i]; }
  cout << endl;
}
