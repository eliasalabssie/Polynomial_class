#include "Poly.h"


// ------------------------------------Poly-----------------------------------------------
// Description: an empty constructor of the Poly class
//sets the array size to 1 and initialize it to 0
// ----------------------------------------------------------------------------------------
Poly::Poly()
{
	 maxSize = 1;
	 thisArray = new double[maxSize];
	 thisArray[0] = 0;

}// end of empty constructor



//------------------------------------Poly(coefficient, exponent)--------------------------
// Description: constructs the poly class from coefficient and exponent arguments
//sets the array size to exponent + 1 and initialize it to 0
// ----------------------------------------------------------------------------------------
Poly::Poly(double coefficient, int exponent)
{

	this->maxSize = exponent+1;
	
	this->thisArray = new double [maxSize];
	
	for(int i = 0; i < maxSize; i++)
	{
		thisArray[i] = 0;
	}

	thisArray[exponent] = coefficient;	
	

}//end of two argumet constructor



// ------------------------------------Poly(coefficient)------------------------
// Description: constructs the poly class from the coefficient argument.
//sets the array size to 1 and initialize it to 0
// ----------------------------------------------------------------------------------------
Poly::Poly(double coefficient)
{
	
	this->maxSize = 1;
	thisArray = new double[maxSize];
	thisArray[0] = coefficient;


}//end of one argument constructor 


// ------------------------------------Poly(Poly&, int)------------------------
// Description: constructs the poly class from another Poly object and gibven size, 
//and initializes the values to the argument Poly object
// ----------------------------------------------------------------------------------------
Poly::Poly(const Poly &guestP, int size)
{
	this->thisArray = new double[size];
	this->maxSize = size;

	//initialize the array content to zero
	for(int i = 0; i < size; i++)
	{
		thisArray[i] = 0;

	}

	//copy the array contents
	for(int i = 0; i < guestP.maxSize; i++)
	{

		thisArray[i] = guestP.thisArray[i];
	}


}//end of const




// ------------------------------------Poly(Poly &)----------------------------------------
// Description: the copy constructor constructs the poly Object from another Poly object
// ----------------------------------------------------------------------------------------
Poly::Poly (const Poly &polynomial)
{
	//delete []thisArray;
	thisArray = new double[polynomial.maxSize];
	maxSize = polynomial.maxSize;

	//copy the values
	for(int i = 0; i < polynomial.maxSize; i++)
	{
		this->thisArray[i] = polynomial.thisArray[i];
	}

}//end of copy constructor


// ------------------------------------ ~Poly()----------------------------------------
// Description: this is the destructor function, frees momery
// ----------------------------------------------------------------------------------------
Poly::~Poly()
{
	delete [] thisArray;

}//end of destructor



// ------------------------------------getCoeff(int) const---------------------------------
// Description: this function returns the values of the arry at a requested index if the requested
// value is within the array bound, exits without returning value otherwise.the function assumes 
//a valid integer index as an argument.
// ----------------------------------------------------------------------------------------
int Poly::getCoeff(int exponent) const
{
	if(exponent < 0 || exponent > maxSize - 1)
	{
		//out of bound request, so exit with out returning value
		exit(1);
		
	}

	//valid request, so return value at the required index
	else
	{
		return thisArray[exponent];
	}
}


// ------------------------------------setCoeff(double,int) const--------------------------
// Description: this function sets the the coefficient at the right indet(exponent)of the arry.
//if the exponent argument is greater than the array size, the function recreate the "thisArray"
//data member with a new size and copies the original values back into it.
//the function assumes a valid double and integer numbers as an argument
// ----------------------------------------------------------------------------------------
void Poly::setCoeff(double coefficient, int exponent)
{
		if(this->maxSize < exponent)//resize the array
		{
			//temporary holder for the current array elements	
			double *tempHolder  = new double[maxSize]; 

			// temporaty holder for the current size
			int tempSizeHolder = this->maxSize;
			
			//copy the array elements
			for(int i = 0; i < maxSize; i++)
			{
					tempHolder[i] = thisArray[i];

			}	
			
			//delete the existing array data member
			delete [] thisArray;
			
			//the new size of the array data member
			int tempSize = exponent + 1;

			//declaring the resized array
			thisArray = new double[tempSize];
			
			//initialize the array to 0
			for(int i = 0; i < tempSize; i++)
			{
				thisArray[i] = 0;
			}

			//copy the original values back to the array	
			for(int k = 0; k < tempSizeHolder; k++)
			{
				thisArray[k] = tempHolder[k];

			}

			this->maxSize = tempSize;

			//set the new coefficient and exponent
			thisArray[exponent] = coefficient;

			//reclaim memory
			delete [] tempHolder;
		

		}

		// the the argument exponent is <= the the current array size 
		else
		{
			thisArray[exponent] = coefficient;
		}

}



