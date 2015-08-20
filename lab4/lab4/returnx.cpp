#include "returnx.h"
#include "movie.h"
#include "store.h"

//---------------------------Constructor----------------------------------//
//sets the data of a return derived class from transaction
Returnx::Returnx()
{
	//returns always have an action of 'R'
	action = 'R';
	//it's customer and movie associated with the trans init as NULL
	//so that they are not garbage
	customer = NULL;
	movie = NULL;
}

//---------------------------Destructor-----------------------------------//
//no need for clean up since it is not dynamic
Returnx::~Returnx()
{
}

//--------------------------Factory Constructor---------------------------//
//utilized for the Transaction Factory to create a blank Return obj
Transaction* Returnx::create() const
{
	return new Returnx;
}

//--------------------------Pretty Prints---------------------------------//
//this method uses the ostream as a reference to alter the stream and 
//print out the data stored inside of an object, it calls on movies
//print movie method to be shown in historys as properly formatted
void Returnx::print(ostream& os) const
{
	os << "Return " << movie->getFormat() << " ";
	movie->printMovie(os);
	os << "\n"; 
}

//--------------------------Set Data--------------------------------------//
//whenever we call set data in the return transaction
//we know everything has been set correctly and the customer and movie
//will be fine such that we can simply set the data and do no error 
//checking
void Returnx::setData(Customer* cust, Movie* mov)
{
	customer = cust;
	movie = mov;
}

//--------------------------------Execute---------------------------------//
//this method performs the actions for the Return object, using the
//store as a parameter to access the inventory and alter accordingly
//it also uses the file stream to read in the information
//according to formatting specifications, setting it for this specified
//derived transaction class
bool Returnx::execute(ifstream& file, Store& st)
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
				cout << "Invalid movie. Transaction could not be"
					<< "executed.\n";
				//no need for clean up since tempMov is still NULL
				return false;
			}
			else
			{
				//everything worked, now we try to set the data
				//from the format specifications of a return
				//movie, and if this didn't work, the movie was 
				//created so we must clean this up. otherwise, we try
				//to return the movie from the inventory
				if (!tempMov->readTrans(file))
				{
					delete tempMov;
					tempMov = NULL;
					return false;
				}
				else
				{
					if (!cust->returnMovie(tempMov))
					{
						cout << "Invalid movie. Transaction could not be "
							<< "executed.\n";
						delete tempMov;
						tempMov = NULL;

						return false;
					}
					else
					{
						Movie* mov;
						//use a movie locator and a movie return value
						//to try to return the movie from the stores
						//inventory, if the return couldn't occur
						//we must delete the temporary movie
						if (!st.getInventory().returnMovie(mov, tempMov))
						{
							//if we couldn't return we must clean up
							cout << "Invalid movie." <<
								"Transaction could not be "
								<< "executed.\n";
							delete tempMov;
							tempMov = NULL;

							return false;
						}
						else
						{
							//otherwise everything worked out perfectly
							//so the data is set and the customer
							//adds this transaction to his/her trans hist
							//and clean up our temp mov
							setData(cust, mov);
							//cust->returnMovie(mov);
							delete tempMov;
							tempMov = NULL;
							cust->addTransaction(this);
							return true;
						}
					}
				}
			}
		}
	}
}

