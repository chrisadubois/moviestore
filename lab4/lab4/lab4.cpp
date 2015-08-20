#include "store.h"
//thanks for a great quarter of 343 Professor Zander!!
//--Brody Schulke
//--Chris DuBois
int main()
{
	Store theStore;
	theStore.buildCustomerList("data4customers.txt");
	theStore.buildInventory("data4movies.txt");
	theStore.processTransactions("data4commands.txt");
	return 0;
}