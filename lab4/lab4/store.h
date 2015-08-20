#ifndef STORE_H
#define STORE_H
#include "inventory.h"
#include "customer.h"
#include "moviefactory.h"
#include "transactionfactory.h"
//class Borrow;
//class Returnx;
//class History;
//class Show;
#include "transaction.h"
#include <istream>
#include <string>
static const int CUSTOMERIDCODELIMIT = 10000;
using namespace std;
//---------------------------------------------------------------------------
// Store Class: Contains everything necessary for the MOVIE store to function
// -- able to read multiple types of files:
// ------ one for intializing the inventory of Movies
// ------ one for initalizing the container of MOVIE Store Customers
// ------ one for conducting multiple forms of Transactions
//
// Implementation and Assumptions
// -- Input files are formatted properly with correct data types:
// ------ Invalid inputs are handled, but data type must be correct
//
// -- MOVIE Store only contains DVD Movies of three Genres:
// ------ Funny, Classic, and Drama
//
// -- Uses two factories to create Transactions and Movie objects
// -- Customer IDs must be between 1000 and 9999 for hasing and storing
//---------------------------------------------------------------------------

class Store
{
public:
	Store();
	~Store();
	//ShowInventory method to print the entire Inventory
	void showInventory() const;
	//showCustomerHistory to print a Customer's history based on the 
	//give ID
	void showCustomerHistory(const int) const;
	//Build customer inventory
	void buildCustomerList(const string&);
	//addCustomer to add a new customer to the Customer array
	bool addCustomer(Customer&);
	//buildInventory takes a const string reference to make an istream
	//for reading from the file to build the inventory
	void buildInventory(const string&);
	//processTransactiosn takes a const string reference to make an istream
	//for reading from the file to process all Transactions
	void processTransactions(const string&);
	//getInvetory method to return the Inventory
	const Inventory& getInventory() const;
	//getMovieFact method to return the MovieFactory
	const MovieFactory& getMovieFact() const;
	//getCustomer method to return a Customer based on the given ID
	Customer* getCustomer(const int) const;
	//hash method for access and storing customers
	int hash(const Customer&) const;
	

private:
	//Inventory object for storing Movies
	Inventory storeInventory;
	//Array of Customer pointers to contain MOVIE Store Customers
	Customer* customers[CUSTOMERIDCODELIMIT];
	//MovieFactory object for creating Movie objects 
	MovieFactory movieFact;
	//TransactionFactory object for creating Transaction objects
	TransactionFactory transactionFact;

};
#endif