#ifndef CUST_TRANS_HIST_H
#define CUST_TRANS_HIST_H
#include <iostream>
#include "transaction.h"
using namespace std;
//---------------------------------------------------------------------------
// CustTransHist class: stores Customer Transactions in the order that
// they occur to simplify History Transactions
//
// Implementation and Assumptions
// -- Assumes valid parameters are passed since Transactin objects validate
//    given information before they are created
// -- Uses a Linked List for storing the Customer Transactions
// -- Transactions are inserted at the end of the list for ordering of 
//    occurence
// -- Uses a struct to hold Transaction information and build the list
//---------------------------------------------------------------------------
//    |head|->|Transaction*|next|->|Transaction*|next|->...<-|tail|
//using the tail in this case was beneficial because it allowed
//for quick inserts at the very end of the list
//we only needed the list to store transactions and knew that we would need
//o(n) to traverse the list regardless. holding the tail however, makes
//inserting o(1)
class CustTransHist
{
public:
	CustTransHist();
	~CustTransHist();

	//Print method for a History Transaction printing Customer's Transaction
	//history in the order that they occur 
	void displayTransactionHistory() const;
	//Insert for inserting a new Transaction at the end of the lsit
	void insert(Transaction*);
	
private:
	//Struct Node for Linked List
	//Node pointer to next Node
	//Transaction pointer to the Transaction performed
	struct custtranshistnode
	{
		custtranshistnode* next;
		Transaction* custtranshistdata;
	};
	//Head pointer to first Node in Linked List
	custtranshistnode* head;
	//Tail pointer to last Node in Linked List for easy Insertion
	custtranshistnode* tail;
};
#endif