#include "transaction.h"
//#include "store.h"

//---------------------------Constructor----------------------------------//
//the transaction object is a pure virtual object and doesn't actually
//implement anything, nothing in the transaction object needs to be set
//because it is never used
Transaction::Transaction()
{
}

//---------------------------Destructor-----------------------------------//
//the transaction object is a pure virtual object and doesn't actually 
//implement anything, nothing in the transaction object needs to be cleaned
//up for because the dynamically allocated variables are not used
//or accessed here, but rather in the classes below
Transaction::~Transaction()
{
}

//--------------------------Pretty Prints---------------------------------//
//this method allows the cout << to be called on classes that inherit
//from transaction because they must implement a print function
//that is called from ostream operator
ostream& operator<<(ostream& os, const Transaction& ref)
{
	ref.print(os);
	return os;
}

