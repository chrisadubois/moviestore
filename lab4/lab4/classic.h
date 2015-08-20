#ifndef CLASSIC_H
#define CLASSIC_H
#include "movie.h"
#include "actor.h"
//---------------------------------------------------------------------------
// Classic class: child class of Movie, implements virtual methods accordingly
//				  allows for reading in and outputing the Classic Movie
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
static const int MAXMOVIEMONTHPRINT = 2;
static const int MAXMOVIEACTORPRINT = 17;
class Classic : public Movie
{


public:
	Classic();
	~Classic();
	//Virtual printMovie method to print the Classic information
	virtual ostream& printMovie(ostream&) const override;
	//Overridden setData to accomodate for unique data in Classic
	virtual bool setData(ifstream&) override;
	//readTrans to process transactions from the file appropriately and
	//set a temporary Movie with just enough information for comparisons
	virtual bool readTrans(ifstream&) override;
	//getPubMonth get get publication month
	int getPubMonth() const;
	
	//Hash method for hashing the Classic Moviie
	virtual int hash() const override;

	//Virtual create method for the TransactionFactory
	virtual Movie* create() const override;


	

	//Overridden comparison operators for proper comparisons and sorting
	//Sorted by publication Year, publication Month, and then acotr/actress
	//name (first, last)
	virtual bool operator == (const Movie&) const override;
	virtual bool operator != (const Movie&) const override;
	virtual bool operator < (const Movie&) const override;
	virtual bool operator > (const Movie&) const override;
	virtual bool operator <= (const Movie&) const override;
	virtual bool operator >= (const Movie&) const override;

private:
	//Virtual print method for printing Movie information related
	//to Transaction information
	virtual ostream& print(ostream&) const override;
	//publication Month
	int pubMonth;
	//Actor in the movie
	Actor movieActor;
};
#endif