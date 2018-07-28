#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<unsigned int> starting_positions(string sequence, string genome)
{
  vector<unsigned int> positions;
  string substring;
  unsigned int pos;
  unsigned int k = sequence.size();
  for (pos = 0; pos <= genome.size() - k; ++pos) {
    substring = genome.substr(pos, k);
    if (substring == sequence) {
      positions.push_back(pos);
    }
  }
  return positions;
}

int main(int argc, char **argv)
{
    vector<unsigned int> sp = starting_positions(argv[1], argv[2]);
    for (auto& elem : sp) {
        cout << elem << " ";
    }
    cout << endl;
}
