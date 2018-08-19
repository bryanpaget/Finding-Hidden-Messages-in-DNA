#ifndef GREEDYMOTIFSEARCH_H
#define GREEDYMOTIFSEARCH_H

#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <fstream>
#include <boost/tokenizer.hpp>

#include "MedianString.h"
#include "Hamming.h"
#include "MotifEnumeration.h"
#include "Entropy.h"

std::vector<std::string> kmers(std::string sequence, unsigned int k);

std::vector<std::string> GreedyMotifSearch(std::vector<std::string> DNA, unsigned int k, unsigned int t);

#endif // GREEDYMOTIFSEARCH_H
