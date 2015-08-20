#ifndef MOVIEBST_H
#define MOVIEBST_H
#include "movie.h"
//---------------------------------------------------------------------------
// MovieBST Class: Binary Search Tree class for storing Movie objects
// -- allows for the addition and retrieval of Movies within the tree
//
// Implemenation and Assumptions
// -- Movie objects are passed appropriately into correct methods:
// ------ Can handle invalid Movies, but must be valid data type (Movie)
// -- Assumes that the removal of a Movie from a database will never occur or
//    be desired
// -- Uses a unique MovieNode to store the information of a Movie and point
//    to the left and right in the MovieBST
//---------------------------------------------------------------------------
//----------------------------------------------------------------
//Binary Search Tree Property(left < parent && right > parent)
//----------------------------------------------------------------
/*
                           rootNode
                       /<-L |obj->| R->\                   |Rootobj|
                      /                 \
           |<-L | obj-> | R->|    |<-L | obj-> | R->|    |Lobj| |Robj|
             /             \        /              \
           ...            ...     ...             ...    ... ... ... ...
*/

class MovieBST
{
public:
	MovieBST();
	~MovieBST();
	//PrintMovies method to print all of the Movies within the tree
	void printMovies() const;
	//addMovie for the addition of a new Movie object to the database
	void addMovie(Movie*);
	//retriveMovie for ensuring that a requested Movie exists withing
	//the MovieBST. Borrow checks for the inStock being 0, while Return
	//does not. 
	bool retrieveMovieBorrow(const Movie*, Movie*&);
	bool retrieveMovieReturn(const Movie*, Movie*&);
	

private:
	//Struct MovieNode
	//Contains pointer to Movie object
	//MovieNode pointer to the left and right
	//Total number of copies that belong to the Store
	//Number of copies currently in-stock
	//------------------------
	//| l   |   o    |   r   |
	//| e   |   b    |   i   |
	//| f   |   j    |   i   |
	//| t   |   e    |   g   |
	//| <-  |   c    |   h   |
	//|     |   t->  |   t-> |
	//------------------------
	struct MovieNode
	{
		Movie* moviedata;
		MovieNode* left;
		MovieNode* right;
	};
	MovieNode* root;
	//Recursive print helper method to print the Movies within the MovieBST
	//using an inOrder traversal
	void print(MovieNode*) const;
	//Recursive helper method insert used by addMovie to insert a Movie
	//into the MoveiBSt
	void insert(MovieNode*, Movie*);
	//Recursive retrieveBorrow method used by retrieveMovieBorrow
	bool retrieveBorrow(const Movie*, Movie*&, MovieNode*);
	//Recursive retrieveReturn method used by retrieveMovieReturn
	bool retrieveReturn(const Movie*, Movie*&, MovieNode*);
	//Recursive deleteTree method used by the destructor to delete the 
	//MovieBST
	void deleteTree(MovieNode*);

	
};
#endif