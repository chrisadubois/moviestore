#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "transaction.h"
#include "movie.h"
#include "person.h"
#include "custmovielist.h"
#include "custtranshist.h"
//---------------------------------------------------------------------------  
// Customer class: contains information about a Customer who is related
// to the Store and can perform Transactions with the Store
//
// Implementation and Assumptions
// -- Assumes valid parameters are passed into methods, since the objects
//    validate themselves before they are actually created
// -- Assumes Customer information won't change after the Customer is created
// -- Allows for access to customer ID
// -- Allows for adding Transaction to the CustTransHist and printing
//    the Customer's history
// -- Allows for printing of the Customer and their information
//---------------------------------------------------------------------------

class Customer : public Person
{
public:
	Customer();
	//Virtual destructor due to Inheritence
	virtual ~Customer();
	//setId used for setting the customer's ID
	//Virtual print method to print the Customer's information
	virtual void print(ostream&) const override;
	//PrintHistory for printing CustTransHist
	void printHistory() const;
	virtual bool setData(ifstream&) override;
	
	//getId for access and viewing the Customer's ID number
	string getID() const;
	//getIdValue to get the actual Int representing the Customer's 
	//ID number
	int getIDValue() const;
	//addTransaction for adding a Transaction to the Customer's CustTransHist
	bool addTransaction(Transaction*);
	
	//remove a movie from the customer movie list and return it
	bool returnMovie(Movie*);
	//add a movie to the customer movie list 
	bool borrowMovie(Movie*);
	
private:
	//ID number of Customer
	string id;
	//CustTransHist for Transaction history
	CustTransHist transactions;
	//Linked list of Movie pointers for holding rentals
	CustMovieList movieList;
};
#endif