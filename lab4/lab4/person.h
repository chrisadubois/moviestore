#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
//---------------------------------------------------------------------------  
// Person class: contains a first and last name for Customers, and is the
//				 parent class for Customer
//
// Implementation and Assumptions
// -- Contains two strings for first and last name
// -- Can set data by passing an ifstream reference
// -- Assumes valid parameters are passed
// -- Only default constructor, setData used for initialization of data 
//    members
//---------------------------------------------------------------------------

class Person
{
	//Overloaded ostream operator to print the Person informations
	friend ostream& operator<<(ostream&, const Person&);
public:
	Person();
	//Pure virtual desctructor for base classes to implement
	virtual ~Person() = 0;
	//Pure virtual print method used by the ostream operator
	//for base classes to implement
	virtual void print(ostream& os) const = 0;
	//Virtual setData function using an ifstream reference
	virtual bool setData(ifstream&) = 0;
	//getter methods for first and last name
	string getFirstName() const;
	string getLastName() const;
	


protected:
	//Protected data members for first and last name
	string firstName;
	string lastName;
};
#endif
