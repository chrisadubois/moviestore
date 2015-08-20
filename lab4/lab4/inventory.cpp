#include "inventory.h"

//---------------------------Constructor----------------------------------//
//the constructor for the inventory does not need to set anything
//because it begins empty when it is created and is filled
//from there. additionally all of the instance variables of
//the inventory are stack allocated
Inventory::Inventory()
{
}

//---------------------------Destructor-----------------------------------//
////no need for clean up since instance variables are not dynamic
Inventory::~Inventory()
{
}

//--------------------------Pretty Prints---------------------------------//
//call the abstracted movielist print classics method
void Inventory::printInventoryClassics() const
{
	movies.printClassics();
}

//--------------------------Pretty Prints---------------------------------//
//call the abstracted movielist print dramas method
void Inventory::printInventoryDramas() const
{
	movies.printDramas();
}

//--------------------------Pretty Prints---------------------------------//
//call the abstracted movielist print funnies method
void Inventory::printInventoryFunnies() const
{
	movies.printFunnies();
}

//-----------------------------------Add Movie-----------------------------//
//call the abstracted, polymorphic movielist add movie method
bool Inventory::addMovie(Movie* add)
{
	return movies.addMovie(add);
}

//----------------------------Borrow Movie--------------------------------//
//call the abstracted, polymorphic movielist borrow movie method
bool Inventory::borrowMovie(Movie*& ret, Movie* find) const
{
	return movies.borrowMovie(ret, find);
}

//-----------------------------Return Movie-------------------------------//
//call the abstracted, polymorphic movielist borrow movie method
bool Inventory::returnMovie(Movie*& ret, Movie* find) const
{
	return movies.returnMovie(ret, find);
}




