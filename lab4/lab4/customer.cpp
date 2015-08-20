#include "customer.h"

//---------------------------Constructor----------------------------------//
//Customer does not require anything to be set to be constructed
//all instance variables are static
Customer::Customer()
{
}

//---------------------------Destructor-----------------------------------//
//Customer does not require clean up as all isntance variables are static
Customer::~Customer()
{
}

//--------------------------Pretty Prints---------------------------------//
//this method uses the ostream as a reference to alter the stream and 
//print out the data stored inside of an object
void Customer::print(ostream& os) const
{
	os << id << " " << getFirstName() << " " << getLastName() << "\n";
}

//--------------------------Pretty Prints---------------------------------//
//this method is abstracted to print out a customers history as it only
//calls on the transactions prints method to loop through and print
//out all the transaction
void Customer::printHistory() const
{
	transactions.displayTransactionHistory();
}

//--------------------------Set Data--------------------------------------//
//This method sets the data for a customer object checking at each level
//and stepping through the file stream 
bool Customer::setData(ifstream& file)
{
	string idCheck;
	file >> idCheck;
	if (file.eof())
	{
		return false;
	}
	if (idCheck.length() != 4)
	{
		cout << "Customer's id is not correctly formatted.\n";
		return false;
	}
	else
	{
		//convert the string ID into an int
		//this will break if the text file is inputted in the format
		//with a 4 letter string as the first thing on a new line
		int ID = atoi(idCheck.c_str());
		//id cannot be a negative number
		if (ID < 0)
		{
			cout << "Customer's id is not correctly formatted.\n";
			return false;
		}
		//if there is only the id in there, this isn't a customer
		else if (file.eof() || file.peek() == '\n')
		{
			cout << "Customer name is not correctly formatted.\n";
			return false;
		}
		//everything worked, customer had a last name and a first name
		else
		{
			file >> lastName;
			if (file.eof() || file.peek() == '\n')
			{
				cout << "Customer name is not correctly formatted.\n";
				return false;
			}
			file >> firstName;
			id = idCheck;
			return true;
		}
	}
}

//-----------------------------Get ID-------------------------------------//
//this method returns a copy of the customers id as a string
string Customer::getID() const
{
	return id;
}

//-------------------------------Get ID------------------------------------//
//this method returns the actual value of the string stored as the ID
//for the customer, this is used for input validation
int Customer::getIDValue() const
{
	return atoi(id.c_str());
}

//-------------------------------Add Transaction---------------------------//
//this method adds to the customers transactions history list
//by inserting
bool Customer::addTransaction(Transaction* ins)
{
	transactions.insert(ins);
	return true;
}

//-----------------------------Borrow Movie--------------------------------//
//this method adds to the customers movie list by inserting
//to the end of the list
bool Customer::borrowMovie(Movie* bor)
{
	movieList.insert(bor);
	return true;
}

//----------------------------Return Movie---------------------------------//
//This method returns a movie from the customers movie list
//if the movie cannot be returned then we don't remove it from the
//customer's movie list, otherwise it uses the customers movie list
//data structure to remove the movie appropriately
bool Customer::returnMovie(Movie* ret)
{
	if (movieList.remove(ret))
	{
		return true;
	}
	else
	{
		//Transactions.addFailure("Failure");
		cout << "The Movie could not be returned.\n";
		return false;
	}
}
