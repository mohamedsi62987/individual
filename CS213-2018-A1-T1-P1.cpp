// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 1
// Program: CS213-2018-A1-T1-P1
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
    int* data;       // Pointer to 1-D array that will simulate matrix
    int row, col;
    int s=4;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);

// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
// new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
// matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
// and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
// Print matrix  as follows (2 x 3)			4	 6 	  8
// and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

//__________________________________________

int main()
{
    int y;
    cout<<"hello"<<endl;
    cout<<"press 1 if you need to add matrix "<<endl;
    cout<<"press 2 if you need to sub matrix "<<endl;
    cout<<"press 3 if you need to Multi if col1 == row2 matrix "<<endl;
    cout<<"press 4 if you need to Add a scalar "<<endl;
    cout<<"press 5 if you need to Subtract a scalar "<<endl;
    cout<<"press 6 if you need to Multiple by scalar"<<endl;
    cout<<"press 7 if you need to mat1 changes & return "<<endl;
    cout<<"press 8 if you need to mat1 changes + return new "<<endl;
    cout<<"press 9 if you need to +change mat & return new matrix  "<<endl;
    cout<<"press 10 if you need to -change mat & return new matrix  "<<endl;
    cout<<"press 11 if you need to  Add 1 to each element ++mat  "<<endl;
    cout<<"press 12 if you need to Sub 1 from each element --mat "<<endl;
    cout<<"press 13 if you need to Input matrix like this (dim 2 x 3)  "<<endl;
    cout<<"press 14 if you need to Print matrix  as follows (2 x 3)  "<<endl;
    cout<<"press 15 if you need to True if identical "<<endl;
    cout<<"press 16 if you need to True if not same "<<endl;
    cout<<"press 17 if you need to True if square matrix "<<endl;
    cout<<"press 18 if you need to True if square and symmetric "<<endl;
    cout<<"press 19 if you need to True if square and identity "<<endl;
    cout<<"press 20 if you need to Return new matrix with the transpose "<<endl;
    cin>>y;

   int data1 [] = {1,2,3,4,5,6,7,8,9};
 //int data1 [] = {1,0,0,0,1,0,0,0,1};
 //   int data1 [] = {1,3,5,3,2,4,5,4,9};
    int data2 [] = {13,233,3,4,5,6};
    int data3 [] = {10,100,10,100,10,100,10,100};

    matrix mat1, mat2, mat3;
    createMatrix (3, 3, data1, mat1);
    createMatrix (2, 3, data2, mat2);
    createMatrix (4, 2, data3, mat3);

// The next code will not work until you write the functions

    if (y==1)
        cout << (mat1 + mat2) << endl;
    if (y==2)
        cout << (mat1 - mat3) << endl;
    if (y==3)
        cout << (mat1 * mat3) << endl;

    if (y==14)
    {   cout << mat1 <<endl;
        cout << mat2 <<endl;
        cout << mat3 <<endl;
    }
    if (y==15)
        cout<<(mat1==mat2)<<endl;
    if (y==16)
        cout<<(mat1!=mat2)<<endl;
    if (y==17)
        cout<<(isSquare ( mat1))<<endl;
    if (y==18)
        cout<<isSymetric (mat1) <<endl;
    if (y==19)
        cout<<(isIdentity ( mat1))<<endl;
    if (y==20)
        transpose( mat2);

     main();
    /* cout << (mat1 + mat3) << endl << endl;
     cout << (mat3 + mat3) << endl << endl;

     ++mat1;
     cout << mat1 << endl;

     mat1+= mat3 += mat3;
     cout << mat1 << endl;
     cout << mat2 << endl;
     cout << mat3 << endl;
     // Add more examples of using matrix
    // * .......*/

    return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int [row * col];
    for (int i = 0; i < row * col; i++)
        mat.data [i] = num [i];
}
ostream& operator<< (ostream& out, matrix mat)
{
    for (int i=0; i<mat.row ; i++)
    {
        for (int j=0; j<mat.col; j++)
        {
            //out<<mat.data[i*mat.col+j]<<" ";
            out<<mat.data[j*mat.row+i]<<" ";
        }
        cout<<endl;
    }
    cout<<"";
}
bool   operator== (matrix mat1, matrix mat2)
{
    int x=0;
    if (mat1.row==mat2.row&&mat1.col==mat2.col)
    {
        for (int i=0; i<mat1.row*mat1.col ; i++)
        {

            if ( mat1.data[i]==mat2.data[i])
            {
                x=1;

            }
            else
                x=0;
        }
    }
    return x;
}




// True if identical
bool   operator!= (matrix mat1, matrix mat2)
{
    int x=0;
    if (mat1.row!=mat2.row&&mat1.col!=mat2.col)
    {
        x=1;
    }
    else
    {
        for (int i=0; i<mat1.row*mat1.col ; i++)
        {

            if ( mat1.data[i]==mat2.data[i])
            {
                x=0;

            }
            else
                x=1;

        }
        return x;
    }
}	// True if not same


bool   isSquare   (matrix mat)
{
    int x=0;
    if (mat.row==mat.col)
        x=1;
    else
        x=0;
    return x;

}
bool   isSymetric (matrix mat)// True if square and symmetric
{
    int x=1;


    if (mat.row==mat.col)
    {
        for(int i=0; i<mat.row; i++)
        {
            for(int j=0; j<mat.row; j++)
            {
                if((mat.data[i*mat.col+j])!=(mat.data[j*mat.row+i]))
                {
                    x=0;
                }}}}

    else
        x=0;

    return x;

}
bool   isIdentity (matrix mat)
{
    int x=1;
    if (mat.row==mat.col)
    {
        for(int i=0; i<mat.row; i++)
        {
            for(int j=0; j<mat.row; j++)
            {
                if((i==j) && (mat.data[i*mat.col+j]!=1))
                {
                    x=0;
                }
                else if(i!=j && mat.data[i*mat.col+j]!=0)
                {
                    x = 0;
                }

            }
        }
    }
    else
        x=0;
    return x;
}
matrix transpose(matrix mat)
{
    matrix matk;
    int data5[mat.row*mat.col];
    createMatrix (mat.col, mat.row, data5, matk);


        for(int i=0; i<mat.row; i++)
        {
            for(int j=0; j<mat.col; j++)
            {
                (matk.data[i*mat.col+j])= (mat.data[i*mat.col+j]);//(mat.data[j*mat.row+i]);

}}

cout <<matk<<endl;
}

istream& operator>> (istream& in, matrix &mat)
{
    for (int i=0; i<mat.row ; i++)
    {
        for (int j=0; j<mat.col; j++)
        {
            in>>mat.data[i*mat.col+j];
        }
    }
}
matrix operator+ (matrix mat1, matrix mat2)
{
    matrix output;
    output.data = new int [output.s];
    for(int i=0;i<output.s;++i)
        output.data[i]=mat1.data[i]+mat2.data[i];

            return output;
}

//*************************************
//Function of subtrction
matrix operator- (matrix mat1, matrix mat2)
{
    matrix output;
    output.data = new int [output.s];
    for(int i=0;i<output.s;++i)
        output.data[i]=mat1.data[i] - mat2.data[i];

            return output;
}

//**************************************
//Function of multiplcation
matrix operator* (matrix mat1, matrix mat2)
{
    matrix output;
    output.data = new int [output.s];
    for(int i=0;i<output.s;++i)
        output.data[i]=mat1.data[i] * mat2.data[i];

            return output;
}
