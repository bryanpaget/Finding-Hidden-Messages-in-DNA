#ifndef MOTIFENUMERATION_H
#define MOTIFENUMERATION_H

#include <string>
#include <set>
#include <vector>
#include <iostream>

#include "Neighborhood.h"
#include "Hamming.h"

std::set<std::string> MotifEnumeration(unsigned int &k, unsigned int &d, std::set<std::string> &DNA);

#endif // MOTIFENUMERATION_H
