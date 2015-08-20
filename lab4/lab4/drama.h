#ifndef DRAMA_H
#define DRAMA_H
#include "movie.h"
//---------------------------------------------------------------------------
// Drama class: Child class of Movie, implements virtual methods accordingly
//				allows for reading in and outputing the Drama Movie
//
// Implementation and Assumptions
// -- Overloaded ostream and ifstream operators:
// ------ ifstream operator used for reading in from the build inventory file
// ------ ostream operator used for printing Movie information appropriately
// -- Seperate method for reading and handling transactions from the 
//    transaction input file
// -- Assumes that the file for reading is formatted correctly:
// ------ can handle invalid commands, but data type and order must be
//		  properly formatted
//---------------------------------------------------------------------------

class Drama : public Movie
{

public:
	Drama();
	~Drama();
	

	//readTrans to process transactions from the file appropriately and
	//create a temproary Movie with just enough information for comparisons
	virtual bool readTrans(ifstream&) override;
	
	//Overridden comparison operators for proper comparisons and sorting
	//Sorted by Director name (first, last), and then title
	virtual bool operator == (const Movie&) const override;
	virtual bool operator != (const Movie&) const override;
	virtual bool operator < (const Movie&) const override;
	virtual bool operator > (const Movie&) const override;
	virtual bool operator <= (const Movie&) const override;
	virtual bool operator >= (const Movie&) const override;
	
	//Overridden Hash function which returns the genre character of the Movie
	virtual int hash() const override;
	//Create method to return a new Drama object for the TransactionFactory
	virtual Movie* create() const override;

private:
	//virtual ostream& print(ostream&) const;
};
#endif