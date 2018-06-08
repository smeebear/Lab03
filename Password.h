#if !defined PASSWORD_H
#define PASSWORD_H

#include "Text.h" //complete the includes
using CSC1310::String;
#include "ListArray.h"
using CSC1310::ListArray;

class Password
{
   private:
      ListArray<String>* viable_words;  //the list of words that can still be the password
      ListArray<String>* all_words;  //the original list of words
      int len;  //the length of the first word entered is stored to check that all subsequent words have the same length
      int currVi;
      int currAll;

      //a private helper method to report the number of character matches between two Strings
      int getNumMatches(String* curr_word, String* word_guess);

   public:
		Password();
		~Password();
		void addWord(String* word);
		void guess(int try_password, int num_matches);
		int getNumberOfPasswordsLeft();
		void displayViableWords();
		int bestGuess();
		String* getOriginalWord(int index);
};

#endif

