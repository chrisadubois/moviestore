1. We believe that the state of our program is "complete", we don't think anything specifically
      does not work. To our knowledge, there is nothing that the program has not implemented correctly.
      only things we feel are incorrect are possible file reading errors -(just formatting not validation)-
 
2. Our hash tables are used for Movies and for Transactions, Transaction Factories, Movie Factories and
       Customers. These are all located in the store.  
       Specifically: the Movies hash table is located in Store's Inventory, which has
       a MovieList, and this is the actual hash table for movies.  Transactions are not implemented with
       a hash table, but is just a Transaction Factory.  Customers are located in the store as an array
       and is a simplistic hash table with mapping corresponding to customer IDs. Finally the Movie
       Factory is technically a hash table as well.

       Movie Hashtable - Store->Inventory->MovieList -- used to store movies using alphabetic mapping
                                                        stored in BSTs at a hashed index

       Movie HashFactory - Store->MovieFactory       -- used to produce correct movie genres using
                                                        alphabetic mapping

       Transaction HashFactory - Store->TransactionFactory -- used to produce correct transaction
                                                              types using alphabetic mapping

       Customer Hashtable - Store                          -- used to access customers at a specific
                                                              index in the store using unique int IDs
    
3. We read the movie data using the Store, which is the "Manager" class for our Movie Store. This method
      is called BuildInventory which calls setData on the movies passing an ifstream.
      store.BuildInventory("textfilename.txt")->setData(ifstream textfilename)->AddMovie(movie)

4. We read the command data using the Store, which is the "Manager" class for our Movie Store.
      This method is called ProcessTransactions which calls Transaction's execute, which calls an inventory
      method representing show, return, borrow, or history. store.ProcessTransactions("textfilename.txt")->
      execute(textfilename, store)->dependent on type of transaction the action to be performed

5. Dirty little secrets: 1. Formats were hard coded, to only allow for DVDs as a Format and thus a 
      switch type of statement was used checking to make sure that the format == 'D' to represent
      DVD, we did it this way because movie commands don't state what type of format the movie is. 
      2. We used Customer pointers in our store rather than stack allocated variable for Customer objects
      which is less efficient (in terms of allocations), we feel we could have done it using static
      variables but did not realize that until it was too late. 3.  As discussed in class, Directors
      only have one name and thus do not inherit from Person and so is a stand alone class that 
      does not fit.  4.  File read checking: We assume that shows file formatting is 100% accurate
      and so this action does not error check aside from the type of transaction that it is.  Other
      file read secrets include that we don't do the new line check using fileIn.peek() != '\n' at the end
      of a transaction in the data4commands.txt file because linux complained about this read check and
      we could not find an alternative method for this. 
      5. We hardcode the movieCount and inStock in the .h file for a movie as specifications requested.
      6. We did not add a remove for the Binary Search Tree, leaving it semi-incomplete, because we
      didn't think that a movie would be removed from the inventory completely.
      7. We produced a doubly linked list unneccesarily, in customer movie list.  It did not speed
      anything up, and was only implemented because we had never made a doubly linked list for a hw
      before.

6.  The whole project because we finished it, we put our hearts and souls into it, and because the only dirty secrets 
    we had on the project were ones discussed in class as acceptable. 