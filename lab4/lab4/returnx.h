#ifndef RETURN_H
#define RETURN_H
//#include "transaction.h"
#include "customer.h"
//#include "movie.h"
#include "transaction.h"
class Movie;
class Store;

//---------------------------------------------------------------------------
// Return class: child class of Transaction for a Customer Returning a Movie
// to the Store's inventory.
//
// Implementation and Assumptions
// -- Assumes valid parameters are passed into methods
// -- Handles invalid information given in the input file, but data type
//    and ordering must be correct
// -- Unique execute method for Return transaction
// -- Create method for supporting TransactionFactory
// -- Contains additional information related to the Return Transaction
//---------------------------------------------------------------------------

class Returnx : public Transaction
{
public:
	Returnx();
	~Returnx();


	//Overridden create method to return a new Returnx object
	//for the TransactionFactory
	virtual Transaction* create() const override;
	//Execute method for performing a Return Transaction
	virtual bool execute(ifstream&, Store&) override;

	
private:
	//Customer related to Return Transaction
	Customer* customer;
	//Movie related to Return Transaction
	Movie* movie;

	//setData for setting the Customer and Movie information related
	//to the Return Transaction
	void setData(Customer*, Movie*);
	//Overridden print method to print the Returnx information
	virtual void print(ostream&) const override;
};
#endif

