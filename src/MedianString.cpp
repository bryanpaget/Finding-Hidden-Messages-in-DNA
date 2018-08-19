#include "MedianString.h"

using namespace std;

unsigned int SymbolToNumber(const char &c)
{
  string alphabet = "ACGT";

  unsigned int i = 0;
  while (alphabet[i] != c) ++i;
  return i;
}

double kmerProbability(string kmer, vector<vector<double> > &profile)
{
  double p = 1.;
  for (unsigned int i = 0; i < kmer.size(); ++i)
    p *= profile[i][SymbolToNumber(kmer[i])];
  return p;
}

string MostProbablekmer(string sequence, unsigned int k, vector<vector<double> > profile)
{
  string sub;
  vector<string> my_kmers = kmers(k, sequence);
  string most_probable_kmer = sequence.substr(0,k);

  double kmer_prob;
  double max_prob = 0;
  for (string km : my_kmers) {
    kmer_prob = kmerProbability(km, profile);
    if (kmer_prob > max_prob) {
      most_probable_kmer = km;
      max_prob = kmer_prob;
    }
  }
  return most_probable_kmer;
}

vector<string> kmers(unsigned int k, string sequence)
{
  unsigned int num_kmers = sequence.size() - k + 1;
  vector<string> my_kmers;
  for (unsigned int i = 0; i < num_kmers; ++i) {
    my_kmers.push_back(sequence.substr(i, k));
  }
  return my_kmers;
}

unsigned int DistanceBetweenPatternAndString(string pattern, set<string> motifs)
{
  unsigned int k = pattern.size();
  unsigned int my_d = 0;
  unsigned int my_hamming_distance, the_hamming_distance;

  for (auto &m : motifs) {
    my_hamming_distance = 1000;
    for (auto &km : kmers(k, m)) {
      the_hamming_distance = hamming_distance(km, pattern);
      if (my_hamming_distance > the_hamming_distance) {
        my_hamming_distance = the_hamming_distance;
      }
    }
    my_d += my_hamming_distance;
  }
  return my_d;
}

string MedianString(set<string> DNA, unsigned int k)
{
  string my_median_string;
  vector<set<string> > motifs;
  unsigned int my_d = k-1;
  unsigned int distance = 1000; // some big integer to start

  if (my_d > 0) {
    do { // get ALL motifs, for each d < k
      motifs.push_back(MotifEnumeration(k, my_d, DNA));
      --my_d;
    } while (my_d != 0);
  } else {
    return "";
  }

  for (auto &v : motifs)
    for (auto &m : v) {
      unsigned int d = DistanceBetweenPatternAndString(m, DNA);
      if (distance > d) {
        distance = d;
        my_median_string = m;
      }
    }
  return my_median_string;
}
