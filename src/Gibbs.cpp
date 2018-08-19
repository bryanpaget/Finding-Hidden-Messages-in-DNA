#include "RandomizedMotifSearch.h"
#include "MedianString.h"
#include "utils.h"

#include <vector>
#include <map>
#include <random>
#include <iostream>

using namespace std;

vector<double> normalize(vector<double> dist)
{
  double sum = 0.;
  for (auto elem : dist)
    sum += elem;

  for (unsigned int i = 0; i < dist.size(); ++i)
    dist[i] = dist[i]/sum;

  return dist;
}

unsigned int Random(vector<double> flattened_profile)
{
  random_device rd;
  mt19937 gen(rd());
  discrete_distribution<> distribution(flattened_profile.begin(), flattened_profile.end());
  return distribution(gen);
}

string RandomKmer(vector<vector<double> > profile, unsigned int k, string sequence)
{
  string random_kmer, sub;
  vector<double> probabilities;
  vector<string> my_kmers = kmers(k, sequence);

  for (auto km : my_kmers)
    probabilities.push_back(kmerProbability(km, profile));

  random_kmer = my_kmers[Random(probabilities)];

  return random_kmer;
}

vector<double> flattenProfile(vector<vector<double> > profile)
{
  unsigned int rows = profile.size();
  unsigned int columns = profile[0].size();

  vector<double> dist(columns, 0.);
  for (unsigned int j  = 0; j < columns; ++j)
    for (unsigned int i = 0; i < rows; ++i)
      dist[j] += profile[i][j];

  dist = normalize(dist);

  return dist;
}

vector<string> remove(vector<string> motifs, unsigned int index)
{
  vector<string> new_motifs;
  unsigned int num_motifs = motifs.size();

  for (unsigned int i = 0; i < num_motifs; ++i)
    if (i == index)
      continue;
    else
      new_motifs.push_back(motifs[i]);
  return new_motifs;
}

vector<string> replace(vector<string> motifs, string sequence, unsigned int index)
{
  vector<string> new_motifs;
  unsigned int num_motifs = motifs.size();
    for (unsigned int i = 0; i < num_motifs; ++i)
      if (i != index)
        new_motifs.push_back(motifs[i]);
      else if (i == index)
        new_motifs.push_back(sequence);
  return new_motifs;
}

vector<string> Gibbs(vector<string> DNA, unsigned int k, unsigned int t, unsigned int N)
{
  unsigned int num_kmers = NumKmers(DNA, k);
  vector<string> my_best_motifs;

  for (auto& sequence : DNA)
    my_best_motifs.push_back(kmers(k, sequence)[my_random(num_kmers)]);

  vector<string> motifs;
  vector<vector<double> > my_other_profile;

  for (unsigned int j = 0; j < N; ++j) {
    unsigned int index = my_random(t);
    my_other_profile = profile(remove(my_best_motifs, index));
    motifs = replace(my_best_motifs, kmers(k, DNA[index])[my_random(num_kmers)], index);
    if (entropy(motifs) < entropy(my_best_motifs))
      my_best_motifs = motifs;
  }
  return my_best_motifs;
}

vector<string> GibbsSampler(vector<string> DNA, unsigned int k, unsigned int t, unsigned int N)
{
  unsigned int num_runs = 20;
  map<double, vector<string> > my_map;

  vector<vector<string> > my_collection_of_motifs;

  for (unsigned int i = 0; i < num_runs; ++i)
    my_collection_of_motifs.push_back(Gibbs(DNA, k, t, N));

  vector<double> my_scores;
  for (auto &m: my_collection_of_motifs)
    my_scores.push_back(entropy(m));

  for (size_t i = 0; i < my_scores.size(); ++i)
    my_map[my_scores[i]] = my_collection_of_motifs[i];

  pair<double, vector<string> > b = {10000.0, {}};
  for (auto &score : my_map)
    if (score.first < b.first)
      b = score;

  return b.second;
}


int main(int argc, char **argv)
{

  string tmp;
  ifstream file(argv[1]);
  unsigned int k, t, N;

  vector<string> DNA;

  getline(file, tmp);
  k = stoi(tmp);
  getline(file, tmp);
  t = stoi(tmp);
  getline(file, tmp);
  N = stoi(tmp);
  while (getline(file, tmp))
    DNA.push_back(tmp);
  return 0;

}