// ----------------------------------- operator+(const Poly&) ----------------------------
// Description: this function overloads the + operator
// ----------------------------------------------------------------------------------------
Poly Poly::operator+(const Poly &rightPol)const
{
	//get the longest array size
	int size = this->maxSize >= rightPol.maxSize? maxSize: rightPol.maxSize;
	
	//construct a new Poly object from "rightPol" Poly object.
	Poly sum(rightPol, size);
	
	for(int i = 0; i < this->maxSize; i++)
	{
		sum.thisArray[i] += this->thisArray[i];
	}

	return sum;

}//end of + operator overload


// ------------------------------------ operator+= (const Pol&)------------------------
// Description: this function overloads += operator
// ----------------------------------------------------------------------------------------
Poly& Poly:: operator+=(const Poly &polynomial)
{

	//Poly sum = *this;
	//sum = sum + polynomial;
	* this = *this + polynomial;
	//delete [] sum.thisArray; 
	return *this;


}//end of += operator overloading function


// ------------------------------------ operator-  ----------------------------------
// Description: this function overloads the - operator
// ----------------------------------------------------------------------------------------
Poly Poly::operator-(const Poly &polynomial)const
{
	//get the maximum size among the two "thisArray" data members
	int size = max(this->maxSize, polynomial.maxSize);
	Poly differece(*this, size);
	
	double negatedValue;
	for(int i = 0; i < polynomial.maxSize; i++)
	{
		//get the value from the right side of the Poly array, negate it, and add it to the "difference"
		negatedValue = polynomial.thisArray[i] * (-1);

		//add the left and the right values into the third Poly object("difference")
		differece.thisArray[i] += negatedValue;
	}

	return differece;

}//end of operator- overload


// ------------------------------------ operator -=(const Poly&)---------------------------
// Description: this function overloads -=operator
// ----------------------------------------------------------------------------------------
Poly& Poly::operator-=(const Poly &polynomial)
{
	
	*this = *this - polynomial;
	
	return *this;

}//end of -= overloading 


// ------------------------------------ operator*(const Poly&) ---------------------------
// Description: this function overloads * operator
// ----------------------------------------------------------------------------------------
Poly Poly::operator*(const Poly &polynomial)const
{

	//creat new Poly object with Array size of summation of maxSize and polynomial.maxSize
	int size = maxSize + polynomial.maxSize;
	Poly Product;
	delete [] Product.thisArray;
	 Product.thisArray = new double[size];
	 Product.maxSize = size;
	 
	 //initialize it to 0
	 for (int i = 0; i < size; i ++)
	 	{
	 		Product.thisArray[i] = 0;
	 	}

	 	//the product of the two polynomial expressions
	 	for(int k = 0; k < maxSize; k++)
	 	{
	 		for(int j = 0; j < polynomial.maxSize; j++)
	 		{

	 			Product.thisArray[k+j]  += thisArray[k] *  polynomial.thisArray[j]; 

	 		}
	 	}
	 	
	return Product;

}//end of overloading * operator


// ------------------------------------ operator*=(const Poly&) ---------------------------
// Description: overloading * operator
// ----------------------------------------------------------------------------------------
Poly& Poly::operator*=(const Poly &polynomial)
{

	*this = *this * polynomial;
	return *this;
}


