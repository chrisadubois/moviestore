#include "store.h"


//---------------------------Constructor----------------------------------//
//Constructor for the store, goes through the array of Customer pointers
//setting all of the pointers to NULL so they do not point to garbage
Store::Store()
{
	for (int i = 0; i < CUSTOMERIDCODELIMIT; i++)
	{
		customers[i] = NULL;
	}
}


//---------------------------Destructor-----------------------------------//
//this method deletes all the customers in the store by looping through
//the array of the customers. it does not need to delete the movies
//because the movie bst handles that
Store::~Store()
{
	for (int i = 0; i < CUSTOMERIDCODELIMIT; i++)
	{
		delete customers[i];
		customers[i] = NULL;
	}
}

//--------------------------------Show Inventory---------------------------//
//this method calls on the inventory's abstracted method to print the dramas
//classics and funnies stored in the inventory
void Store::showInventory() const
{
	storeInventory.printInventoryDramas();
	storeInventory.printInventoryClassics();
	storeInventory.printInventoryFunnies();
}

//---------------------------Show Customer History-------------------------//
//this method prints out the customers history using the abstracted method
//calling on the customer list to print the history of a customer, it
//knows that the identification code is correct
void Store::showCustomerHistory(const int ID) const
{
	customers[ID]->printHistory();
}

//------------------------------hash--------------------------------------//
//hash Method for customers, which takes a const Customer reference as
//its parameter. Returns the Customer's ID as the value
int Store::hash(const Customer& cust) const
{
	return cust.getIDValue();
}

//--------------------------buildInventory--------------------------------//
//takes a string representing a file name as a parameter, and creaes an
//ifstream to process the file and create the inventory basd on the given
//Movies in the file. 
void Store::buildInventory(const string& file)
{
	//Create the ifstream
	ifstream fileIn(file);
	//Print an error and return if the file could not be opened
	if (!fileIn)
	{
		cout << "The file " << file << "could not be opened.\n";
		return;
	}
	//Character for the genre of movie
	char c;
	//Until the end of file
	while (!fileIn.eof())
	{
		//Read in the genre
		fileIn >> c;
		//Return if the file has ended
		if (fileIn.eof())
		{
			return;
		}
		//Movie pointer calling create it, passing the genre char
		Movie* addMov = movieFact.createIt(c);
		//If the Movie pointer is NULL, the genre char was bad
		//Print an error, get the rest of the line and continue
		if (addMov == NULL)
		{
			cout << "Invalid Movie genre. Cannot create Movie.\n";
			string no;
			getline(fileIn, no, '\n');
			continue;
		}
		else
		{
			//If the data was set properly, add the Movie to the Inventory
			if (addMov->setData(fileIn))
			{
				storeInventory.addMovie(addMov);
			}
			//Otherwise print an error, get the rest of the line, delete
			//the Movie and set the pointer to NULL
			else
			{
				cout << "Invalid Movie data. Cannot create Movie.\n";
				string no;
				getline(fileIn, no, '\n');
				delete addMov;
				addMov = NULL;
			}
		}
	}
}

//-----------------------processTransactions------------------------------//
//takes a string representing a file name as a parameter, and creaes an
//ifstream to process the file and create the transactions and process
//them based on the information given within the file
void Store::processTransactions(const string& file)
{
	//Create the ifstream
	ifstream fileIn(file);
	//Print an error and return if the file could not be opened
	if (!fileIn)
	{
		cout << "The file " << file << "could not be opened.\n";
		return;
	}
	//Character to read the Transaction type
	char c;
	//Until the end of file
	while (!fileIn.eof())
	{
		//Read in the Transaction type
		fileIn >> c;
		//Return if at the end of file
		if (fileIn.eof())
		{
			return;
		}
		else
		{
			//Trarnsaction pointer calling create it, passing Transaction
			//type char
			Transaction* addTrans = transactionFact.createIt(c);
			//If addTrans is NULL, the Transaction type char was invalid
			//Get the rest of the line, print an error and continue
			if (addTrans == NULL)
			{
				string no;
				getline(fileIn, no, '\n');
				cout << "Invalid Transaction Command.\n";
				continue;
			}
			else
			{
				//If the transaction was executed correctly, continue
				if (addTrans->execute(fileIn, *this))
				{
					continue;
				}
				//Otherwise get the rest of the line, delete the Transaction
				//and set the Transaction pointer to NULL
				else
				{
					string no;
					getline(fileIn, no, '\n');
					delete addTrans;
					addTrans = NULL;
				}
			}
		}

	}
}

//-------------------------buildCustomerList------------------------------//
//takes a string representing a file name as a parameter, and creaes an
//ifstream to process the file and create the Customers and add them
//to the Customer list baesed on the information given within the file
void Store::buildCustomerList(const string& file)
{
	//Create the ifstream
	ifstream fileIn(file);
	//Print an error and return if the file could not be opened
	if (!fileIn)
	{
		cout << "The file " << file << "could not be opened.\n";
		return;
	}
	//Until the end of file
	while (!fileIn.eof())
	{
		//Pointer to a new customer
		Customer* addCust = new Customer;
		//If the data was set appropriately
		if (addCust->setData(fileIn))
		{
			//If the customer was added appropriately, continue
			if (addCustomer(*addCust))
			{
				continue;
			}
			//Otherwise delete the customer and set the pointer
			//to NULL
			else
			{
				delete addCust;
				addCust = NULL;
			}
		}
		//If the data was not set appropriately, get the rest of the line,
		//delete the customer, set the pointer to NULL and continue
		else
		{
			string no;
			getline(fileIn, no, '\n');
			delete addCust;
			addCust = NULL;
			continue;
		}
	}
	return;
}

//----------------------------addCustomer---------------------------------//
//Method to add a Customer to the list of Customers for the Store
//Takes a Customer reference as a parameter
bool Store::addCustomer(Customer& addCust)
{
	//Hash the customer to get their ID
	int custAddIdx = hash(addCust);
	//If the ID location in the list is NULL, add the customer and return
	//true
	if (customers[custAddIdx] == NULL)
	{
		customers[custAddIdx] = &addCust;
		return true;
	}
	//Otherwise print an error and return false
	else
	{
		cout << "Customer already exists with this ID number.\n";
		return false;
	}
}

//----------------------------getCustomer---------------------------------//
//getCustomer to return the desired Customer from the Customer list based
//on the given ID which the method takes as a parameter
Customer* Store::getCustomer(const int custID) const
{
	//If the ID is invalid, return NULL
	if (custID < 0 || custID > 9999)
	{
		return NULL;
	}
	//Otherwise return the customer at that ID index
	else
	{
		return customers[custID];
	}
}

//----------------------------getInventory--------------------------------//
//getInventory to return the Store's inventory for use by Transactions
//Const all around to prevent manipulation the Inventory
const Inventory& Store::getInventory() const
{
	return storeInventory;
}

//---------------------------getMovieFact---------------------------------//
//getMovieFact to return the Store's Movie Factory for use by Transactions
//Const all around to prevent manipulation of the Movie Factory
const MovieFactory& Store::getMovieFact() const
{
	return movieFact;
}


