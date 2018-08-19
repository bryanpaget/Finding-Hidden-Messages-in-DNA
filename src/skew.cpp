#include <vector>
#include <string>

#include "skew.h"

using namespace std;

vector<int> skew(string &genome)
/* We define skew_i(genome) to be the difference between the total
   number of occurences of G and the total number of occurences of C
   in the first i nucleotides of genome. */
{
  vector<int> my_skew(genome.length()+1, 0);

  int i = 1;
  for (auto &elem : genome) {
    if (elem == 'C')
      my_skew[i] = my_skew[i-1] - 1;
    else if (elem == 'G')
      my_skew[i] = my_skew[i-1] + 1;
    else
      my_skew[i] = my_skew[i-1];
    ++i;
  }
  return my_skew;
}
