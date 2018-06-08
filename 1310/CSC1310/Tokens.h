#if !defined TOKENS_H
#define TOKENS_H

#include "Text.h"
using CSC1310::String;

namespace CSC1310
{
class Tokens
{
   private:
      String** tokens;
      int max_tokens;
      int sz;

      void addToken(String* str);  //requires a resizing check
      void resize();

   public:
      Tokens(String* str, char delimiter);
      ~Tokens();  //Tokens is not responsible for deleting each token
      void displayTokens();
      String* getToken(int index);  //returns a specifically requested token
      int getNumTokens();
};
}

#endif