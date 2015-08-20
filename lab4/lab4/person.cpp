#include "person.h"


//---------------------------Constructor----------------------------------//
//Actor is a static variable, the constructor does not need to
//define anything, except for the creation of an Actor object
Person::Person()
{
}

//---------------------------Destructor-----------------------------------//
//The destructor has no dynamic allocation and thus does not need to do
//any special clean up
Person::~Person()
{
}

//--------------------------Pretty Prints---------------------------------//
//this method uses the ostream as a reference to alter the stream and 
//print out the data stored inside of an object
ostream& operator<<(ostream& os, const Person& ref)
{
	ref.print(os);
	return os;
}
//---------------------------Get First Name-------------------------------//
//this method returns the first name stored in the actor object as a string
string Person::getFirstName() const
{
	return firstName;
}

//-------------------------Get Last Name----------------------------------//
//this method returns the last name stored in the actor object as a string
string Person::getLastName() const
{
	return lastName;
}
