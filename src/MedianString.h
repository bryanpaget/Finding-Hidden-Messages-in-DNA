#ifndef MEDIANSTRING_H
#define MEDIANSTRING_H

#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <fstream>
#include <boost/tokenizer.hpp>

#include "Hamming.h"
#include "MotifEnumeration.h"

unsigned int SymbolToNumber(const char &c);

double kmerProbability(std::string kmer, std::vector<std::vector<double> > &profile);

std::string MostProbablekmer(std::string sequence, unsigned int k, std::vector<std::vector<double> > profile);

std::vector<std::string> kmers(unsigned int k, std::string sequence);

unsigned int DistanceBetweenPatternAndString(std::string pattern, std::set<std::string> motifs);

std::string MedianString(std::set<std::string> DNA, unsigned int k);

#endif // MEDIANSTD::STRING_H
