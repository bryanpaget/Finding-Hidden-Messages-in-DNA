#include "genome.h"

using namespace std;

Genome::Genome(unsigned int length)
  : my_rng(rd()), unif(uniform_int_distribution<unsigned int>(0, 3)), length(length)
{
  my_rng.seed(time(NULL));
  uniform_int_distribution<unsigned int> unif;
  initialize();
}

Genome::Genome(string& genome)
  : genome(genome) {}

void Genome::initialize()
{
  for (unsigned int i = 0; i < length; ++i)
     genome += random_letter();
}

char Genome::random_letter() { return alphabet[unif(my_rng)]; }

string Genome::get_genome() { return genome; }

unsigned int Genome::get_length() { return length; }

unsigned int Genome::pattern_counter(string pattern)
{
  const unsigned int k = pattern.size();
  unsigned int count = 0;
  string sub;
  char *p;

  for (unsigned int i = 0; i < genome.length(); ++i) {
    p = &genome[i];

    while (p != &genome[i+k]) {
      sub += *p;
      ++p;
    }

    if (pattern == sub)
      ++count;

    sub.clear();
  }

  return count;
}

vector<string> Genome::most_popular_k_mers(unsigned int k)
{
  vector<string> most_popular;
  map<string, unsigned int> kmers;
  string sub;
  char *p;
  set<unsigned int> popularity_counts;
  unsigned int max;

  for (unsigned int i = 0; i < genome.length() - k + 1; ++i) {
    p = &genome[i];
    while (p != &genome[i+k]) {
      sub += *p;
      ++p;
    }

    auto search = kmers.find(sub);

    if (search != kmers.end())
      ++kmers[sub];
    else
      kmers.insert({sub, 1});
    sub.clear();
  }

  for (auto& t : kmers)
    popularity_counts.insert(t.second);

  max = max_of_set(popularity_counts);

  for (auto& t : kmers)
    if (t.second == max)
      most_popular.push_back(t.first);

  return most_popular;
}

unsigned int Genome::max_of_set(set<unsigned int> &my_set)
{
  unsigned int max = 0;

  for (auto& elem : my_set)
    if (max < elem)
      max = elem;

  return max;
}

map<string, unsigned int> words_index(unsigned int k)
{
  string alphabet = "ACGT";
  int j;
  unsigned int i, word_index;
  vector<int> index(k, 0);
  map<string, unsigned int> sequence_index;
  word_index = 1;
  while (true) {
    string word(k, '_');
    for (i = 0; i < k; ++i) word[i] = alphabet[index[i]];
    sequence_index.insert({word, word_index});
    ++word_index;
    for (j = k-1; ; --j) {
      if (j < 0) return sequence_index;
      index[j] = (index[j] + 1) % alphabet.size();
      if (index[j] != 0) break;
    }
  }
}

unsigned int sequence_to_integer(string sequence)
{
  string alphabet = "ACGT";
  map<string, unsigned int> sequence_index;
  sequence_index = words_index(sequence.size());
  return sequence_index[sequence];
}

string Genome::reverse_complement()
{
  int i = genome.length() - 1;
  string my_complement;
  string reverse_complement;
  char comp;

  while (i >= 0) {
    comp = complement(genome[i]);
    my_complement.push_back(comp);
    --i;
  }

  return my_complement;
}

char Genome::complement(char& c)
{
  map<char, char> complements;
  complements = {{'A', 'T'}, {'T', 'A'}, {'G', 'C'}, {'C', 'G'}};
  return complements[c];
}

vector<unsigned int> Genome::starting_positions(string& sequence)
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
