#ifndef MOVIELIST_H
#define MOVIELIST_H
#include "moviebst.h"
//#include "movie.h"
class Movie;
static const int MOVIETYPELIMIT = 26;
//---------------------------------------------------------------------------
// MovieList Class: class for sorting and storing Movie objects by genre
// -- allows for the manipulation of Movie containers
// -- allows for the retrieval and return of Movies
// -- allows for the addition of new Movies to various Movie containers
//
// Implementation and Asssumptions
// -- Uses a Binary Search Tree of Movies for storing and sorting
// -- Individual trees for different genres:
// ------ Different genres are sorted different, allowing for easy retrieval
// and addition of Movie types during Transaction processing
// -- Assumes that Movie objects are passed appropriately:
// ------ Can handle invalid Movies, but must be valid data type (Movie)
// -- Assumes that genre character is passed into the hash function:
// ------ Can handle invalid characters, but must be valid data type (char)
//---------------------------------------------------------------------------

class MovieList
{
public:
	MovieList();
	~MovieList();

	//printMovies for the Show transaction to print inventory and
	//any related information (e.g. in stock count)
	void printDramas() const;
	void printClassics() const;
	void printFunnies() const;
	//addMovie for adding a new Movie into the database of Movies
	bool addMovie(Movie*);
	//borrowMovie for Customers who wish to borrow a movie
	bool borrowMovie(Movie*&, Movie*) const;
	//returnMovie for Customers who wish to return a movie
	bool returnMovie(Movie*&, Movie*) const;
	
	

private:
	//Array of MovieBST pointers for storing Movies seperately
	//by their genre
	MovieBST* movies[MOVIETYPELIMIT];
};
#endif
