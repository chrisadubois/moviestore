#include "borrow.h"
#include "movie.h"
#include "store.h"

//---------------------------Constructor----------------------------------//
//sets the data of a borrow derived class from transaction
Borrow::Borrow()
{
	//borrows always have an action of 'B'
	action = 'B';
	//it's customer and movie associated with the trans init as NULL
	//so that they are not garbage
	customer = NULL;
	movie = NULL;
}

//---------------------------Destructor-----------------------------------//
//no need for clean up since it is not dynamic
Borrow::~Borrow()
{
}

//--------------------------Factory Constructor---------------------------//
//utilized for the Transaction Factory to create a blank Borrow obj
Transaction* Borrow::create() const 
{
	return new Borrow;
}

//--------------------------Pretty Prints---------------------------------//
//this method uses the ostream as a reference to alter the stream and 
//print out the data stored inside of an object it calls on movies
//print movie method to be shown in historys as properly formatted
void Borrow::print(ostream& os) const
{
	os << "Borrow " << movie->getFormat() << " ";
	movie->printMovie(os);
	os << "\n";
}

//--------------------------Set Data--------------------------------------//
//whenever we call set data in the borrow transaction
//we know everything has been set correctly and the customer and movie
//will be fine such that we can simply set the data and do no error 
//checking
void Borrow::setData(Customer* cust, Movie* mov)
{
	customer = cust;
	movie = mov;
}

//--------------------------------Execute---------------------------------//
//this method performs the actions for the Borrow object, using the
//store as a parameter to access the inventory and alter accordingly
//it also uses the file stream to read in the information
//according to formatting specifications, setting it for this specified
//derived transaction class
bool Borrow::execute(ifstream& file, Store& st)
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
		char format;
		file >> format;
		//read in the format, the format is specified to only be DVDs
		if (format != 'D')
		{
			cout << "Invalid format. Transaction could not be executed.\n";
			//no need for clean up since Formaat is not dynamic
			return false;
		}
		else
		{
			char genre;
			file >> genre;
			//read in the genre and then use the stores movie factory
			//to create a temporary movie of this genre,
			//however, if the genre did not correspond to an appropriate
			//movie, return false
			Movie* tempMov = st.getMovieFact().createIt(genre);
			if (tempMov == NULL)
			{
				cout << "Invalid movie. Transaction could not be "
					<< "executed.\n";
				//no need for clean up since tempMov is still NULL
				return false;
			}
			else
			{
				//everything worked, now we try to set the data
				//from the format specifications of a borrow
				//movie, and if this didn't work, the movie was 
				//created so we must clean this up. otherwise, we try
				//to borrow the movie from the inventory
				if (!tempMov->readTrans(file))
				{
					delete tempMov;
					tempMov = NULL;
					return false;
				}
				else
				{
					Movie* mov = NULL;
					//use a movie locator and a movie return value
					//to try to borrow the movie from the stores
					//inventory, if the borrow couldn't occur
					//we must delete the temporary movie
					if (!st.getInventory().borrowMovie(mov, tempMov))
					{
						cout << "Invalid movie. Transaction could not be "
							<< "executed.\n";
						delete tempMov;
						tempMov = NULL;

						return false;
					}
					else
					{
						//otherwise everything has worked out so far
						//so we set the data of the borrow transaction
						//because we already know the movie
						//and the customer is accurate
						setData(cust, mov);
						//if we couldn't borrow we must clean up
						if (!cust->borrowMovie(mov))
						{
							cout << "Invalid movie." <<
								"Transaction could not be "
								<< "executed.\n";
							delete tempMov;
							tempMov = NULL;
							return false;
						}
						//otherwise everything worked out perfectly
						//so the data is set and the customer
						//adds this transaction to his/her trans hist
						//and clean up our temp mov
						cust->addTransaction(this);
						delete tempMov;
						tempMov = NULL;
						return true;
					}
				}
			}
		}
	}
}

