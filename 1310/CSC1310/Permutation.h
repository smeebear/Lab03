#if !defined (PERMUTATION_H)
#define PERMUTATION_H

#include "ListArray.h"
using CSC1310::ListArray;
#include "Integer.h"
using CSC1310::Integer;
#include "Random.h"
using CSC1310::Random;

namespace CSC1310
{
class Permutation
{
   private:
      int r;
      ListArray<Integer>* numbers;
      Random* random;

   public:
      Permutation(int r, int n);
      virtual ~Permutation();
      int next();
};
}

#endif
