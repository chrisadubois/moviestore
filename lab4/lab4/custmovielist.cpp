#include "custmovielist.h"

//---------------------------Constructor----------------------------------//
//the customer movie list is a linked list
//so we must set the head to NULL when constructing the list
CustMovieList::CustMovieList()
{
	head = NULL;
}
//---------------------------Destructor-----------------------------------//
//the destructor loops through the entire movie list and deletes
//all of the data, and sets pointers to null
//THE KEY HERE IS THAT WE DO NOT DELETE THE MOVIE 
//BECAUSE THE MOVIE LIST IS A POINTER TO THE MOVIE THAT EXISTS
//IN THE BINARY SEARCH TREE FOR INVENTORY, WHICH IMPLEMENTS
//ITS OWN CORRECT DESTRUCTOR
//there are 2 pointers to the movie object
//other than that it is a standard linked list traversal
CustMovieList::~CustMovieList()
{
	custmovienode* cur = head;
	while (cur != NULL)
	{
		head->custmoviedata = NULL;
		cur = head->next;
		delete head;
		head = cur;
	}
}

//-------------------------------Insert-----------------------------------//
//insert a new movie into the list
//if the movie already exists in the list, simply implement the count
//in the movie node to save time and space
//otherwise, find a spot in the list, by adding always to the head
void CustMovieList::insert(Movie* ins)
{
	custmovienode* checkIfInAlrdy;
	//the movie is already in the list
	//so right away, return and increment the nodes count and
	//return
	if (contains(ins, checkIfInAlrdy))
	{
		checkIfInAlrdy->movieCt++;
		return;
	}
	else
	{
		//the case that the list is empty
		if (head == NULL)
		{
			head = new custmovienode;
			head->custmoviedata = ins;
			head->next = NULL;
			head->prev = NULL;
		}
		//the case that the list is not empty
		else
		{
			custmovienode* cur = head;
			head = new custmovienode;
			head->custmoviedata = ins;
			head->prev = NULL;
			head->next = cur;
			cur->prev = head;
		}
	}
}

//---------------------------------Remove---------------------------------//
//this method removes a movie from the movie list
//if the customer has already checked out more than one copy of the
//movie they are trying to return, we simply decrement the count
//stored in the node
bool CustMovieList::remove(Movie* remv)
{
	//can't remove anything from an empty list
	if (head == NULL)
	{
		return false;
	}
	else
	{
		//find the movie
		//if it exists and is greater than 1, than simply decrement
		//the count
		custmovienode* loc = NULL;
		if (contains(remv, loc))
		{
			if (loc->movieCt > 1)
			{
				loc->movieCt--;
				return true;
			}
			//otherwise, the movie does not exist OR
			//the movie only has a count of 1 in the customers
			//movie list
			else
			{
				//the case that there is only a head
				if (loc->next == NULL && loc->prev == NULL)
				{
					loc->custmoviedata = NULL;
					delete loc;
					head = NULL;
				}
				//the case that it is the last item in the list
				else if (loc->next == NULL)
				{
					loc->prev->next = NULL;
					loc->custmoviedata = NULL;
					loc->prev = NULL;
					delete loc;
				}
				//the case that the movie is the head
				else if (loc->prev == NULL)
				{
					head = loc->next;
					loc->next->prev = NULL;
					loc->custmoviedata = NULL;
					loc->next = NULL;
					delete loc;
				}
				//the case that the movie is in the body of the list
				else
				{
					loc->prev->next = loc->next;
					loc->next->prev = loc->prev;
					loc->custmoviedata = NULL;
					loc->prev = NULL;
					loc->next = NULL;
					delete loc;
				}
				return true;
			}
		}
		else
		{
			return false;
		}
	}
}

//---------------------------Contains-------------------------------------//
//this method searches through the entire list and looks for a movie
//returning a pointer reference to the movie
//implements a standard traversal of a tree and calling on
//movies virtual operator==
bool CustMovieList::contains(const Movie* remv, custmovienode*& loc)
{
	custmovienode* cur = head;
	while (cur != NULL)
	{
		if (*cur->custmoviedata == *remv)
		{
			loc = cur;
			return true;
		}
		cur = cur->next;
	}
	return false;
}
