#include "moviebst.h"

//---------------------------Constructor----------------------------------//
//Movie Binary Search Tree constrcutor sets the root of the tree to NULL
//so it does not point to garbage
MovieBST::MovieBST()
{
	root = NULL;
}

//---------------------------Destructor-----------------------------------//
//Checks to see if the root is already NULL, and then does nothing if that
//is the case. Otherwise, deleteTree is called and root is passed in.
MovieBST::~MovieBST()
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		deleteTree(root);
	}
}

//-----------------------------deleteTree---------------------------------//
//Recursive helper method for the MovieBST destructor
//Initally takess the root as the parameter
void MovieBST::deleteTree(MovieNode* cur)
{
	if (cur == NULL)
	{
		return;
	}
	else
	{
		deleteTree(cur->left);
		deleteTree(cur->right);
		delete cur->moviedata;
		cur->moviedata = NULL;
		cur->left = NULL;
		cur->right = NULL;
		delete cur;
		cur = NULL;
	}
}

//---------------------------printMovies----------------------------------//
//Method to print all of the movies within the tree
//Calls a recursive helper method called print, passing the root as a 
//parameter
void MovieBST::printMovies() const
{
	print(root);
}

//------------------------------print-------------------------------------//
//Recursive helper method for print Movies to print all of the movies
//within the tree, taking a MovieNode pointer as a parameter
//Prints the Movies using an in-order traversal
void MovieBST::print(MovieNode* cur) const
{
	if (cur == NULL)
	{
		return;
	}
	else
	{
		print(cur->left);
		cout << *cur->moviedata;
		print(cur->right);
	}
}

//----------------------------addMovie------------------------------------//
//Adds a movie into the MovieBST by taking a Movie pointer as a parameter
void MovieBST::addMovie(Movie* ins)
{
	//If the root is null make the root point to the Movie parameter
	if (root == NULL)
	{
		root = new MovieNode;
		root->moviedata = ins;
		root->moviedata->addCount();
		root->moviedata->addStock();
		root->left = NULL;
		root->right = NULL;
	}
	//Otherwise call the helper method insert, passing the Movie pointer
	//and the root as parameters
	else
	{
		insert(root, ins);
	}
}

//-----------------------------insert-------------------------------------//
//Recursive helper method for addMovie
//Takes a MovieNode pointer and a Movie pointer as parameters and locates
//the appropriate place to put the Movie into the MovieBST
void MovieBST::insert(MovieNode* cur, Movie* ins)
{
	//If the movie exists already print an error and return
	if (*ins == *cur->moviedata)
	{
		cout << "Invalid movie insert; the store does not allow duplicates.\n";
		return;
	}
	else if (*ins <= *cur->moviedata)
	{
		//If the left is NULL add the Movie to the left and return
		if (cur->left == NULL)
		{
			cur->left = new MovieNode;
			cur->left->moviedata = ins;
			cur->left->moviedata->addCount();
			cur->left->moviedata->addStock();
			cur->left->left = NULL;
			cur->left->right = NULL;
			return;
		}
		else
		{
			//Otherwise make a recursive call to the left
			insert(cur->left, ins);
		}
	}
	//If the Movie parameter is greater than or equal to cur's Movie
	else if (*ins >= *cur->moviedata)
	{
		//If the right is NULL add the Movie to the right and return
		if (cur->right == NULL)
		{
			cur->right = new MovieNode;
			cur->right->moviedata = ins;
			cur->right->moviedata->addCount();
			cur->right->moviedata->addStock();
			cur->right->right = NULL;
			cur->right->left = NULL;
			return;
		}
		//Otherwise make a recursive call to the right
		else
		{
			insert(cur->right, ins);
		}
	}
	//Return if all else fails
	else
	{
		return;
	}
}

