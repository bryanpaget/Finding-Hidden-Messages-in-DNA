#include "NumberToPatternFAST.h"

using namespace std;

string NumberToPattern(int64_t number, unsigned int num_digits)
{

  int64_t remainder;
  string pattern;

  map<int, char> my_map = {{0, 'A'}, {1, 'C'}, {2, 'G'}, {3, 'T'}};

  while (number > 0) {
    remainder = number % 4;
    number = number / 4;
    pattern += my_map[remainder];
  }

  while (pattern.length() < num_digits) {
    pattern += 'A';
  }

  reverse(pattern.begin(), pattern.end());
  return pattern;
}