// ------------------------------------ operator==(const Poly&) const---------------------
// Description: overloading == operator(check the equality of two polynomials)
// return true if equal; false otherwise
// ----------------------------------------------------------------------------------------
bool Poly::operator==(const Poly &polynomial) const
{
	//if they don't have equal size, they are not equal.
	bool equalTo = this->maxSize == polynomial.maxSize;
	
	if(equalTo)
	{
		for(int i = 0; i < maxSize; i++)
		{
			//check equality of individual elements, return false if unequal.
			if(this-> thisArray[i] != polynomial.thisArray[i])
			{
				return false;
			}
		}

		return equalTo;
	}

}


// ------------------------------------ operator!= (const Poly&) ---------------------------
// Description: overloading != operator(check the equality of two polynomials)
// return true if not equal; false otherwise
// ----------------------------------------------------------------------------------------
bool Poly::operator!=(const Poly &polynomial) const
{
	bool notEqual = *this == polynomial;
	return !notEqual;
}


//---------------------------------------operator=()---------------------------------
// Description: this function overloads the assignment operator.
// ------------------------------------------------------------------------------------
Poly& Poly::operator=(const Poly &polynomial) 
{	
		//check self assignemt
		if(this != &polynomial)	
		{
			//delete the "thisArray" data member
			delete [] thisArray;

			thisArray = new double[polynomial.maxSize];
			maxSize = polynomial.maxSize;
		
			for(int i = 0; i < polynomial.maxSize; i++)
			{
				this->thisArray[i] = polynomial.thisArray[i];

			}
		}	
	return *this;
}


//---------------------------------------operator<<(ostream&, const Poly&)---------------------
// Description: overloading the friend insertion << operator.
ostream& operator <<(ostream &outStream, const Poly &pol)
{
	int valIndex = pol.maxSize-1;
	double value = pol.thisArray[valIndex];
	
	//find the first non-zero value from the array
	while(value == 0 && valIndex >= 0)
	{
		valIndex--;
		value = pol.thisArray[valIndex];
	}
	
	//if no non-zero value in the Array, return outStream << 0
	if(valIndex < 0)
	{
		outStream << 0;
		return outStream;
	}

	//only one constant at 0 index 
	if(valIndex == 0)
	{
		outStream << pol.thisArray[valIndex];
		return outStream;
	}
	
	//only 2 elements in the array 
	if(valIndex == 1)
	{
		outStream << pol.thisArray[valIndex] << "x" << pol.thisArray[0];
		return outStream;
	}


	//the array size is more than 2
	
	if(pol.thisArray[valIndex] > 0)
	{
		outStream << " +"<<pol.thisArray[valIndex] << "x^" << valIndex;
	}
	else if(pol.thisArray[valIndex] < 0)
	{
		outStream << " "<< pol.thisArray[valIndex] << "x^" << valIndex;

	}


	for(int i = valIndex-1; i > 1; i--)
	{

		if(pol.thisArray[i] > 0)//for positive coefficients
		{
			outStream <<" +"<< pol.thisArray[i] << "x^" << i;
		}
		
		else if(pol.thisArray[i] < 0) //for negative coefficients
		{
			outStream <<" "<< pol.thisArray[i] << "x^" << i;
		}

	}

	//desplaying value at position 1
	if(pol.thisArray[1] > 0)
	{
		outStream << " +"<< pol.thisArray[1] << "x";
	}

	if(pol.thisArray[1] < 0)
	{
		outStream << " "<< pol.thisArray[1] << "x";
	}

	//desplaying value at position 0
	if(pol.thisArray[0] > 0)
	{
		outStream << " +"<< pol.thisArray[0];
	}

	if(pol.thisArray[0] < 0)
	{
		outStream << " " << pol.thisArray[0];
	}
	
	return outStream;
}


//---------------------------------------operator>>(ostream&, Poly&)---------------------
// Description: overloading the friend extraction >> operator.
istream& operator>>(istream &iStream, Poly &pol)
{
	
	double coefficient;
	int exponent;
	
	iStream >> coefficient >> exponent;
	
	while(coefficient != -1 && exponent != -1)
	{
		pol.setCoeff(coefficient, exponent);
		iStream >> coefficient >> exponent;
		
	}
	
	return iStream;
}

