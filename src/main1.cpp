#include "hamming.h"

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
  string pattern = argv[1];
  string genome = argv[2];
  string d = argv[3];
  unsigned int distance = stoi(d);
  string sub;

  vector<unsigned int> hamming_distances(genome.size()-pattern.size(), 0);
  vector<int> hamming_locations;

  for (unsigned int i = 0; i <= genome.size() - pattern.size(); ++i) {
    sub = genome.substr(i, pattern.size());
    hamming_distances[i] = hamming_distance(pattern, sub);
    if (hamming_distances[i] <= distance) hamming_locations.push_back(i);
  }

  cout << hamming_locations.size() << endl;
}
