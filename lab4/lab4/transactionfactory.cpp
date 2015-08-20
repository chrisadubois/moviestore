#include "transactionfactory.h"
#include "borrow.h"
#include "returnx.h"
#include "history.h"
#include "show.h"

//---------------------------Constructor----------------------------------//
//the constructor for the factory sets all the values corresponding
//to the alphabetic hash array, in this case, most of the spots are NULL
//because there are only Borrows, Returns, Shows, and Historys
//but these are set using ASCII codes
TransactionFactory::TransactionFactory()
{
	for (int i = 0; i <TRANSACTIONLIMIT; i++)
	{
		transactions[i] = NULL;
	}
	transactions[1] = new Borrow;
	transactions[17] = new Returnx;
	transactions[18] = new Show;
	transactions[7] = new History;
}

//---------------------------Destructor-----------------------------------//
//the destructor for the factory loops through the alphabetic
//hash array and deletes all things that are not already empty
TransactionFactory::~TransactionFactory()
{
	for (int i = 0; i < TRANSACTIONLIMIT; i++)
	{
		if (transactions[i] != NULL)
		{
			delete transactions[i];
			transactions[i] = NULL;
		}
	}
}

//--------------------------------Hash------------------------------------//
//Using the alphabetic hash we can simply return the index value by taking
//our character subtracting a capital A to correspond with a sized 26 array
int TransactionFactory::hash(const char ch) const
{
	return ch - 'A';
}

//--------------------------Create It-------------------------------------//
//this method does error checking to ensure that we will return a valid
//object from the Transaction Factory using the hash index and checking with
//the alphabetic array
Transaction* TransactionFactory::createIt(const char ch) const
{
	int factoryIndex = hash(ch);
	//error checking for valid genres
	if (factoryIndex < 0 || factoryIndex > TRANSACTIONLIMIT)
	{
		return NULL;
	}
	else if (transactions[factoryIndex] == NULL)
	{
		return NULL;
	}
	return transactions[factoryIndex]->create();
}


