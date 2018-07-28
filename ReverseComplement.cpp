#include <map>
#include <string>
#include <iostream>

using namespace std;

char complement(char& c)
{
  map<char, char> complements;
  complements = {{'A', 'T'}, {'T', 'A'}, {'G', 'C'}, {'C', 'G'}};
  return complements[c];
}

string reverse_complement(string sequence)
{
  int i = sequence.length()-1;
  string my_complement;
  string reverse_complement;
  char comp;

  while (i >= 0) {
    comp = complement(sequence[i]);
    my_complement.push_back(comp);
    --i;
  }

  return my_complement;
}

int main(int argc, char** argv)
{
  std::cout << reverse_complement(argv[1]) << std::endl;
}
