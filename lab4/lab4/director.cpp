#include "director.h"

//---------------------------Constructor----------------------------------//
//no need to set anything for the instance variables
//just needs to create a director object
Director::Director()
{
}

//---------------------------Destructor-----------------------------------//
//there is no need to delete anything, no data needs to be cleaned up
Director::~Director()
{
}

//--------------------------Set Data--------------------------------------//
//this method uses the instream text file to set the directors
//name data iterating through piece by piece in the file
bool Director::setData(ifstream& file)
{
	if (file.eof())
	{
		cout << "The Director's name is undefined.\n";
		return false;
	}
	else
	{
		file.ignore(1);
		if (file.peek() != '\n')
		{
			getline(file, name, ',');
		}
	}
	file.ignore(1);
	return true;
}

//----------------------------------Get Name-------------------------------//
//this method returns the name of the director
string Director::getName() const
{
	return name;
}


