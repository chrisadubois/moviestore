#ifndef SHOW_H
#define SHOW_H
#include "transaction.h"
#include <fstream>
#include <iostream>
//#include "inventory.h"
class Store;
using namespace std;
//---------------------------------------------------------------------------
// Show class: child class of Transaction for displaying the Store's
// inventory in a logical manner and all related information
// 
// Implementation and Assumptions
// -- Assumes valid parameters are passed for execute (istream)
// -- Handles invalid commands while reading, but data types must be
//    valid and ordered correctly
// -- Contains methods for supporting the TransactionFactory
// -- Unique execute method for Show Transaction
// -- Contains necessary overridden methods as determined by the
//    Parent class (Transaction)
//---------------------------------------------------------------------------
class Show : public Transaction
{
public:
	Show();
	~Show();
	//Overridden execute method for executing the Show Transaction
	virtual bool execute(ifstream&, Store&) override;
	//Create method for creating and returning new Show object for
	//TransactionFactory
	virtual Transaction* create() const override;
	

private:
	//Overridden print method to print the Show transaction information
	virtual void print(ostream&) const override;
};
#endif
