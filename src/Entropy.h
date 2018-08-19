#ifndef ENTROPY_H
#define ENTROPY_H

#include <vector>
#include <string>
#include <iostream>
#include <math.h>

std::vector<double> entropy_vector(std::vector<std::vector<double> > profile);

double entropy(std::vector<std::string> motifs);

std::vector<double> motif_logo(std::vector<std::vector<double> > profile);

char integer_to_allele(unsigned int i);

template <typename T>
unsigned int my_max(std::vector<T> v);

unsigned int locate_max(std::vector<double> v);

std::vector<unsigned int> count_alleles(std::string seq);

std::vector<std::string> transpose(std::vector<std::string> matrix);

std::vector<std::vector<unsigned int> > counts(std::vector<std::string> motifs);

std::vector<std::vector<double> > profile(std::vector<std::vector<unsigned int> > counts);

std::vector<std::vector<double> > profile(std::vector<std::string> motifs);

std::string consensus(std::vector<std::vector<double> > profile);

unsigned int score(std::vector<std::string> motifs);

struct motifs
{
  std::vector<std::string> motifs;
  unsigned int num_seq;
  unsigned int seq_length;
  std::vector<std::vector<double> > profile;
  std::vector<std::vector<int> > counts;
  std::string consensus;
  unsigned int score;
  double entropy;
  std::vector<double> motif_logo;
};

#endif // ENTROPY_H
