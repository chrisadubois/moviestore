#include "classic.h"

//---------------------------Constructor----------------------------------//
//Constructor does not need to set anything as all instance variables
//are static, just needs to create a new Classic obj
Classic::Classic()
{
	movieCount = 0;
	inStock = 0;
}

//---------------------------Destructor-----------------------------------//
//there are no dynamically allocated variables to clean up after
Classic::~Classic()
{
}

//--------------------------Factory Constructor---------------------------//
//this method returns a new Classic object for use by the factory
Movie* Classic::create() const
{
	return new Classic;
}

//--------------------------Pretty Prints---------------------------------//
//this method uses the ostream as a reference to alter the stream and 
//print out the data stored inside of an object
//using specification iostream formatting and justification
ostream& Classic::printMovie(ostream& outStream) const
{
	outStream.setf(ios::left, ios::adjustfield);
	outStream << left << setfill(' ') << setw(MAXMOVIETITLEPRINT - 4) << 
		title.substr(0, MAXMOVIETITLEPRINT - 4) << " " << 
		setw(MAXMOVIEDIRECTORPRINT - 3) << 
		movieDirector.getName().substr(0, MAXMOVIEDIRECTORPRINT - 3) << " " << 
		setw(MAXMOVIEYEARPRINT) << pubYear << " " << 
		setw(MAXMOVIEMONTHPRINT) << pubMonth << " " <<
		setw(MAXMOVIEACTORPRINT - 3) << 
		movieActor.getFirstName() + " " +
		movieActor.getLastName().substr(0, MAXMOVIEACTORPRINT - 3);
	return outStream;
}

//--------------------------Pretty Prints---------------------------------//
//this method uses the ostream as a reference to alter the stream and 
//print out the data stored inside of an object
//using specification iostream formatting and justification
ostream& Classic::print(ostream& os) const
{
	os.setf(ios::left, ios::adjustfield);
	os << left << setfill(' ') << setw(MAXMOVIEINPRINT) << inStock 
		<< setw(MAXMOVIEOUTPRINT) << movieCount - inStock << 
		setw(MAXMOVIETITLEPRINT) << title.substr(0, MAXMOVIETITLEPRINT) << 
		" " << setw(MAXMOVIEDIRECTORPRINT) <<
		movieDirector.getName().substr(0, MAXMOVIEDIRECTORPRINT) <<
		" " << setw(MAXMOVIEYEARPRINT) << pubYear << " " << 
		setw(MAXMOVIEMONTHPRINT) << pubMonth << " " <<
		movieActor.getFirstName() + " " + 
		movieActor.getLastName().substr(0, MAXMOVIEACTORPRINT) << "\n";
	return os;
}

//--------------------------Set Data--------------------------------------//
//this method sets the data of the classic movie, using the file
//to increment through the text line and create appropriately
//formatted classic movies according to specific formatting of a classic
bool Classic::setData(ifstream& file)
{
	//use formats setFormat to make the movie
	//no need for clean up
	if (!format.setFormatMakeMovie(file))
	{
		return false;
	}
	else
	{
		//use movieDirectors setData
		//no need for clean up
		if (!movieDirector.setData(file))
		{
			return false;
		}
		else
		{
			//read the whole rest of the line for the title
			//setting the title as this string up to the comma delim
			//no need for clean up
			getline(file, title, ',');
			if (!movieActor.setData(file))
			{
				return false;
			}
			else
			{
				//such that the file hasn't ended yet, or the 
				//line hasn't ended
				//no need for clean up
				if (file.eof() || file.peek() == '\n')
				{
					cout << "Movie is not formatted correctly.\n";
					return false;
				}
				//pub month validation
				//no need for clean up
				//such that the file hasn't ended yet, or the 
				//line hasn't ended
				file >> pubMonth;
				if (file.eof() || file.peek() == '\n' ||
					pubMonth < 1 || pubMonth > 12)
				{
					cout << "Movie is not formatted correctly.\n";
					return false;
				}
				//pub year validation
				//the first movie was made in 1878
				//such that the file hasn't ended yet, or the 
				//line hasn't ended
				//no need for clean up
				file >> pubYear;
				if (pubYear < 1878 || pubYear > 2016)
				{
					cout << "Movie is not formatted correctly.\n";
					return false;
				}
				//this if statement crashed on linux?
				/*if (file.peek() != '\n')
				{
					cout << "There is too much movie information provided\n";
					return false;
				}*/
				return true;
			}
		}
	}
}

//---------------------------Read Trans----------------------------------//
//this method reads a transaction from a specifically formatted
//text file to read the transaction data for a classic movie once
//determined that the movie is a classic, using the ifstream text file
//there is no clean up necessary for this method
bool Classic::readTrans(ifstream& file)
{
	file >> pubMonth;
	//months cannot be less than 1, and greater than 12
	if (pubMonth < 1 || pubMonth > 12)
	{
		cout << "Movie is not formatted correctly.\n";
		return false;
	}
	file >> pubYear;
	//the first movie made was in 1878 named Horse
	//and the movie couldn't be produced in the future
	if (pubYear < 1878 || pubYear > 2016)
	{
		cout << "Movie is not formatted correctly.\n";
		return false;
	}
	//uses actors set data passing the rest of the file
	if (!(movieActor.setData(file)))
	{
		cout << "Movie is not formatted correctly.\n";
		return false;
	}
	return true;
}


