#ifndef CUSTMOVIELIST_H
#define CUSTMOVIELIST_H
#include "movie.h"
//---------------------------------------------------------------------------
// CustMovieList class : Used for storing the Movies that a particular
//						 customer is currently renting
//
// Implementation and Assumptions
// -- Able to insert and remove Movies to the list, taking a Movie pointer
//    as its parameters
// -- Struct custmovienode which stores the movie, prev, next, and number
//    of copies the Customer has of that particular Movie
// -- Able to check if a Customer has a particular Movie, which is a private
//    method used by the remove function
// -- Assumes valid parameters are passed. Can handle invalid information,
//    but the type must be accurate
//---------------------------------------------------------------------------
//<-|prev|head|next|-><-|prev|Transaction*|next|->...<-|prev|tail|next|->
//we used previous as part of the linking because we had never
//implemented a doubly linked list for a homework assignment and wanted
//to try it out
class CustMovieList
{
public:
	CustMovieList();
	~CustMovieList();
	//Insert for inserting a Movie into the list
	void insert(Movie*);
	//Remove for removing a Movie from the list
	bool remove(Movie*);
private:
	//Struct containing the Movie, and number of copies of that Movie
	//the Customer has out
	struct custmovienode
	{
		int movieCt = 1;
		custmovienode* next;
		custmovienode* prev;
		Movie* custmoviedata;
	};
	//Head pointer of the list
	custmovienode* head;
	//Contains function to check if the Customer actually has the Movie
	//out
	bool contains(const Movie*, custmovienode*&);
};
#endif
