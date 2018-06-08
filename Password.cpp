#include "Password.h"
using CSC1310::ListArrayIterator;

#include <iostream>
using namespace std;

Password::Password()
{
   ListArray<String>* viable_words = new ListArray<String> [2];
   ListArray<String>* all_words = new ListArray<String> [2];
}

Password::~Password()
{
    ListArrayIterator<String>* iter = all_words->iterator();	// Create iterator
    while (iter->hasNext())	// while loop hasNext() 
    {
    	String* next = iter->next();
    	delete next;
    }

    ListArrayIterator<String>* iter2 = viable_words->iterator();	// use next() to get the next
    while (iter2->hasNext())	// while loop hasNext() 
    {
    	String* next = iter2->next();
    	delete next;
    }	// delete next
    delete iter;	// after the loop, delete the iterator
    delete iter2;
    delete [] viable_words;
    delete [] all_words;
}

void Password::addWord(String* word)
{
	all_words->add(word);
	currAll++;
}

int Password::getNumMatches(String* curr_word, String* guess_word)
{
	int matches = 0;
	for (int i = 0; i < len; i++)
	{
		char c1 = curr_word->charAt(i);
		char c2 = guess_word->charAt(i);

		if (c1 == c2)
			num_matches++;
	}
	return matches;
}

void Password::guess(int try_password, int num_matches)
{
	String* pw = all_words[try_password];	// try_password is the index from the original words list (all_words)
	ListArrayIterator<String>* pw_iter = all_words->iterator();	// num_matches is the number of characters that should match
	while (pw_iter->hasNext())
	{
		String* pw_guess = pw_iter->next();
		int matches = getNumMatches(pw, pw_guess);

		if (matches == num_matches)
		{
			viable_words->add(pw_guess);
		}
	}	// Walk through each of "all words"
		// ONLY add them to viable_words IF matches == num_matches

}

int Password::getNumberOfPasswordsLeft()
{
	return currVi;
}

void Password::displayViableWords()
{
	ListArrayIterator<String>* viable_iter = viable_words->iterator();
	while (viable_iter->hasNext())
	{
		viable_words[currVi]->displayString();
	}
	delete viable_iter;
}

int Password::bestGuess()
{
   int best_guess_index = -1;
   int best_num_eliminated = -1;
   int num_viable_passwords = getNumberOfPasswordsLeft();

   //loop over ALL words, even if they have been eliminated as the password
   int count = 1;
   ListArrayIterator<String>* all_iter = all_words->iterator();
   while(all_iter->hasNext())
   {
      String* original_word = all_iter->next();

      //loop over only those words that could still be the password
      //count up the number of matches between a possible password and a word in the original list
      int* count_num_matches = new int[len + 1];

      for (int i = 0; i < len; i++) 
      {
         count_num_matches[i] = 0;
      }

      ListArrayIterator<String>* viable_iter = viable_words->iterator();
      while(viable_iter->hasNext())
      {
         String* viable_word = viable_iter->next();
         int num_matches = getNumMatches(viable_word, original_word);
         count_num_matches[num_matches]++;
      }
      delete viable_iter;

      //find the largest number in the count_num_matches array
      //the largest number indicates the guess that will generate the most eliminations
      int most_num_matches = 0;
      for (int j = 0; j < len; j++) 
      {
         int curr_num_matches = count_num_matches[j];
         if (curr_num_matches > most_num_matches)
         {
            most_num_matches = curr_num_matches;
         }
      }

      //compute the fewest that can possibly be eliminated by guessing the current word (original list)
      int num_eliminated = num_viable_passwords - most_num_matches;

      //select the word to guess that maximizes the minimum number of eliminations (minimax)
      if (num_eliminated > best_num_eliminated)
      {
         best_num_eliminated = num_eliminated;
         best_guess_index = count;
      }
      
      count++;
      delete[] count_num_matches;
   }

   delete all_iter;
   return best_guess_index;  //return a 1-based index into the all_words list of words (careful)
}

String* Password::getOriginalWord(int index)
{
	return all_words[index-1];
}
