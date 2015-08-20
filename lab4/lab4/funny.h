#ifndef FUNNY_H
#define FUNNY_H
#include "movie.h"
//---------------------------------------------------------------------------
// Funny class: child class of Movie, implements virtual methods accordingly
//              and alows for reading in and outputting Funny information
//
// Implemenation and Assumptions
// -- Overloaded ostream and ifstream operators:
// ------ ifstream operator used for reading in from the build inventory file
// ------ ostream operator used for printing Movie information appropriately
// -- Seperate method for reading and handling transactions from the 
//    transaction input file
// -- Assumes that the file for reading is formatted correctly:
// ------ can handle invalid commands, but data type and order must be
//		  properly formatted
//---------------------------------------------------------------------------

class Funny : public Movie
{


public:
	Funny();
	
	~Funny();

	//readTrans to process Transactions from the file appropriaely
	virtual bool readTrans(ifstream&) override; 
	
	//Overridden comparison operators for proper comparisons and sorting
	//Sorted by Title, and then publication year
	virtual bool operator == (const Movie&) const override;
	virtual bool operator != (const Movie&) const override;
	virtual bool operator < (const Movie&) const override;
	virtual bool operator > (const Movie&) const override;
	virtual bool operator <= (const Movie&) const override;
	virtual bool operator >= (const Movie&) const override;

	//Create method to return a new Funny object for the Transaction Factory
	virtual Movie* create() const override;

	//Overridden hash function to return the genre of the Movie
	virtual int hash() const override;

private:
	//ostream& print(ostream&) const;

};
#endif
