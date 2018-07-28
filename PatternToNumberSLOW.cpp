#include <iostream>
#include <map>
#include <stdio.h>

using namespace std;

char alphabet[] = "ACGT";

bool equal(int *arr1, int *arr2, unsigned int length)
{
  for (unsigned int i = 0; i < length; ++i) {
      if (arr1[i] != arr2[i]) return false;
  }
  return true;
}

unsigned int PatternToNumber(char *pattern, unsigned int length)
{
  map<char, int> my_map = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
  int base_4_pattern[length];

  for (unsigned int i = 0; i < length; ++i)
    base_4_pattern[i] = my_map[pattern[i]];

  int base_4_word[length];
  for (auto &elem : base_4_word)
    elem = 0;

  unsigned int index = 0;

  while (!equal(base_4_pattern, base_4_word, length)) {
    ++base_4_word[length-1];
    for (int j = length-1; j > 0; --j) {
      if (base_4_word[j] == 4) {
        base_4_word[j] = 0;
        ++base_4_word[j-1];
      }
    }
    ++index;
  }
  std::cout << length << std::endl;
  return index;
}

int main()
{
  char pattern[] = "CTTCTCACGTACAACAAAATC";
  unsigned int length = 21;
  int number = PatternToNumber(pattern, length);
  cout << number << endl;
}
