#ifndef HISTORY_H
#define HISTORY_H
#include "transaction.h"
#include "customer.h"
class Store;

//---------------------------------------------------------------------------
// History class: child class of Transaction for displaying any Customer's 
// history of Transactions with the Store
//
// Implementation and Assumptions
// -- Assumes valid parameters are passed into arguments
// -- Handles invalid information and commands, but data type and ordering
//    must be correct
// -- Unqiue execute method for performing a History Transaction
// -- Create method to support the TransactionFactory
// -- Contains additional information related to History Transaction
//---------------------------------------------------------------------------

class History : public Transaction
{
public:
	History();
	~History();
	//Execute method for performing a History Transaction
	virtual bool execute(ifstream&, Store&) override;
	//Create method for returning a new History object for the 
	//TransactionFactory
	virtual Transaction* create() const override;
private:
	//Customer related to the History Transaction
	Customer* customer;

	//setData for setting the Customer related to the History Transaction
	void setData(Customer*);

	//Virtual print method to print the History transaction information
	virtual void print(ostream&) const override;
};
#endif

