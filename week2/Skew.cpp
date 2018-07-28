#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<int> skew(string &genome)
/* We define skew_i(genome) to be the difference between the total
   number of occurences of G and the total number of occurences of C
   in thr first i nucleotides of genome. */
{
  vector<int> my_skew(genome.length());

  unsigned int i = 0;
  for (auto &elem : genome) {
    if (i == 0) my_skew[i] = 0;
    else {
      if (elem == 'C')
        my_skew[i] = my_skew[i-1] - 1;
      else if (elem == 'G')
        my_skew[i] = my_skew[i-1] + 1;
      else
        my_skew[i] = my_skew[i-1];
    }
    ++i;
  }
  return my_skew;
}



int main(int argc, char **argv)
{
  string genome = argv[1];
  vector<int> my_skew = skew(genome);
  for (auto &elem : my_skew) {
    cout << elem << " ";
  }
  cout << endl;
}
