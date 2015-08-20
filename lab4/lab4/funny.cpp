#include "funny.h"


//---------------------------Constructor----------------------------------//
//Funny inherits from movie and simply needs to set the data
//to the standards of what creates the blank movie object
Funny::Funny()
{
	movieCount = 0;
	inStock = 0;
}

//---------------------------Destructor-----------------------------------//
//no dynamically allocated variables and thus no clean up is necessary
Funny::~Funny()
{
}

//--------------------------Create----------------------------------------//
//this method is used by the factory to return a new blanked out Funny 
//object
Movie* Funny::create() const
{
	return new Funny;
}

//--------------------------Read Trans-------------------------------------//
//this method sets the data for a transaction call on a Funny movie
//by using the directors set data 
//and then reading in the file and setting it for the funny movie
bool Funny::readTrans(ifstream& file)
{
	file.ignore(1);
	getline(file, title, ',');
	file >> pubYear;
	if (pubYear < 0 || pubYear > 2016)
	{
		cout << "Movie information is not correctly formatted.\n";
		return false;
	}
	return true;
}

//---------------------------operator==-----------------------------------//
//this method returns a bool based on whether or not the left operand
//Funny is equivalent to the right operand Funny, using instance
//variable checking of each
//the significant thing here is the static cast, which casts a Movie down
//to a Funny for possible comparison
bool Funny::operator==(const Movie& movie) const
{
	const Funny& funnyMv = static_cast<const Funny&>(movie);
	return (title == funnyMv.title && pubYear == funnyMv.pubYear);
}

//---------------------------operator!=-----------------------------------//
//this method returns a bool based on whether or not the left operand
//Funny is equivalent to the right operand Funny, using instance
//variable checking of each
//the significant thing here is the static cast, which casts a Movie down
//to a Funny for possible comparison
bool Funny::operator!=(const Movie& movie) const
{
	const Funny& funnyMv = static_cast<const Funny&>(movie);
	//logically, return the opposite of the == operator
	return (title != funnyMv.title || pubYear != funnyMv.pubYear);
}

//---------------------------operator<=-----------------------------------//
//this method returns a bool based on whether or not the left operand
//funny is less than or equal to to the right operand funny, 
//using instance variable checking of each.
//it will cascade down using the comparisons defined in the requirements
//checking if one is less than the other, and if not, cascading to equal to
//if then equal to, continue (almost in a recursive fashion
//the significant thing here is the static cast, which casts a Movie down
//to a funny for possible comparison
bool Funny::operator<=(const Movie& movie) const
{
	const Funny& funnyMv = static_cast<const Funny&>(movie);
	//start with comparing the lexicographical ordering of the
	//title
	if (title < funnyMv.title)
	{
		return true;
	}
	//if same, cascade down
	else if (title == funnyMv.title)
	{
		//and check the years
		return (pubYear <= funnyMv.pubYear);
	}
	else
	{
		return false;
	}
}

//---------------------------operator>=-----------------------------------//
//this method returns a bool based on whether or not the left operand
//funny is less than or equal to to the right operand funny, 
//using instance variable checking of each.
//it will cascade down using the comparisons defined in the requirements
//checking if one is less than the other, and if not, cascading to equal to
//if then equal to, continue (almost in a recursive fashion
//the significant thing here is the static cast, which casts a Movie down
//to a funny for possible comparison
bool Funny::operator>=(const Movie& movie) const
{
	const Funny& funnyMv = static_cast<const Funny&>(movie);
	//start with comparing the lexicographical ordering of the
	//title
	if (title > funnyMv.title)
	{
		return true;
	}
	//if same, cascade down
	else if (title == funnyMv.title)
	{
		//and check the years
		return (pubYear >= funnyMv.pubYear);
	}
	else
	{
		return false;
	}
}

//---------------------------operator<------------------------------------//
//needs to check only one thing after doing the base class to 
//derived class static cast, which is the title
//because if the title is not less than, than the whole thing is not
//less than
bool Funny::operator<(const Movie& movie) const
{
	const Funny& funnyMv = static_cast<const Funny&>(movie);
	return (title < funnyMv.title);
}

//---------------------------operator<------------------------------------//
//needs to check only one thing after doing the base class to 
//derived class static cast, which is the title
//because if the title is not greater than, than the whole thing is not
//greater than
bool Funny::operator>(const Movie& movie) const
{
	const Funny& funnyMv = static_cast<const Funny&>(movie);
	return (title > funnyMv.title);
}

//--------------------------------Hash-----------------------------------//
//we map movies to hash table using the alphabet
//thus to map classics to c and to an array, it is simple to
//use ASCII values, always getting a value above 0
int Funny::hash() const
{
	return 'F' - 'A';
}