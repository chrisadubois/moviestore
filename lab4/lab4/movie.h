#ifndef MOVIE_H
#define MOVIE_H
#include "format.h"
#include "director.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
static const int MAXMOVIETITLEPRINT = 23;
static const int MAXMOVIEDIRECTORPRINT = 20;
static const int MAXMOVIEYEARPRINT = 4;
static const int MAXMOVIEINPRINT = 4;
static const int MAXMOVIEOUTPRINT = 4;
using namespace std;
//---------------------------------------------------------------------------
// Movie Parent Class: parent class for various Movie genres including:
// -- Funny, Classic, and Drama
// -- Allows for retrieving various pieces of information related to
//    the Movie:
// -- Also allows for the setting of this same information
// -- Overloads comparison operators as well
//
// Implementation and Assumptions:
// -- Transactions related to Movies are formatted correctly:
// -- can handle Invalid commands, but the data type must
//    be valid and ordered correctly
// -- Pure virtual comparisons for genres to be compared uniquely:
// ------ ensures Transactions and carried out correct and that Movie types
//        are stored in the database how they should be
// -- Getter methods for retrieving Movie information:
// ------ title, director information, publication year
//---------------------------------------------------------------------------

class Movie
{
	//Overloaded ostream  to print the Movie and its information
	friend ostream& operator<<(ostream&, const Movie&);
public:
	Movie();
	//Virtual destructor for children to be destroyed properly
	virtual ~Movie();
	//Virtual printMovie method to print the Movie and its information
	virtual ostream& printMovie(ostream&) const;
	//setData sets all necessary data for Movie by reading from a file
	virtual bool setData(ifstream&);
	//Pure virtual readTrans method to read from a file and set the 
	//data needed for Transactions, just enough information for comparisons
	virtual bool readTrans(ifstream&) = 0;
	//getTitle returns Movie title
	string getTitle() const;
	//getStock returns the Movies in stock
	int getStock() const;
	//getTotalMovieCount returns the total copies of a Movie that the 
	//Store owns
	int getTotalMovieCount() const;
	//getFormat returns the Format object that a Movie has
	const Format& getFormat() const;
	//Pure virtual create method for the MovieFactory
	virtual Movie* create() const = 0;

	
	//AddCount adds 10 to the total count of a Movie that the Store has
	void addCount();
	//IncremenetStock increments the inStock count of a movie by 1
	void incrementStock();
	//decrementStock decrements the inStock count of a movie by 1
	void decrementStock();
	//addStock adds 10 to the total inStock count of a Movie
	void addStock();
	//Pure virtual hash function used for hashing Movies
	virtual int hash() const = 0;

	
	//Pure virtual comparison operator overloads
	//Each genre is compared and sorted differently
	virtual bool operator == (const Movie&) const = 0;
	virtual bool operator != (const Movie&) const = 0;
	virtual bool operator < (const Movie&) const = 0;
	virtual bool operator > (const Movie&) const = 0;
	virtual bool operator <= (const Movie&) const = 0;
	virtual bool operator >= (const Movie&) const = 0;

protected:
	//Movie title
	string title;
	Director movieDirector;
	//Movie's publication year
	int pubYear;
	//Movie's format
	Format format;
	//movie count
	int movieCount = 0;
	//instock
	int inStock = 0;
	//Virtual print method to print the Movie information used by
	//the overloaded ostream operator for Inventory
	virtual ostream& print(ostream&) const;
};
#endif
