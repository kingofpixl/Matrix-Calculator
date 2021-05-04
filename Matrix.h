//CPSC2620
//Assignment 2
//File: Matrix.h
//This is the interface file for the matrix class.
//date: change the name of this file to Matrix.h
//Author: Wesley Waldern
//Partner:Ben Hunt
//work %: Ben:50%, Wes:50%.

#ifndef MATRIX_H
#define MATRIX_H
#include<iostream>
using namespace std;

class Matrix
{
  public:
   Matrix(int r=2, int c=2); //default constructor with default input parameters
   

   //methods
   void getDimensions(int &rows, int &columns);//returns the dimensions of a matrix.
   int &element(int i, int j);//returns a reference to the element at position i,j, allows you to change the elemnt at position i,j
   const int &element(int i, int j) const;
   void add(Matrix& m);//add a matrix with another
   void subtract(Matrix& m);//subtrace a matrix from another
   Matrix multiply(Matrix& b);//multiplies 2 matricies
   void read();//reads a matrix
   void write() const;//writes a matrix to the console

  private:
   int rows, cols;
   int **A;
};

#endif
