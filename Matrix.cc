//CPSC2620
//Assignment 2
//File: matrix.h
//This is the implimentation  file for the matrix class.
//date:
//Author: Wesley Waldern
//partner Ben Hunt
//Work %: Ben:50%, Wes:50%.

#include"./Matrix.h"
#include<iostream>
#include<iomanip>
#include<cassert>
using namespace std;

//*************************************************************************
//Function: Default Constructor
//sets the array default to a 2 X 2 matrix
//*************************************************************************

Matrix::Matrix(int r, int c)
{
   rows = r;
   cols = c;
   A = new int *[rows];    // first dimension
   for (int i = 0; i < rows; i++)
   {
      A[i] = new int[cols];
      for(int j=0; j<cols; j++)
	 A[i][j] = 0;
   }
}

//*************************************************************************
//Function: gets the dimensions of the array so that you can use them in the//client
//*************************************************************************

void Matrix::getDimensions(int &r, int &c)
{
   r = rows;
   c = cols;
}

//*************************************************************************
//Function: gets the element position and checks if its below the rows and
//greater than 0, makes it possible to change the value.
//*************************************************************************

int &Matrix:: element(int i, int j)
{
   assert(i<rows && i>=0);
   assert(j<cols && j>=0);
   return A[i][j];
}

//*************************************************************************
//Function: gets the element position and checks if its below the rows and
//greater than 0, makes it impossible to change the value.
//*************************************************************************

const int &Matrix:: element(int i, int j) const
{
   assert(i<rows && i>=0);
   assert(j<cols && j>=0);
   return A[i][j];
}

//*************************************************************************
//Function: Adds two matricies
//*************************************************************************

void Matrix::add(Matrix& m)
{
   assert(rows == m.rows && cols == m.cols);
   for(int i=0;i<rows;i++)
      for(int j=0;j<cols;j++)
      {
	 A[i][j] +=  m.A[i][j];
      }
}

//*************************************************************************
//Function: Subtracts two matricies
//*************************************************************************

void Matrix::subtract(Matrix& m)
{
   assert(rows == m.rows && cols == m.cols);
   for(int i=0;i<rows;i++)
      for(int j=0;j<cols;j++)
      {
	 A[i][j] -=  m.A[i][j];
      }
}

//*************************************************************************
//Function: Multiplies two matricies
//*************************************************************************

Matrix Matrix::multiply(Matrix& b)
{
   assert(cols == b.rows);
   Matrix c(rows,b.cols);
   for(int i=0;i<rows;i++)
      for(int j=0;j<b.cols;j++)
	 for(int k = 0;k<cols;k++)
	    c.A[i][j] += A[i][k] * b.A[k][j];
   return c;
	    
}

//*************************************************************************
//Function: reads a matrix into the console and asks for the dimensions of
//the matrix
//*************************************************************************

void Matrix::read()
{
   int r , c;
   cout << "Enter dimensions of matrix: ";
   cin >> r >> c;
   if(rows!=r||cols!=c)
   {
      for(int i=0;i<rows;i++)
	 delete [] A[i];
      delete [] A;
      rows = r;
      cols = c;

      A = new int *[rows];
      for (int i = 0; i < rows; i++)
      {
      A[i] = new int[cols];
      for(int j=0; j<cols; j++)
	 A[i][j] = 0;
      }
   }
   cout << "Enter the " << r * c << " elements: ";
   for(int i=0; i<r; i++)
      for(int j=0; j<c; j++)
	 cin >> A[i][j];
   
   
}

//*************************************************************************
//Function: writes the matrix out to the client
//*************************************************************************

void Matrix::write() const
{
   for(int i=0; i<rows; i++)
   {
      for(int j=0; j<cols; j++)
	 cout << setw(4) << A[i][j];
      cout << endl;
   }
}
