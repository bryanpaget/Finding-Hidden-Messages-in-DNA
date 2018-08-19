#ifndef GENOME_H
#define GENOME_H

#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <iomanip>
#include <set>

class Genome
{
public:
  Genome(unsigned int length);
  Genome(std::string& genome);
  unsigned int get_length();
  unsigned int pattern_counter(std::string pattern);
  std::vector<std::string> most_popular_k_mers(unsigned int k);
  std::string get_genome();
  std::string reverse_complement();
  std::vector<unsigned int> starting_positions(std::string& sequence);
private:
  unsigned int max_of_set(std::set<unsigned int> &my_set);
  void initialize();
  std::random_device rd;
  typedef std::mt19937 MyRng;
  MyRng my_rng;
  std::uniform_int_distribution<unsigned int> unif;
  char random_letter();
  char complement(char& c);
  std::string alphabet = "ACGT";
  std::string genome;
  unsigned int length;
};

#endif // GENOME_H
