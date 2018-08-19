#include "RandomizedMotifSearch.h"
#include "utils.h"

using namespace std;

vector<string> MotifSearch(vector<string> DNA, unsigned int k, vector<vector<double> > my_profile)
{
  vector<string> motif;
  for (auto &sequence : DNA)
    motif.push_back(MostProbablekmer(sequence, k, my_profile));
  return motif;
}

unsigned int NumKmers(vector<string> &DNA, unsigned int k) { return DNA[0].size() - k + 1; }

vector<string> Random(vector<string> DNA, unsigned int k, unsigned int N)
{
  vector<string> my_random_motifs;
  vector<string> my_best_motifs;
  vector<vector<double> > my_profile;

  for (auto &sequence : DNA)
    my_random_motifs.push_back(sequence.substr(my_random(N), k));
  my_best_motifs = my_random_motifs;

  while(true) {
    my_random_motifs = (MotifSearch(DNA, k, profile(my_random_motifs)));
    if (score(my_random_motifs) < score(my_best_motifs))
      my_best_motifs = my_random_motifs;
    else
      return my_best_motifs;
  }
}

vector<string> RandomizedMotifSearch(vector<string> DNA, unsigned int k, unsigned int t)
{
  unsigned int num_runs = 1;
  map<double, vector<string> > my_map;

  unsigned int N = NumKmers(DNA, k);

  vector<vector<string> > my_ms;
  for (unsigned int i = 0; i < num_runs; ++i)
    my_ms.push_back(Random(DNA, k, N));

  vector<double> my_scores;
  for (auto &m: my_ms)
    my_scores.push_back(score(m));

  for (size_t i = 0; my_scores.size(); ++i)
    my_map[my_scores[i]] = my_ms[i];

  pair<double, vector<string> > b = {10000.0, {}};
  for (auto &score : my_map)
    if (score.first < b.first)
      b = score;

  return b.second;
}

// int main(int argc, char **argv)
// {
//   string tmp;
//   ifstream file(argv[1]);
//   unsigned int k, t;
//
//   vector<string> DNA;
//
//   getline(file, tmp);
//   k = stoi(tmp);
//   getline(file, tmp);
//   t = stoi(tmp);
//   while (getline(file, tmp))
//     DNA.push_back(tmp);
//
//   vector<string> my_ms = RandomizedMotifSearch(DNA, k, t);
//
//   for (auto &elem : my_ms)
//     cout << elem << endl;
//
//   return 0;
// }
