#ifndef ACTOR_H
#define ACTOR_H
#include "person.h"

//---------------------------------------------------------------------------
// Actor class : used to represent an Actor in a Movie, inherits from Person
//
// Implementation and Assumptions
// -- has its unique setData method for setting the two strings
// -- has its unique print method to print the Actor information
//---------------------------------------------------------------------------

class Actor : public Person
{
public:
	Actor();
	//Virtual destructor for inheritence
	virtual ~Actor();
	//Virtual print method for inheritence
	virtual void print(ostream&) const override;
	//Virtual setData for inheritence
	virtual bool setData(ifstream&) override;

};
#endif
