//CPSC2620
//Assignment 2
//File: Matrix2.h
//This is the interface file for the matrix class.
//date: feb,13,2019
//Author: Wesley Waldern
//Partner:Ben Hunt
//work %: Ben:50%, Wes:50%.

#ifndef MATRIX2_H
#define MATRIX2_H
#include<iostream>
using namespace std;

template<typename T>
class Matrix
{
  public:
   Matrix(int r=2, int c=2); //default constructor with default input parameters
   Matrix(const Matrix& m);
   ~Matrix();

   //methods
   Matrix& operator=(const Matrix& m);
   void getDimensions(int &rows, int &columns) const;//returns the dimensions of a matrix.
   T& operator()(int i, int j);//returns a reference to the element at position i,j, allows you to change the elemnt at position i,j
   const T& operator()(int i, int j) const;
   Matrix& operator+=(Matrix& m);//adds a matrix with another and equates them
   Matrix& operator-=(Matrix& m);//subtracts a matrix from another and equates them
   Matrix& operator*=(Matrix& m);//multiplies 2 matricies and equates them

   Matrix operator+(Matrix& m) const;//add a matrix with another
   Matrix operator-(Matrix& m) const;//subtracts a matrix from anothe
   Matrix operator*(Matrix& m) const;//multiplies 2 matricies
   //allows us to cin a matrix/ allows us to read a matrix with cin>>
   template<typename U> friend istream& operator>>(istream&, Matrix&);
   //allows us to cout a matrix/allows us to write a matrix with cout<<
   template<typename U> friend ostream& operator<<(ostream&, const Matrix&);
  private:
   int rows, cols;
   T **A;
   void setSize(int r, int c);
};

#include"./Matrix2.cc"
#endif
