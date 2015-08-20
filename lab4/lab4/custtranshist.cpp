#include "custtranshist.h"

//---------------------------Constructor----------------------------------//
//constructor sets the two sided linkings to NULL
//so that they are not garbage
CustTransHist::CustTransHist()
{
	head = NULL;
	tail = NULL;
}

//---------------------------Destructor-----------------------------------//
//clean up all the data stored in the customers transactions history
//data structure (doubly sided linking) by traversing, and deleting
//each piece
CustTransHist::~CustTransHist()
{
	while (head != NULL)
	{
		custtranshistnode* temp = head->next;
		delete head->custtranshistdata;
		head->custtranshistdata = NULL;
		delete head;
		head = NULL;
		head = temp;
	}
	head = NULL;
	tail = NULL;
}


//--------------------------Pretty Prints---------------------------------//
//this method loops through the links calling on the ostream operator
//of the transaction
void CustTransHist::displayTransactionHistory() const
{
	custtranshistnode* cur = head;
	while (cur != NULL)
	{
		cout << *cur->custtranshistdata;
		cur = cur->next;
	}
	cout << "\n";
}

//---------------------------------Insert----------------------------------//
//this method adds transactions to the customers transaction history list
//and ensures that there is always a tail pointer to the end of the list as
//well because new transactions are always added to the tail
//to maintain ordering properties and for quick additions to the list
void CustTransHist::insert(Transaction* add)
{
	//the case that the list is empty
	if (head == NULL)
	{
		head = new custtranshistnode;
		head->custtranshistdata = add;
		tail = head;
		head->next = NULL;
		tail->next = NULL;
	}
	//the case that the list is not empty
	else
	{
		custtranshistnode* temp = new custtranshistnode;
		temp->custtranshistdata = add;
		tail->next = temp;
		tail = temp;
		tail->next = NULL;
	}
}