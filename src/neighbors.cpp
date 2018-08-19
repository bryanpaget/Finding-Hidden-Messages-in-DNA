#include "neighbors.h"

using namespace std;

string alphabet = "ACGT";

unsigned int hamming_distance(const string &pattern1, const string &pattern2)
{
  unsigned int my_hamming_distance = 0;
  for (unsigned int i = 0; i < pattern1.size(); ++i)
    if (pattern1[i] != pattern2[i]) ++my_hamming_distance;
  return my_hamming_distance;
}

string tail(const string& pattern) { return pattern.substr(1, pattern.size()); }

string head(const string& pattern) { return pattern.substr(0,1); }

vector<string> neighbors(const string& pattern, unsigned int d)
{
  if (d == 0) return {pattern};
  if (pattern.size() == 1) return {"A", "C", "G", "T"};

  vector<string> neighborhood;
  vector<string> tail_neighborhood = neighbors(tail(pattern), d);
  for (auto& neighbor : tail_neighborhood) {
    if (hamming_distance(tail(pattern), neighbor) < d) {
      for (auto& nucleotide : alphabet)
        neighborhood.push_back(nucleotide + neighbor);
    } else {
      neighborhood.push_back(head(pattern) + neighbor);
    }
  }
  return neighborhood;
}

// int main()
// {
//   string pattern = "GAGG";
//   unsigned int d = 3;
//   vector<string> my_ns = neighbors(pattern, d);
//   cout << my_ns.size() << endl;
// }
