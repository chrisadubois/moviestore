#include "show.h"
#include "store.h"

//---------------------------Constructor----------------------------------//
//Show objects always have a transaction action as 'S'
Show::Show()
{
	action = 'S';
}

//---------------------------Destructor-----------------------------------//
//there are no dynamically allocated variables to clean up after
Show::~Show()
{
}

//--------------------------Factory Constructor---------------------------//
//utilized for the Transaction Factory to create a blank Show obj
Transaction* Show::create() const
{
	return new Show;
}

//--------------------------Pretty Prints---------------------------------//
//this method uses the ostream as a reference to alter the stream and 
//print out the data stored inside of an object
void Show::print(ostream& os) const
{
	os << action << "\n";
}

//--------------------------------Execute---------------------------------//
//this method performs the actions for the Show object, using the
//store as a parameter to access the inventory and print accordingly
//it also uses the file stream to read in the information as a show
//and prints out headers for for each type of method being called 

//this method does not error checking because format specifications
//stated that type for all transactions would always be valid as
//one character in this case
bool Show::execute(ifstream& file, Store& st)
{
		file.ignore(1);
		cout << "*****************************Displaying Inventory"
			<< "*****************************\n";
		cout << "\n-----------------------------------CLASSICS"
			<< "-----------------------------------\n" <<
			"IN  " << "OUT " << "\n" << "DVD " <<
			"DVD " <<
			"---------TITLE--------- " <<
			"------DIRECTOR------ " <<
			"YEAR " << "MO " <<
			"------ACTOR------" << "\n";
		st.getInventory().printInventoryClassics();
		cout << "\n------------------------------------DRAMAS"
			<< "------------------------------------\n" <<
			"IN  " << "OUT " << "\n" << "DVD " <<
			"DVD " <<
			"---------TITLE--------- " <<
			"------DIRECTOR------ " <<
			"YEAR" << "\n";
		st.getInventory().printInventoryDramas();
		cout << "\n------------------------------------FUNNIES"
			<< "-----------------------------------\n" <<
			"IN  " << "OUT " << "\n" << "DVD " <<
			"DVD " <<
			"---------TITLE--------- " <<
			"------DIRECTOR------ " <<
			"YEAR" << "\n";
		st.getInventory().printInventoryFunnies();
		cout << "\n*****************************End Inventory Show" <<
			"******************************\n\n";
		//we don't store or need this show object any longer
		//so we can commit suicide and return true
	delete this;
	return true;
}
