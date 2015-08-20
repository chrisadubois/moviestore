#include "format.h"


//---------------------------Constructor----------------------------------//
//nothing needs to be set in format because it will read from the file
//and format's instance variables are not dynamically allocated
Format::Format()
{
}

//---------------------------Destructor-----------------------------------//
//all instance variables are stack allocated and thus do not need to be
//cleaned up
Format::~Format()
{
}

//--------------------------Pretty Prints---------------------------------//
//this method uses the ostream as a reference to alter the stream and 
//print out the data stored inside of an object
//moreover, the dvd aspect is hardcoded in because the project
//specification state that format is always DVD and nevery anything else
ostream& operator<<(ostream& os, const Format& ref)
{
	if (ref.getFormat() == "D")
	{
		os << "DVD";
	}
	else
	{
		os << "FORMATUNSPECIFIED";
	}
	return os;
}

//--------------------Set Format Make Movie--------------------------------//
//Movies formats are always set to D according to the program specifications
//so the file does not need to be altered
bool Format::setFormatMakeMovie(ifstream& file)
{
		format = 'D';
		return true;
}

//-----------------------Set Format From Trans-----------------------------//
//this method sets the format for the transaction using the file stream
//and hard codes the check for the dvd aspect
bool Format::setFormatFromTrans(ifstream& file)
{
	char f;
	file >> f;
	if (f != 'D')
	{
	cout << "Invalid media format type\n";
	return false;
		}
	else
	{
	format = 'D';
	return true;
	}
}

//----------------------------Get Format-----------------------------------//
//this method returns the string representation of the format
//stored for a movie
string Format::getFormat() const
{
	return format;
}