//-----------------------retrieveMovieBorrow------------------------------//
//Method for retrieving a movie for a Borrow transaction
//Takes a Movie pointer and a Movie pointer reference as parameters
//The movie reference pointer will point to the actual movie in the tree
//while the Movie pointer is used to locate the movie
bool MovieBST::retrieveMovieBorrow(const Movie* loc, Movie*& ret)
{
	//Set the Movie pointer reference to NULL so it doesn't point to garbage
	ret = NULL;
	if (root == NULL)
	{
		return false;
	}
	//Otherwise make a call to the recursive helper method passing 
	//the exact same parameters with the root as the addition
	else
	{
		return retrieveBorrow(loc, ret, root);
	}
}

//-------------------------retrieveBorrow---------------------------------//
//Recursive helper method for retrieveMovieBorrow
//Takes a Movie pointer, Movie pointer reference, and a MovieNode pointer 
//as parameters and locates the desired movie, setting the Movie pointer
//reference to point to the actual movie in the MovieBST, while the Movie 
//pointer is used to locate the Movie in the MovieBST
bool MovieBST::retrieveBorrow(const Movie* loc, Movie*& ret, MovieNode* cur)
{
	//Return false if cur is NULL, because the Movie does not exist
	if (cur == NULL)
	{
		return false;
	}
	//If cur's Movie is the one we are trying to find
	else if (*cur->moviedata == *loc)
	{
		//Return false if that Movie is currently out of stock
		if (cur->moviedata->getStock() < 1)
		{
			return false;
		}
		//Otherwise set the Movie pointer reference to cur's Movie
		//and return true
		else
		{
			ret = cur->moviedata;
			return true;
		}
	}
	//If cur's Movie is not the one we are trying to find
	else
	{
		//If the Movie we are trying to find is greater than or equal
		//to cur's Movie, make a recursive call to the right 
		if (*cur->moviedata <= *loc)
		{
			return retrieveBorrow(loc, ret, cur->right);
		}
		//Otherwise make a recursive call to the left
		else //if (*cur->moviedata > *loc)
		{
			return retrieveBorrow(loc, ret, cur->left);
		}
	}
}

//-----------------------retrieveMovieReturn------------------------------//
//Method for retrieving a Movie for a Return transactions
//Takes a Movie pointer and a Movie pointer reference as parameters
//The Movie pointer reference will point to the actual Movie in the MovieBST
//and the Movie pointer is used to locate the Movie in the tree
bool MovieBST::retrieveMovieReturn(const Movie* loc, Movie*& ret)
{
	//Set the Movie pointer reference to NULL so it doesn't point to garbage
	ret = NULL;
	if (root == NULL)
	{
		return false;
	}
	//Otherwise make a call to the recursive helper method retrieveReturn
	//passing the same exact parameters with the root as an addition
	else
	{
		return retrieveReturn(loc, ret, root);
	}
}

//--------------------------retrieveReturn--------------------------------//
//Recursive helper method for retrieveMovieReturn
//Takes a Movie pointer, Movie pointer reference, and a MovieNode pointer
//as parameters
//The Movie pointer is used to locate the Movie in the MovieBST, while the 
//Movie pointer reference will point to the actual movie within the MovieBST
bool MovieBST::retrieveReturn(const Movie* loc, Movie*& ret, MovieNode* cur)
{
	if (cur == NULL)
	{
		return false;
	}
	//If cur's Movie is the Movie we are looking for, set the Movie pointer
	//reference to cur's Movie, and return true
	else if (*cur->moviedata == *loc)
	{
		ret = cur->moviedata;
		return true;
	}
	//If we are still looking for the Movie
	else
	{
		//If the Movie we are trying to find is greater than or euqal to 
		//cur's Movie, make a recursive call to the right
		if (*cur->moviedata <= *loc)
		{
			return retrieveReturn(loc, ret, cur->right);
		}
		//Otherwise make a recursive call to the left
		else //if (*cur->moviedata > *loc)
		{
			return retrieveReturn(loc, ret, cur->left);
		}
	}
}




