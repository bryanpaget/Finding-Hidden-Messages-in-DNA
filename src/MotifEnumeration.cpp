#include "MotifEnumeration.h"

using namespace std;

struct kmer
{
  string kmer;
  set<string> neighbors;
};

bool AllTrue(vector<bool> v)
{
  bool t = true;
  for (auto elem : v) {
    if (elem == false)
      t = false;
  }
  return t;
}

bool HammingFind(string pattern, string seq, unsigned int d)
{
  unsigned int i;
  bool in = false;
  string sub;
  unsigned int pat_len = pattern.length();

  if (seq.find(pattern) != string::npos) {
    in = true;
  } else {
    for (i = 0; i <= seq.length() - pat_len; ++i) {
      sub = seq.substr(i, pat_len);
      if (hamming_distance(sub, pattern) <= d) {
        return true;
      }
    }
  }

  return in;
}

set<string> MotifEnumeration(unsigned int &k, unsigned int &d, set<string> &DNA)
{
  unsigned int i;
  unsigned int num_kmers = DNA.begin()->size() - k;
  set<string> motifs;
  vector<kmer> neighborhood;
  for (auto &strand: DNA)
    for (i = 0; i <= num_kmers; ++i) {
      string substring = strand.substr(i, k);
      set<string> my_neighbors = neighbors(substring, d);
      struct kmer my_kmer;
      my_kmer.kmer = substring;
      my_kmer.neighbors = my_neighbors;
      neighborhood.push_back(my_kmer);
    }

  for (auto my_kmer : neighborhood) {
    for (auto variant : my_kmer.neighbors) {
      vector<bool> in(DNA.size(), false);
      i = 0;
      for (auto seq : DNA) {
        if (HammingFind(variant, seq, d))
          in[i] = true;
        else
          in[i] = false;
        ++i;
      }
      if (AllTrue(in)) {
        motifs.insert(variant);
      }
    }
  }

  return motifs;
}
