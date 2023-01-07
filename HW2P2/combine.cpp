using namespace std;
#include <iostream>
#include <vector>

// CS311 YOSHII FALL21
// Must use the algorithm that is in the notes! 
//  NEVER delete my comments!!
//--------------------------------------------
//CS311 HW2P2 Combine 
//Name: Zach Mekaelian
//Compiler: g++
//--------------------------------------------

// combines two sorted lists A and B into R
// displays comparison every time it is done
void combine(vector<int> A, vector<int> B, vector<int>& R)
{
  // your combine here      
    int  ia = 1; // index for A
    int ib = 1; // index for B
    int ir = 1; // i ndex for R 
    int lenA = A.size();// you can find out the size of A using the
    int lenB = B.size();// size function. Treat A and B like arrays. 
    R.resize(lenA + lenB);
    if (A[ia] < B[ib]) {
        R[ir] = A[ia]; ia = ia + 1; // get the A element to R
        cout << "comparison" << endl;

    }
    else {
        R[ir] = B[ib]; ib = ib + 1; // get the B element to R
        ir = ir + 1;

    }
}
// be careful -- R comes in as an empty vector with no slots so you have to use push_back




int main()
{
    vector<int> L1;
    vector<int> L2;
    vector<int> L3;
    int N;  // how many elements in each of L1 and L2
    int e;  // for each element

    cout << "How many elements in each list?" << endl;
    cin >> N;

    cout << "List1" << endl;
    for (int i = 1; i <= N; i++)
    {
        cout << "element :"; cin >> e; L1.push_back(e);
    }

    cout << "List2" << endl;
    for (int i = 1; i <= N; i++)
    {
        cout << "element :"; cin >> e; L2.push_back(e);
    }


    // call combine here to combine L1 and L2 into L3
    combine(L1, L2, L3);

    cout << "The result is: ";
    for (int i = 0; i < N * 2; i++)
    {
        cout << L3[i];
    } cout << endl;

}// end of main
