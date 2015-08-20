#include "history.h"
#include "store.h"

//---------------------------Constructor----------------------------------//
//History objects always have a transaction action as 'H'
//and the dynamic customer pointer is set to null rather than garbage
//because the transaction does not have a customer associated with it
//until the file reading has been completed
History::History()
{
	action = 'H';
	customer = NULL;
}

//---------------------------Destructor-----------------------------------//
//we do not need to delete the customer associated with the transaction
//object because the customers are stored in the store and we don't want
//to delete the customer through the transaction, but only through the store
History::~History()
{
}

//--------------------------Factory Constructor---------------------------//
//utilized for the Transaction Factory to create a blank History obj
Transaction* History::create() const
{
	return new History;
}

//--------------------------Pretty Prints---------------------------------//
//this method uses the ostream as a reference to alter the stream and 
//print out the data stored inside of an object
void History::print(ostream& os) const
{
	os << action << " " << customer->getID() << "\n";
}

//--------------------------Set Data--------------------------------------//
//whenever we call set data in the History transaction
//we know everything has been set correctly and the customer
//will be fine such that we can simply set the data and do no error 
//checking
void History::setData(Customer* cust)
{
	customer = cust;
}

//--------------------------------Execute---------------------------------//
//this method performs the actions for the History object, using the
//store as a parameter to access the inventory and alter accordingly
//it also uses the file stream to read in the information
//according to formatting specifications, setting it for this specified
//derived transaction class
bool History::execute(ifstream& file, Store& st)
{
	int custIdx;
	file >> custIdx;
	Customer* cust = st.getCustomer(custIdx);
	//read the custtomer index and get the customer at that index
	//from the store, if the store doesn't have the customer at that
	//spot then the customer has not been created and we cannot do anything
	if (cust == NULL)
	{
		cout << "Invalid Customer ID. Transaction could not be executed.\n";
		//no need for clean up since Customer is still NULL
		return false;
	}
	else
	{
		//this if else block
		//ensures that customer print out will never wrap if the entire
		//name is greater than the additional 40 characters that
		//would fall off the edge
		//so this will truncate the name and keep the ID
		if (cust->getFirstName().length() + cust->getLastName().length() > 40)
		{
			cout.setf(ios::left, ios::adjustfield);
			cout << left << setfill(' ') <<
				"Customer Transaction History for " <<
				setw(40) << cust->getFirstName() + " " +
				cust->getLastName().substr(0, 40) << " " <<
				cust->getID() << "\n";
		}
		else
		{
			cout.setf(ios::left, ios::adjustfield);
			cout << left << setfill(' ') <<
				"Customer Transaction History for " <<
				cust->getFirstName() << " " <<
				cust->getLastName() << " " <<
				cust->getID() << "\n";
		}
		//we will call the customers print history method related
		//to transactions
		cust->printHistory();
		//then we set the customer pointer to null because this
		//object is now useless
		cust = NULL;
		//and we delete the history object because it is also useless
		delete this;
		return true;
	}
}

