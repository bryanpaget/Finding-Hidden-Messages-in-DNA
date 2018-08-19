#include "Greedy.h"

using namespace std;
using namespace boost;

int main(int argc, char **argv)
{
  string tmp;
  ifstream file(argv[1]);
  unsigned int k, t;

  vector<string> DNA;

  getline(file, tmp);
  k = stoi(tmp);
  getline(file, tmp);
  t = stoi(tmp);
  while (getline(file, tmp))
    DNA.push_back(tmp);

  vector<string> motifs = GreedyMotifSearch(DNA, k, t);
  for (auto elem : motifs)
    cout << elem << endl;

  return 0;
}
