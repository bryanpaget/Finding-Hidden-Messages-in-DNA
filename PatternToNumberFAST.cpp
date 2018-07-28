#include <iostream>
#include <map>
#include <string>

using namespace std;

int64_t PatternToNumber(string pattern)
{
  int64_t number = 0;

  map<char, int> my_map = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

  for (unsigned int i = 0; i < pattern.length(); ++i) {
    number = (number * 4) + my_map[pattern[i]];
  }

  return number;
}

int main()
{
  string pattern = "TGCCTTGAGTCTAACGTGAAACCTACGTTGCGCAG";
  int64_t number = PatternToNumber(pattern);
  cout << number << endl;
}
