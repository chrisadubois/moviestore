#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <istream>
class Store;
using namespace std;
//---------------------------------------------------------------------------
// Transaction parent class: parent class for various types of transactions
// which stores information related to the transaction and allows for 
// operations to be performed based on the transaction type
//
// Implementation and Assumptions
// -- Assumes parameters passed are of the appropriate type 
// -- Handles invalid commands, but data type and ordering must be correct
// -- Exectues transaction by reading file based on which Transaction type
//    is invoking the method
//---------------------------------------------------------------------------

class Transaction
{
	//Overloaded ostream operator to print a Transaction and its information
	friend ostream& operator<<(ostream&, const Transaction&);
public:
	Transaction();
	//Virutal destructor for proper deletion of children
	virtual ~Transaction();
	//Pure virtual execute method for executing the Transaction
	virtual bool execute(ifstream&, Store&) = 0;
	//Pure virtual create method for creating Transaction for
	//for the TransactionFactory class
	virtual Transaction* create() const = 0;
protected:
	//Char action for Transaction type
	char action;
	//Pure virtual print method used by the ostream operator to print
	//a Transaction and its information
	virtual void print(ostream&) const = 0;
};
#endif
