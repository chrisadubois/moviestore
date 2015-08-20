#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H
#include "transaction.h"
class History;
class Borrow;
class Returnx;
class Show;
//#include "history.h"
//#include "borrow.h"
//#include "returnx.h"
//#include "show.h"
static const int TRANSACTIONLIMIT = 26;
//---------------------------------------------------------------------------
// TransactionFactory class: used for creating Transaction objects through
// while avoiding swtich statements for real OO programming
//
// Implementation and Assumptions
// -- Assumes parameters passed are of the correct type (char)
// -- Handles invalid commands appropriately
// -- Returns new Transaction objects 
// -- createIt method used to call a Create method on individual Transactions
// -- Able to hash characters representing Transactions
//---------------------------------------------------------------------------

class TransactionFactory
{
public:
	TransactionFactory();
	~TransactionFactory();

	//CreateIt for creating and returning a new Transaction object
	//based on the hash function
	Transaction* createIt(const char) const;

private:
	//Array of  26 Transaction pointers to new Transaction objects
	//or to NULL if a Transaction does not exist at that index
	Transaction* transactions[26];

	//hash function which hashes Transaction character to appropriate
	//index within Transaction pointer array
	int hash(const char) const;
};
#endif
