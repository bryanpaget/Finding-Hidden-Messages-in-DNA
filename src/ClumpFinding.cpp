#include <map>
#include <string>
#include <iostream>

using namespace std;

map<string, unsigned int> kmers(unsigned int k, string &sequence)
{
  map<string, unsigned int> kmers;
  string sub;

  for (unsigned int i = 0; i <= (sequence.length()-k); ++i) {
    sub = sequence.substr(i, k);

    auto search = kmers.find(sub);
    if (search != kmers.end())
      ++kmers[sub];
    else
      kmers.insert({sub, 1});
  }

  return kmers;
}

map<string, unsigned int> clump_finder(string &genome,  unsigned int &k,
                                       unsigned int &L, unsigned int &t)
{
  unsigned int i;
  string sequence;
  map<string, unsigned int> my_kmers;
  map<string, unsigned int> keepers;

  for (i = 0; i <= genome.length()-L; ++i) {
    sequence = genome.substr(i, L);
    my_kmers = kmers(k, sequence);
    for (auto &elem : my_kmers) {
      if (elem.second >= t) keepers.insert(elem);
    }
  }
  return keepers;
}

int main(int argc, char** argv)
{
    string genome = argv[1];
    unsigned int k = stoi(argv[2]); // length of k-mer
    unsigned int L = stoi(argv[3]); // L is window length
    unsigned int t = stoi(argv[4]); // k-mer must appear >= this many times

    map<string, unsigned int> clumps = clump_finder(genome, k, L, t);

    for (auto &elem : clumps) {
      cout << elem.first << ", " << elem.second << endl;
    }

}
