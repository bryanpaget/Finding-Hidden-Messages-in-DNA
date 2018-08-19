#include "Hamming.h"
#include <iostream>

using namespace std;

unsigned int hamming_distance(string pattern1, string pattern2)
{
  unsigned int my_hamming_distance = 0;

  for (unsigned int i = 0; i < pattern1.size(); ++i) {
    if (pattern1[i] != pattern2[i]) ++my_hamming_distance;
  }

  return my_hamming_distance;
}
