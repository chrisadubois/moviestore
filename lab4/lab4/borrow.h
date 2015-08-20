#ifndef BORROW_H
#define BORROW_H
#include "transaction.h"
#include "customer.h"
class Movie;
class Store;
//---------------------------------------------------------------------------
// Borrow class: child class of Transaction for allowing a customer to Borrow
// a specified Movie from the Store's inventory
//
// Implementation and Assumptions
// -- Assumes valid parameter types are passed
// -- Handles invalid information, but the data type itself must be correct
// -- Create method for the TransactionFactory
// -- Unique execute method for the Borrow Transaction
// -- Contains additional information related to the Transaction
//---------------------------------------------------------------------------

class Borrow : public Transaction
{
public:
	Borrow();
	~Borrow();
	//Create method for returning a new Borrow object for the 
	//TransactionFactory
	virtual Transaction* create() const override;
	//Execute method for reading from the file and executing a Borrow
	//Transaction
	virtual bool execute(ifstream&, Store&) override;
private:
	//Virtual print method for inheritence and printing Borrow 
	//Transaction information
	virtual void print(ostream&) const override;
	//setData method for setting the Customer and Movie information
	void setData(Customer*, Movie*);
	//Customer associated with Borrow Transaction
	Customer* customer;
	//Movie associated with Borrow Transaction
	Movie* movie;
};
#endif
