#if !defined READ_FILE_H
#define READ_FILE_H

#include "Text.h"

#include <fstream>
using namespace std;

namespace CSC1310
{
class ReadFile
{
   private:
      ifstream* input_file;
      bool _eof;
      bool closed;

   public:
      ReadFile(const char* file_name);
      ~ReadFile();
      CSC1310::String* readLine();
      bool eof();
      void close();
};
}

#endif
