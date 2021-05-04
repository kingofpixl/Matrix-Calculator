//CPSC2620
//Assignment 2
//File: matrix.cc
//This is the implimentation  file for the matrix class.
//date: feb,13,2019
//Author: Wesley Waldern
//partner Ben Hunt
//Work %: Ben:50%, Wes:50%.

#include<iostream>
#include<iomanip>
#include<cassert>
using namespace std;

//*************************************************************************
//Function: Default Constructor
//sets the array default to a 2 X 2 matrix
//*************************************************************************
template<typename T>
Matrix<T>::Matrix(int r, int c)
{
   A = nullptr;
   setSize(r,c);
}
//*************************************************************************
//Function: sets the size of the matrix
//*************************************************************************
template<typename T>
void Matrix<T>::setSize(int r, int c)
{
   if(A != nullptr)
   {
      for(int i=0;i<rows; i++)
	 delete [] A[i];
      delete [] A;
   }
   rows = r;
   cols = c;
   A = new T*[rows];
   for(int i = 0; i<rows; i++)
   {
      A[i] = new T[cols];
      for(int j = 0;j<cols;j++)
	 (*this)(i,j) = 0;
   }
}

//*************************************************************************
//Function: gets the dimensions of the array so that you can use
//them in the client
//*************************************************************************
template<typename T>
void Matrix<T>::getDimensions(int &r, int &c) const
{
   r = rows;
   c = cols;
}

//*************************************************************************
//Function: gets the element position and checks if its below the rows and
//greater than 0, makes it possible to change the value.
//*************************************************************************
template<typename T>
T& Matrix<T>::operator()(int i, int j)
{
   assert(i<rows && i>=0);
   assert(j<cols && j>=0);
   return A[i][j];
}

//*************************************************************************
//Function: gets the element position and checks if its below the rows and
//greater than 0, makes it impossible to change the value.
//*************************************************************************
template<typename T>
const T& Matrix<T>::operator()(int i, int j) const
{
   assert(i<rows && i>=0);
   assert(j<cols && j>=0);
   return A[i][j];
}

//*************************************************************************
//Function: takes two matricies adds them and equates
//it to the first matrix with a specified typename
//*************************************************************************
template<typename T>
Matrix<T>& Matrix<T>::operator+=(Matrix<T>& m)
{
   assert(rows == m.rows && cols == m.cols);
   for(int i=0;i<rows;i++)
      for(int j=0;j<cols;j++)
	 (*this)(i,j) +=  m(i,j);
   return *this;
}

//*************************************************************************
//Function: takes two matricies subtracts them and equates
//it to the first matrix with a specified typename
//*************************************************************************
template<typename T>
Matrix<T>& Matrix<T>::operator-=(Matrix<T>& m)
{
   assert(rows == m.rows && cols == m.cols);
   for(int i=0;i<rows;i++)
      for(int j=0;j<cols;j++)
	 (*this)(i,j) -=  m(i,j);
   return *this;
}

//*************************************************************************
//Function: takes two matricies multiplies them together and equates
//it to the first matrix with a specified typename
//*************************************************************************
template<typename T>
Matrix<T>& Matrix<T>::operator*=(Matrix<T>& m)
{
   assert(cols == m.rows);
   Matrix<T> temp(rows,m.cols);
   for(int i=0;i<rows;i++)
      for(int j=0;j<m.cols;j++)
	 for(int k = 0;k<cols;k++)
	    temp(i,j) += (A[i][k] * m(k,j));
   *this = temp;
   return *this;
	    
}

//*************************************************************************
//Function: reads a matrix into the console and asks for the dimensions of
//the matrix
//*************************************************************************
template<typename T>
istream& operator>>(istream& istr, Matrix<T>& m)
{
   int r,c;
   cout << "Enter dimensions of matrix: ";
   istr >> r >> c;
   Matrix<T> temp(r,c);
   
   cout << "Enter the " << r * c << " elements: ";
   for(int i=0; i<r; i++)
      for(int j=0; j<c; j++)
	 istr >> temp(i,j);
   m = temp;
   return istr;
}

//*************************************************************************
//Function: writes the matrix out to the client
//*************************************************************************
template<typename T>
ostream& operator<<(ostream& ostr, const Matrix<T>& m)
{
   int r,c;
   m.getDimensions(r,c);
   for(int i=0; i<r; i++)
   {
      for(int j=0; j<c; j++)
	 ostr << setw(7) << m(i,j);
      ostr << endl;
   }
   return ostr;
}
//*************************************************************************
//Function:Copy Constructor: creates a matrix that is a copy of another
//specified matrix and a specified type name
//*************************************************************************
template<typename T>
Matrix<T>::Matrix(const Matrix<T>& m)
{
   rows = m.rows;
   cols = m.cols;
   A = new T *[rows];
      for(int i = 0;i<rows;i++)
      {
	 A[i] = new T[cols];
      for(int j = 0; j<cols;j++)
	 (*this)(i,j) = m(i,j);
      }
}
//*************************************************************************
//Function: Destructor: destructs the matricies
//*************************************************************************
template<typename T>
Matrix<T>::~Matrix()
{
   for(int i = 0;i<rows;i++)
      delete [] A[i];
   delete [] A;
   A = nullptr;
}
//*************************************************************************
//Function: Assignmanet Operator: assigns one matrix to another with the
//specified typename
//*************************************************************************
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& m)
{
   if (this != &m)
   {
      setSize(m.rows,m.cols);
      for(int i=0;i<rows;++i)
	 for(int j=0;j<cols;++j)
	    (*this)(i,j) = m(i,j);
   }
   return *this;
}
//*************************************************************************
//Function: Addition Operator: allows two matricies to be added with the
//specified typename
//*************************************************************************
template<typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T>& m) const
{
   Matrix temp{*this};
   temp +=m;
   return temp;
}
//*************************************************************************
//Function: Subtraction Operator: allows two matricies to be subtracted
//with the specified typename
//*************************************************************************
template<typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T>& m) const
{
   Matrix temp{*this};
   temp -=m;
   return temp;
}
//*************************************************************************
//Function: Multiplication Operator: allows two matricies to be multiplied
//with the specified typename
//*************************************************************************
template<typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T>& m) const
{
   Matrix temp{*this};
   temp *=m;
   return temp;
}
