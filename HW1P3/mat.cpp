// CS311 YOSHII FALL21
// Complete by searching for **
// NEVER delete my comments!!!
//-------------------------------------- -
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

//--------------------------------------
// CS311 File mat.cpp for HW1P3 Matrix 
// Compiler: g++
// Your name: Zach Mekaelian
//--------------------------------------

// the following can be changed and the rest of the code should work
int const R = 3;  // number of rows
int const C = 4;  // number of columns
int const VL = 3; // table entry vector length

vector<char> T[R][C];  // 3 rows and 4 columns table for now 

// ------------------ Functions --------------------------------

int convert(char q) {
// Formula to convert a to 0, b to 1, c to 2...
int x = q - 'a';
return q;
}

char convert_back(int i)
{
    char t = i + 'a';
    return t;
}

// this reads the input file into the matrix table
void readTable()
{
    int row, col; //row and column variables
    char col_c;
    ifstream fin("lines.txt", ios::in);
    
    int i = 0; 
     // Read in the file into T
    while (fin >> row)  // per row
    {
        vector<char> v;
        fin >> col_c; 
        col = convert(col_c);  // to a slot number
        char c; // one char from the file
        //  Fill vector V with chars from the file (a for loop) ** 
        for (int i = 0; i < VL; i++) {
            fin >> c;
            v.push_back(c);
        }
            T[row][col] = v;
    }
        return ;
}
        //end of while

    // display the vector nicely to the outstream
    void showVector(vector<char> v, ostream & ost)
    {
        if (v.size() == 0)  // empty entry will be dashes
            for (int i = 1; i <= VL; i++) ost << "- ";
        else
        {  // show the content of v separated by blanks **
            for (int i = 0; i < v.size(); i++) 
                cout << v[i] << " ";
        }
    }



    // display the matrix
    void displayTable()
    {
        // display T nicely labeled with row numbers
        //    by calling showVector with cout
        //    for each column
        for (int r = 0; r < R; r++)
        {
            cout << r << ":";
            for (int c = 0; c < C; c++)
            {
                showVector(T[r][c], cout);
                cout << "|";
            }
            cout << endl;
        }
    }

    // save the matrix to the output file
    void saveTable()
    {
        ofstream fout("table.txt", ios::out);

        //    output T nicely labeled with row numbers
        //    by calling showVector with fout
        //    for each colum n**
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
                if (T[i][j].size() == 0) // Empty vector
                    continue; // Go to next iteration
            cout << i << ' '; // Print row number
            cout << convert_back(i) << ' '; // Print column number
            showVector(T[i][i], cout);
            cout << endl;
        }
    }


    int main()
    {
        cout << "reading from lines.txt" << endl;
        readTable();
        displayTable();

        cout << "saving the table in table.txt" << endl;
        saveTable();
    }//the end
