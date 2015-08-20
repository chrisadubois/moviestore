#include "drama.h"


//---------------------------Constructor----------------------------------//
//Drama inherits from movie and simply needs to set the data
//to the standards of what creates the blank movie object
Drama::Drama()
{
	movieCount = 0;
	inStock = 0;
}

//---------------------------Destructor-----------------------------------//
//no dynamically allocated variables and thus no clean up is necessary
Drama::~Drama()
{
}

//--------------------------Create----------------------------------------//
//this method is used by the factory to return a new blanked out drama 
//object
Movie* Drama::create() const
{
	return new Drama;
}

//--------------------------Read Trans-------------------------------------//
//this method sets the data for a transaction call on a drama movie
//by using the directors set data 
//and then reading in the file and setting it for the drama movie
bool Drama::readTrans(ifstream& file)
{
	if (!(movieDirector.setData(file)))
	{
		return false;
	}
	getline(file, title, ',');
	return true;
}

//---------------------------operator==-----------------------------------//
//this method returns a bool based on whether or not the left operand
//drama is equivalent to the right operand drama, using instance
//variable checking of each
//the significant thing here is the static cast, which casts a Movie down
//to a drama for possible comparison
bool Drama::operator==(const Movie& movie) const
{
	const Drama& dramaMv = static_cast<const Drama&>(movie);
	return (movieDirector.getName() ==
		dramaMv.movieDirector.getName() && title == dramaMv.title);
}

//---------------------------operator!=-----------------------------------//
//this method returns a bool based on whether or not the left operand
//drama is equivalent to the right operand drama, using instance
//variable checking of each
//the significant thing here is the static cast, which casts a Movie down
//to a drama for possible comparison
bool Drama::operator!=(const Movie& movie) const
{
	const Drama& dramaMv = static_cast<const Drama&>(movie);
	//logically, return the opposite of the == operator
	return !(*this == dramaMv);
}

//---------------------------operator<=-----------------------------------//
//this method returns a bool based on whether or not the left operand
//drama is less than or equal to to the right operand drama, 
//using instance variable checking of each.
//it will cascade down using the comparisons defined in the requirements
//checking if one is less than the other, and if not, cascading to equal to
//if then equal to, continue (almost in a recursive fashion
//the significant thing here is the static cast, which casts a Movie down
//to a drama for possible comparison
bool Drama::operator<=(const Movie& movie) const
{
	const Drama& dramaMv = static_cast<const Drama&>(movie);
	//start with comparing the lexicographical ordering of the
	//director names
	if (movieDirector.getName() < dramaMv.movieDirector.getName())
	{
		return true;
	}
	//if the director names are same, cascade down
	else if (movieDirector.getName() ==
		dramaMv.movieDirector.getName())
	{
		//and check the lexicographical ordering of the titles
		return (title <= dramaMv.title);
	}
	else
	{
		return false;
	}
}

//---------------------------operator>=-----------------------------------//
//this method returns a bool based on whether or not the left operand
//drama is less than or equal to to the right operand drama, 
//using instance variable checking of each.
//it will cascade down using the comparisons defined in the requirements
//checking if one is less than the other, and if not, cascading to equal to
//if then equal to, continue (almost in a recursive fashion
//the significant thing here is the static cast, which casts a Movie down
//to a drama for possible comparison
bool Drama::operator>=(const Movie& movie) const
{
	const Drama& dramaMv = static_cast<const Drama&>(movie);
	if (movieDirector.getName() > dramaMv.movieDirector.getName())
	{
		return true;
	}
	else if (movieDirector.getName() ==
		dramaMv.movieDirector.getName())
	{
		return (title >= dramaMv.title);
	}
	else
	{
		return false;
	}
}

//---------------------------operator<------------------------------------//
//needs to check only one thing after doing the base class to 
//derived class static cast, which is the director name
//because if the director name is not less than, than the whole thing is not
//less than
bool Drama::operator<(const Movie& movie) const
{
	const Drama& dramaMv = static_cast<const Drama&>(movie);
	return (movieDirector.getName() <
		dramaMv.movieDirector.getName());
}

//---------------------------operator>------------------------------------//
//needs to check only one thing after doing the base class to 
//derived class static cast, which is the director name
//because if the pub year is not greater than, than the whole thing is not
//greater than
bool Drama::operator>(const Movie& movie) const
{
	const Drama& dramaMv = static_cast<const Drama&>(movie);
	return (movieDirector.getName() >
		dramaMv.movieDirector.getName());
}

//--------------------------------Hash-----------------------------------//
//we map movies to hash table using the alphabet
//thus to map classics to c and to an array, it is simple to
//use ASCII values, always getting a value above 0
int Drama::hash() const
{
	return 'D' - 'A';
}