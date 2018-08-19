#include <vector>
#include <iostream>
#include <string>
#include <map>


using namespace std;

string alphabet = "ACGT";

unsigned int SymbolToNumber(const char &c)
{
  unsigned int i = 0;
  while (alphabet[i] != c) ++i;
  return i;
}

class PatternToNumber
{
  private:
    unsigned int length;
    map<string, int> words;
  public:
    PatternToNumber(int length);
    int operator()(string pattern);
};


int PatternToNumber::operator()(string pattern)
{
  return words[pattern];
}

PatternToNumber::PatternToNumber(int length)
  : length(length)
{
  vector<int> index(length, 0);
  int idx = 0;
  while(true) {
    string word("_", length);
    for (int i = 0; i < length; ++i)
      word[i] = alphabet[index[i]];
    words.insert({word, idx});
    for (int i = length-1; ; --i) {
      if (i < 0) return;
      index[i] = (index[i]+1) % alphabet.size();
      if (index[i] != 0) break;
    }
    ++idx;
  }
}


// int main()
// {
//   string pattern = "CGCGG";
//
//
//   PatternToNumber pat(pattern.length());
//   cout << pat(pattern);
//   return 0;
// }
