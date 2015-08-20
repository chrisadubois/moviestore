#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H
static const int GENRELIMIT = 26;
#include "movie.h"
//#include "drama.h"
//#include "funny.h"
//#include "classic.h"
class Drama;
class Funny;
class Classic;

//---------------------------------------------------------------------------
// MovieFactory Class: used for creating Movie objects appropriately 
//	while avoiding switch statements for real OO programming
// 
// Implementation and Assumptions:
// -- Contains an array of 26 new Movie objects by genre
// -- Takes a character which represents the Movie genre
// -- Hashes the character to access the appropraite index, calling createIt
// -- Returns a new Movie object of the specified type
// -- Assumes that input will be one character:
// ------ can handle invalid characters, but must by valid data type (char)
//---------------------------------------------------------------------------

class MovieFactory
{
public:
	MovieFactory();
	~MovieFactory();
	//createIt which returns the appropriate Movie object based on
	//hash function
	Movie* createIt(const char) const;

private:
	//Array of 26 Movie pointers
	//Valid genres point to new Movie objects of specified genre
	//Otherwise the pointers ponit to NULL
	Movie* movies[GENRELIMIT];
	//Hash function which hashes genre character to appropriate index 
	//in Movie poniter array
	int hash(const char) const;
};
#endif
