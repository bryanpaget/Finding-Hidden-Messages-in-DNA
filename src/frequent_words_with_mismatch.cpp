#include<vector>
#include<iostream>
#include<map>
#include<set>
#include<cmath>
#include<algorithm>

#include "NumberToPatternFAST.h"
#include "neighbors.h"

using namespace std;

class dword
{
public:
  string word;
  string origin;
  dword(string word, string origin) : word(word), origin(origin) {}
};

vector<string> findMax(map<string, unsigned int> my_most_frequent_words_with_mismatches)
{
  unsigned int max = 0;
  vector<string> most_popular;
  set<unsigned int> popularity_counts;
  for (auto& t : my_most_frequent_words_with_mismatches) {
    popularity_counts.insert(t.second);
  }

  for (auto& elem : popularity_counts) {
    if (max < elem)
      max = elem;
  }

  for (auto& t : my_most_frequent_words_with_mismatches) {
    if (t.second == max) {
      most_popular.push_back(t.first);
    }
  }
  return most_popular;
}

vector<dword> WordsOfInterest(string& pattern, unsigned int k, unsigned int d)
{
  /** This creates an indicator map.  A 1 means: this is is a word of
      interest. Then we only have to look for the words of interest.  **/
  string sub;
  vector<string> my_neighbors;
  vector<dword> my_interesting_words;

  for (unsigned int i = 0; i < pattern.size() - k; ++i) {
    sub = pattern.substr(i, k);
    my_interesting_words.push_back(dword(sub, sub));
    for (auto& neighbor : neighbors(sub, d))
      my_interesting_words.push_back(dword(sub, neighbor));
  }

  return my_interesting_words;
}

// vector<string> FrequentWordsWithMismatches(string& pattern, unsigned int k, unsigned int d)
// {
//   /** Find all kmers in string of length k. **/
//   vector<dword> my_interesting_words = WordsOfInterest(pattern, k, d);
//   map<string, unsigned int> my_most_frequent_words;

//   for (unsigned int i = 0; i < pattern.size() - k; ++i)
//     for (auto& dword : my_interesting_words)
//       if (dword.word == pattern.substr(i, k))
//         ++my_most_frequent_words[dword.origin];

//   vector<string> my_max = findMax(my_most_frequent_words);

//   return my_max;
// }

vector<string> FrequentWordsWithMismatches(string& pattern, unsigned int k, unsigned int d)
{
  map<string, unsigned int> my_most_frequent_words;

  vector<string> kmers;
  for (unsigned int i = 0; i < pow(4,k); ++i)
    kmers.push_back(NumberToPattern(i, k));

  for (auto& kmer : kmers) {
    for (unsigned int i = 0; i < pattern.size() - k; ++i) {
      string sub = pattern.substr(i, k);
      if (hamming_distance(kmer, sub) <= d)
        ++my_most_frequent_words[kmer];
    }
  }

  vector<string> my_max = findMax(my_most_frequent_words);

  return my_max;
}



int main()
{

  string my_string = "TAAGAGCCATCGTAACCACCATCGCCAGAGTAATAACCATCGCCATCGCTCCTCTAATCGCTCCCACCATCGTAATCGGAGCTCGAGCTCTAAGAGCTCCTCCCATAATAAGAGGAGTCGTAATAAGAGTAATAAGAGGAGTAAGAGGAGCTCTCGTCGCCACCATCGCTCCTCCCATCGGAGTCGCCACCAGAGGAGCTCTCGCCAGAGCCATAACCATCGTCGGAGTCGCTCTCGCCACTCCCACTCCCATCGTAATAAGAGGAGTAACCAGAGCCATAAGAGTAATAATAACTCTCGTAATCGGAGGAGTAATAATAACCACTCTAAGAGCCACCATCGCCATCGCCACCATCGTAATCGCTCTCGTAATCG";
  unsigned int d = 3;
  unsigned int k = 6;

  vector<string> my = FrequentWordsWithMismatches(my_string, k, d);

  for (auto& elem : my)
    cout << elem << endl;

  return 0;
}
