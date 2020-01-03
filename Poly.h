// ------------------------------- Poly.h-------------------------------------------------------------------------

/* Author: Elias Alabssie
*Class: CSS 343, Section c
*project created: Jan 10, 2019
*Date of Last Modification: Jan 20, 2019
 -------------------------------------------------------------------------------------------------------------------

 * This Poly class header creates a declaration for an abstract data type using dinamic arrays for  polynomials. 
   the array is created dynamically using pointers. operators are overloaded for the class to do polynomial calculations
------------------------------------------------------------------------------------------------------------------------
 
The program assumes the user inputs a positive integers  or zero as exponent for the polynimial.
   also the program assumes the user doesn't input non-numberic values (no data type checking).
--------------------------------------------------------------------------------------------------------------------------*/

#pragma once 
#include<iostream>
using namespace std;

class Poly
{
	//friend methods
	friend ostream& operator <<(ostream &outStream, const Poly &pol);
	friend istream& operator>>(istream &iStream, Poly &pol);

public:
	
	//constructors
	Poly();
	Poly(double coefficient, int exponent);
	Poly(double coefficient);
	Poly(const Poly &guestP, int size);

	//copy constructor
	Poly (const Poly &Polynomial);

	//destructor
	~Poly();
	
	//operator overloads
	Poly operator+(const Poly &rightPol)const;
	
	Poly& operator+=(const Poly &polynomial);
	
	Poly operator-(const Poly &Polynomial)const;
	
	Poly& operator-=(const Poly &Polynomial);
	
	Poly operator*(const Poly &Polynomial)const;
	
	Poly& operator*=(const Poly &Polynomial);
	
	Poly& operator=(const Poly &polynomial);
	
	bool operator==(const Poly &Polynomial) const;
	
	bool operator!=(const Poly &Polynomial) const;

	//getters and setters
	int getCoeff(int exponent) const;
	
	void setCoeff(double coefficient, int exponent);


private:
	
	int maxSize;
	double* thisArray; 

};//this is the end of the source file


