#include "moviefactory.h"
#include "drama.h"
#include "classic.h"
#include "funny.h"

//---------------------------Constructor----------------------------------//
//the constructor for the factory sets all the values corresponding
//to the alphabetic hash array, in this case, most of the spots are NULL
//because there are only dramas, classic and funnies
//but these are set using ASCII codes
MovieFactory::MovieFactory()
{
	for (int i = 0; i < GENRELIMIT; i++)
	{
		movies[i] = NULL;
	}
	movies[3] = new Drama;
	movies[2] = new Classic;
	movies[5] = new Funny;
}

//---------------------------Destructor-----------------------------------//
//the destructor for the factory loops through the alphabetic
//hash array and deletes all things that are not already empty
MovieFactory::~MovieFactory()
{
	for (int i = 0; i < GENRELIMIT; i++)
	{
		if (movies[i] != NULL)
		{
			delete movies[i];
			movies[i] = NULL;
		}
	}
}

//--------------------------------Hash------------------------------------//
//Using the alphabetic hash we can simply return the index value by taking
//our character subtracting a capital a to correspond with a sized 26 array
int MovieFactory::hash(const char ch) const
{
	return ch - 'A';
}

//--------------------------Create It-------------------------------------//
//this method does error checking to ensure that we will return a valid
//object from the Movie Factory using the hash index and checking with
//the alphabetic array
Movie* MovieFactory::createIt(const char ch) const
{
	/*if (file.peek() == '\n' || file.eof())
	{
		return NULL;
	}*/

	int factoryIndex = hash(ch);
	//error checking for valid genres
	if (factoryIndex < 0 || factoryIndex > GENRELIMIT)
	{
		return NULL;
	}
	else if (movies[factoryIndex] == NULL)
	{
		return NULL;
	}
	return movies[factoryIndex]->create();
}



