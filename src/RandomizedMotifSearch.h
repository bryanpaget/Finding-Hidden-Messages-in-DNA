#ifndef RANDOMIZEDMOTIFSEARCH_H
#define RANDOMIZEDMOTIFSEARCH_H

#include <iostream>
#include <map>

#include "Entropy.h"
#include "GreedyMotifSearch.h"

std::vector<std::string> MotifSearch(std::vector<std::string> DNA, unsigned int k, std::vector<std::vector<double> > my_profile);

unsigned int NumKmers(std::vector<std::string> &DNA, unsigned int k);

std::vector<std::string> Random(std::vector<std::string> DNA, unsigned int k, unsigned int N);

std::vector<std::string> RandomizedMotifSearch(std::vector<std::string> DNA, unsigned int k, unsigned int t);

#endif // RANDOMIZEDMOTIFSEARCH_H
