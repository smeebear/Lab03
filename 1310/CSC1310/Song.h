#if !defined SONG_H
#define SONG_H

#include "Text.h"
using CSC1310::String;

namespace CSC1310
{
class Song
{
   private:
      String* title;
      String* length;

   public:
      Song(String* title, String* length);
      virtual ~Song();
      void displaySong();
};
}

#endif
