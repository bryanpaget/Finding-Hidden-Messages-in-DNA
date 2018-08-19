#include <map>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

string alphabet = "ACGT";

map<string, unsigned int> get_all_words(int length)
{
  vector<unsigned int> index(length, 0);
  map<string, unsigned int> words;

  while(true)
  {
    string word("_", length);
    for (int i = 0; i < length; ++i)
      word[i] = alphabet[index[i]];
    words.insert({word, 0});

    for (int i = length-1; ; --i)
    {
      if (i < 0) return words;
      index[i] = (index[i]+1) % alphabet.size();
      if (index[i] != 0) break;
    }
  }
}


vector<unsigned int> ComputingFrequencies(string &sequence, unsigned int k)
{
  map<string, unsigned int> kmers = get_all_words(k);
  string sub;
  vector<unsigned int> freqs;

  for (int i = 0; i < pow(4, k); ++i) {
    freqs.push_back(0);
  }
  freqs[0] = 0;

  for (unsigned int i = 0; i <= (sequence.length()-k); ++i) {
    sub = sequence.substr(i, k);

    auto search = kmers.find(sub);
    if (search != kmers.end())
      kmers[sub] = kmers[sub] + 1;
    else
      kmers.insert({sub, 1});
  }

  int i = 0;
  for (auto &elem : kmers) {
    freqs[i] = (int)elem.second;
    ++i;
  }

  return freqs;
}

int main(int argc, char** argv)
{
  string genome = argv[1];
  unsigned int k = stoi(argv[2]);

  vector<unsigned int> my_kmers = kmers(k, genome);

  for (int i = 0; i < my_kmers.size(); ++i) {
    cout << my_kmers[i] << " ";
  }
  cout << endl;
}