//-----------------------------Get Publication Month---------------------//
//returns a copy of the integer stored as the publication month
//for the classic object
int Classic::getPubMonth() const
{
	return pubMonth;
}

//---------------------------operator==-----------------------------------//
//this method returns a bool based on whether or not the left operand
//classic is equivalent to the right operand classic, using instance
//variable checking of each
//the significant thing here is the static cast, which casts a Movie down
//to a classic for possible comparison
bool Classic::operator==(const Movie& movie) const
{
	const Classic& classicMv = static_cast<const Classic&>(movie);
	return (pubYear == classicMv.pubYear && pubMonth == classicMv.pubMonth &&
		movieActor.getFirstName() == classicMv.movieActor.getFirstName() &&
		movieActor.getLastName() == classicMv.movieActor.getLastName());
}

//---------------------------operator!=-----------------------------------//
//this method returns a bool based on whether or not the left operand
//classic is equivalent to the right operand classic, using instance
//variable checking of each
//the significant thing here is the static cast, which casts a Movie down
//to a classic for possible comparison
bool Classic::operator!=(const Movie& movie) const
{
	const Classic& classicMv = static_cast<const Classic&>(movie);
	//logically, return the opposite of the == operator
	return !(*this == classicMv);
}

//---------------------------operator<=-----------------------------------//
//this method returns a bool based on whether or not the left operand
//classic is less than or equal to to the right operand classic, 
//using instance variable checking of each.
//it will cascade down using the comparisons defined in the requirements
//checking if one is less than the other, and if not, cascading to equal to
//if then equal to, continue (almost in a recursive fashion
//the significant thing here is the static cast, which casts a Movie down
//to a classic for possible comparison
bool Classic::operator<=(const Movie& movie) const
{
	const Classic& classicMv = static_cast<const Classic&>(movie);
	//start with the year
	if (pubYear < classicMv.pubYear)
	{
		return true;
	}
	//if the years are the same, cascade down
	else if (pubYear == classicMv.pubYear)
	{
		//check the month
		if (pubMonth < classicMv.pubMonth)
		{
			return true;
		}
		//if the months are the same, cascade down
		else if (pubMonth == classicMv.pubMonth)
		{
			//check the first name lexicographical values
			if (movieActor.getFirstName() < 
				classicMv.movieActor.getFirstName())
			{
				return true;
			}
			//if the first name lexicographical values are the same,
			//cascade down
			else if (movieActor.getFirstName() ==
				classicMv.movieActor.getFirstName())
			{
				//check the last piece of comparison
				//using less than or equal to
				//with string comparison<=, because at this point
				//they are entirely equivalent
				return (movieActor.getLastName() <= 
					classicMv.movieActor.getLastName());
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//---------------------------operator>=-----------------------------------//
//this method returns a bool based on whether or not the left operand
//classic is less than or equal to to the right operand classic, 
//using instance variable checking of each.
//it will cascade down using the comparisons defined in the requirements
//checking if one is less than the other, and if not, cascading to equal to
//if then equal to, continue (almost in a recursive fashion
//the significant thing here is the static cast, which casts a Movie down
//to a classic for possible comparison
bool Classic::operator>=(const Movie& movie) const
{
	const Classic& classicMv = static_cast<const Classic&>(movie);
	//start with the year
	if (pubYear > classicMv.pubYear)
	{
		return true;
	}
	//if same, cascade down
	else if (pubYear == classicMv.pubYear)
	{
		//move to the month
		if (pubMonth > classicMv.pubMonth)
		{
			return true;
		}
		//if same, cascade down
		else if (pubMonth == classicMv.pubMonth)
		{
			//move to the name
			if (movieActor.getFirstName() >
				classicMv.movieActor.getFirstName())
			{
				return true;
			}
			//if same, cascade down
			else if (movieActor.getFirstName() ==
				classicMv.movieActor.getFirstName())
			{
				//check the last piece of comparison
				//using less than or equal to
				//with string comparison>=, because at this point
				//they are entirely equivalent
				return (movieActor.getLastName() >=
					classicMv.movieActor.getLastName());
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//---------------------------operator<------------------------------------//
//needs to check only one thing after doing the base class to 
//derived class static cast, which is the pub year
//because if the pub year is not less than, than the whole thing is not
//less than
bool Classic::operator<(const Movie& movie) const
{
	const Classic& classicMv = static_cast<const Classic&>(movie);
	return (pubYear < classicMv.pubYear);
}

//---------------------------operator>------------------------------------//
//needs to check only one thing after doing the base class to 
//derived class static cast, which is the pub year
//because if the pub year is not greater than, than the whole thing is not
//greater than
bool Classic::operator>(const Movie& movie) const
{
	const Classic& classicMv = static_cast<const Classic&>(movie);
	return (pubYear > classicMv.pubYear);
}

//--------------------------------Hash-----------------------------------//
//we map movies to hash table using the alphabet
//thus to map classics to c and to an array, it is simple to
//use ASCII values, always getting a value above 0
int Classic::hash() const
{
	return 'C' - 'A';
}