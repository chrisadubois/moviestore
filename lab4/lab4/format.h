#ifndef FORMAT_H
#define FORMAT_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//---------------------------------------------------------------------------
// Format class: wrapper class for a string containing information about
// the Movie's Format
//
// Implementation and Assumptions
// -- String used for Format for extendability of Format types
// -- Getter for Format information
// -- Setter for setting the Format
//---------------------------------------------------------------------------

class Format
{
	//Overloaded ostream operator to print the Format
	friend ostream& operator<<(ostream&, const Format&);
public:
	Format();
	~Format();

	//setFormat for setting the Format information
	bool setFormatMakeMovie(ifstream&);
	bool setFormatFromTrans(ifstream&);
	//getFormat for accessing and determining Format
	string getFormat() const;

private:
	//String for type of Format
	string format;
};
#endif

