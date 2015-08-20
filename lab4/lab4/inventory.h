#ifndef INVENTORY_H
#define INVENTORY_H
//#include "movie.h"
class Movie;
#include "movielist.h"
//---------------------------------------------------------------------------
// Inventory Class: used for storing Movie objects in a sorted manner for
//	easy insertion and retrieval when necessary
// -- allows for addition of movie to the database
// -- allows for the borrowing of movies by Customers
// -- allows for the returning of movies by Customers
//
// Implementation and Assumptions:
// -- Movie objects are passed into the appropriate methods:
// ------ handles invalid Movies (e.g. Movies that don't exist)
// ------ but data type must be valid (Movie)
// -- Can add, return, and borrow Movies
// -- Able to print the various Genre inventories
//---------------------------------------------------------------------------

class Inventory
{
public:
	Inventory();
	~Inventory();

	//printInventory is for the Show transaction
	//which prints the Inventory logically and displays related
	//information (e.g. in stock count)
	void printInventoryDramas() const;
	void printInventoryClassics() const;
	void printInventoryFunnies() const;

	//addMovie adds a new Movie to the MovieList
	bool addMovie(Movie*);

	//returnMovie is for Customers returning Movies to the Store
	bool returnMovie(Movie*&, Movie*) const;
	//borrowMovie is for Customers borrowing Movies from the Store
	bool borrowMovie(Movie*&, Movie*) const;

	

private:
	//MovieList for storing individual Movie objects
	MovieList movies;

};
#endif