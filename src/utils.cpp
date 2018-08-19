#include "utils.h"

#include <iostream>

using namespace std;

mt19937 rng(time(NULL));

random_device rd;
mt19937 gen(rd());

unsigned int my_random(unsigned int n) {
  if (n == 1) {
    uniform_int_distribution<int> distribution(0, 1);
    return distribution(rng);
  } else {
    uniform_int_distribution<int> distribution(0, n-1);
    return distribution(rng);
  }
}

double my_random_real(double n) {
  uniform_real_distribution<double> distribution(0.0, n);
  return distribution(gen);
}

template <typename T>
map<unsigned int, T> enumerate(vector<T> container)
{
}
