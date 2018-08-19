#include "GreedyMotifSearch.h"

using namespace std;

vector<string> kmers(string sequence, unsigned int k)
{
  vector<string> my_kmers;
  unsigned int num_kmers = sequence.size() - k + 1;

  for (unsigned int i = 0; i < num_kmers; ++i)
    my_kmers.push_back(sequence.substr(i, k));

  return my_kmers;
}

vector<string> GreedyMotifSearch(vector<string> DNA, unsigned int k, unsigned int t)
{
  vector<string> best_motif;
  vector<string> motif;
  vector<vector<double> > my_profile;

  vector<vector<string> > my_kmers;
  for (auto &sequence : DNA) {
    vector<string> m = kmers(sequence, k);
    my_kmers.push_back(m);
    best_motif.push_back(m[0]);
  }

  for (auto kmer : my_kmers[0]) {
    motif.push_back(kmer);
    for (unsigned int i = 1; i < t; ++i) {
      my_profile = profile(counts(motif));
      motif.push_back(MostProbablekmer(DNA[i], k, my_profile));
    }
    if (score(motif) < score(best_motif))
      best_motif = motif;
    motif.clear();
  }
  return best_motif;
}
