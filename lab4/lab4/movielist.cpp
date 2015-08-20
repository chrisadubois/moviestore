#include "movielist.h"

//---------------------------Constructor----------------------------------//
//the movie list relates it's list elements (as an array) to the alphabetic
//hash table found in movie factory, and in this case, the hash for
//the movie list uses "Seperate Chaining" as a technique
//wherein everything is hashed to a spot in the array and then a data
//structure comes out from that index to store things that has to that
//index
MovieList::MovieList()
{
	for (int i = 0; i < MOVIETYPELIMIT; i++)
	{
		movies[i] = NULL;
	}
	movies[2] = new MovieBST; //Classics
	movies[3] = new MovieBST; //Dramas
	movies[5] = new MovieBST; //Funnys
}

//---------------------------Destructor-----------------------------------//
//the destructor must clean up the allocated variables by looping through
//the entire array and deleting spots which are not null, the places that
//are not null will have that destructor called on it (movie bst)
MovieList::~MovieList()
{
	for (int i = 0; i < MOVIETYPELIMIT; i++)
	{
		if (movies[i] != NULL)
		{
			delete movies[i];
			movies[i] = NULL;
		}
	}
}

//--------------------------Pretty Prints---------------------------------//
//this method will call the abstracted method stored in the bst to
//print all of the movies at a specific location, classics
void MovieList::printClassics() const
{
	movies[2]->printMovies();
}

//--------------------------Pretty Prints---------------------------------//
//this method will call the abstracted method stored in the bst to
//print all of the movies at a specific location, dramas
void MovieList::printDramas() const
{
	movies[3]->printMovies();
}

//--------------------------Pretty Prints---------------------------------//
//this method will call the abstracted method stored in the bst to
//print all of the movies at a specific location, Comedies
void MovieList::printFunnies() const
{
	movies[5]->printMovies();
}

//-----------------------Add Movie----------------------------------------//
//this method will call the abstracted method stored in the bst to insert
//a new movie once it has been hashed
bool MovieList::addMovie(Movie* addMov)
{
	int hashIdx = addMov->hash();
	movies[hashIdx]->addMovie(addMov);
	return true;
}

//---------------------Borrow Movie---------------------------------------//
//this method will call the abstracted method stored in the bst to borrow
//a movie once it has been hashed, and if this worked, then decrement
//the stock of the movie that it locates with the retrieval method
bool MovieList::borrowMovie(Movie*& ret, Movie* loc) const
{
	int hashIdx = loc->hash();
	if (movies[hashIdx]->retrieveMovieBorrow(loc, ret))
	{
		ret->decrementStock();
		return true;
	}
	return false;
}

//---------------------Borrow Movie---------------------------------------//
//this method will call the abstracted method stored in the bst to borrow
//a movie once it has been hashed, and if this worked, then increment
//the stock of the movie that it locates with the retrieval method
bool MovieList::returnMovie(Movie*& ret, Movie* loc) const
{
	int hashIdx = loc->hash();
	if (movies[hashIdx]->retrieveMovieReturn(loc, ret))
	{
		ret->incrementStock();
		return true;
	}
	return false;
}