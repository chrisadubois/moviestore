#ifndef DIRECTOR_H
#define DIRECTOR_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
//---------------------------------------------------------------------------
// Director Class: used for storing the name of the director related to 
//				   a particular movie
//
// Implementation and Assumptions
// -- Assuems that valid parameters are passed. Can handle invalid 
//    information, but the type itself must be correct
// -- Can set the data by passing an ifstream
// -- Able to get the name of the director through a getter method
//---------------------------------------------------------------------------

class Director
{
public:
	Director();
	~Director();
	//setData taking an ifstream, returning a bool, which sets the Name
	//of the director
	bool setData(ifstream&);
	//getName which returns the name of the director
	string getName() const;
	
private:
	//String holding the name of the director
	string name;
};
#endif
