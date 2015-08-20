#include "actor.h"

//---------------------------Constructor----------------------------------//
//Actor is a static variable, the constructor does not need to
//define anything, except for the creation of an Actor object
Actor::Actor()
{
}

//---------------------------Destructor-----------------------------------//
//The destructor has no dynamic allocation and thus does not need to do
//any special clean up
Actor::~Actor()
{
}

//--------------------------Pretty Prints---------------------------------//
//this method uses the ostream as a reference to alter the stream and 
//print out the data stored inside of an object
void Actor::print(ostream& os) const
{
	os << firstName << " " << lastName;
}

//--------------------------Set Data--------------------------------------//
//this method uses the ifstream reading in the file to set the data for
//Actor following formatting specifications
//it reads through setting the first name and the last name dependent
//on if the next data is SOMETHING and the file does not end at a certain
//point that it should not, this will set the instance variables of 
//an actor object
bool Actor::setData(ifstream& file)
{
	//such that the file hasn't ended yet, or the line hasn't ended
	if (file.eof() || file.peek() == '\n')
	{
		cout << "The actor's name is undefined. ERROR\n";
		//no need for clean up since it is not dynamic
		return false;
	}
	file >> firstName;
	//such that the file hasn't ended yet, or the line hasn't ended
	if (file.eof() || file.peek() == '\n')
	{
		cout << "The actor's last name is undefined. ERROR\n";
		//no need for clean up since it is not dynamic
		return false;
	}
	file >> lastName;
	//everything worked perfectly, so the data is set
	return true;
}