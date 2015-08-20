#include "movie.h"

//---------------------------Constructor----------------------------------//
//Movie is the base class for Dramas Comedies and Classics
//none of the data needs to be set 
Movie::Movie()
{
}

//---------------------------Destructor-----------------------------------//
//There is no dynamically allocated variables, nothing needs to be
//allocated
Movie::~Movie()
{
}

//--------------------------Pretty Prints---------------------------------//
//this method will call the print method in the appropriate movie class
ostream& operator<<(ostream& os, const Movie& ref)
{
	return ref.print(os);
}

//--------------------------Pretty Prints---------------------------------//
//this method will print out the movies data by altering the outstream
//reference and ensuring that everything is formatted and justified correctly
ostream& Movie::printMovie(ostream& outStream) const
{
	outStream.setf(ios::left, ios::adjustfield);
	outStream << left << setfill(' ') << setw(MAXMOVIETITLEPRINT - 4) <<
		title.substr(0, MAXMOVIETITLEPRINT - 4) << " " <<
		setw(MAXMOVIEDIRECTORPRINT - 3) <<
		movieDirector.getName().substr(0, MAXMOVIEDIRECTORPRINT - 3) << " " <<
		setw(MAXMOVIEYEARPRINT) << pubYear;
	return outStream;
}
//these two print methods are different because one is called by the 
//movie outstream and one of them is called for a customer
//movie transaction print

//--------------------------Pretty Prints---------------------------------//
//this method will print out the movies data by altering the outstream
//reference and ensuring that everything is formatted and justified correctly
ostream& Movie::print(ostream& os) const
{
	os.setf(ios::left, ios::adjustfield);
	os << left << setfill(' ') << setw(MAXMOVIEINPRINT) << inStock
		<< setw(MAXMOVIEOUTPRINT) << movieCount - inStock <<
		setw(MAXMOVIETITLEPRINT) << title.substr(0, MAXMOVIETITLEPRINT) <<
		" " << setw(MAXMOVIEDIRECTORPRINT) <<
		movieDirector.getName().substr(0, MAXMOVIEDIRECTORPRINT) <<
		" " << setw(MAXMOVIEYEARPRINT) << pubYear << "\n";
	return os;
}

//--------------------------Set Data--------------------------------------//
//this method sets the data for the movie object using the file stream
//text file and formatting specifications to set all the instance variables
//for a movie base class (classic funny and dramas inherit from it)
bool Movie::setData(ifstream& file)
{
	//use the formats set format
	if (!format.setFormatMakeMovie(file))
	{
		return false;
	}
	else
	{
		//use the directors set data
		if (!movieDirector.setData(file))
		{
			return false;
		}
		else
		{
			//read the whole title up until the comma, that is the
			//comma 
			getline(file, title, ',');
			file.ignore(1);
			//such that the file hasn't ended yet, or the line hasn't ended
			if (file.eof() || file.peek() == '\n')
			{
				cout << "Movie information not correctly formatted.\n";
				return false;
			}
			else
			{
				file >> pubYear;
				//error checking for the publication year
				//the first movie was made in 1878 and movies
				//cannot be produced in the future
				if (pubYear < 1878 || pubYear > 2016)
				{
					cout << "Movie information not correctly formatted.\n";
					return false;
				}
				/*	if (file.peek() != ' ')
				{
				cout << "There is too much movie information provided\n";
				return false;
				}*/
				file.ignore();
				return true;
			}
		}
	}
}

//----------------------------------Get Title------------------------------//
//this method returns the string representation of the movie title
string Movie::getTitle() const
{
	return title;
}

//----------------------------------Get Format-----------------------------//
//this method returns a format reference to get the format object
//stored in a movie
const Format& Movie::getFormat() const
{
	return format;
}

//----------------------------------Get Stock------------------------------//
//this method returns the amount that is instock of this particular
//movie
int Movie::getStock() const
{
	return inStock;
}

//----------------------Get Total Movie Count------------------------------//
//this method returns the actual amount of movies that are in the store 
int Movie::getTotalMovieCount() const
{
	return movieCount;
}

//----------------------------------Add Count------------------------------//
//this method increases the count of movies in the store
//by a factor of 10, because program specifications state that
//movies added to the store will have a count of 10
void Movie::addCount()
{
	movieCount += 10;
}

//--------------------------Add Stock--------------------------------------//
//this method increases the count of movies in the store
//by a factor of 10, because program specifications state that
//movies added to the store will have a count of 10
//so this method will be used concurrently with the Add Count method
//to have a current stock
void Movie::addStock()
{
	inStock += 10;
}

//-----------------------Increment Stock----------------------------------//
//when a movie is returned, we must increase the stock of the movie
//so this method allows for incrementing the stock
void Movie::incrementStock()
{
	inStock++;
}
//-----------------------Decrement Stock----------------------------------//
//when a movie is borrows, we must decrease the stock of the movie
//so this method allows for decreasing the stock
void Movie::decrementStock()
{
	inStock--;
}


