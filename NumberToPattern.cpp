#include "NumberToPattern.h"

using namespace std;

string alphabet = "ACGT";

map<int, string> get_all_words(int length)
{
  vector<int> index(length, 0);
  for (auto& elem : index) {
    cout << elem;
  }
  map<int, string> words;

  int idx = 0;
  while(true)
  {
    string word("_", length);
    for (int i = 0; i < length; ++i)
      word[i] = alphabet[index[i]];
    words.insert({idx, word});

    for (int i = length-1; ; --i)
    {
      if (i < 0) return words;
      index[i] = (index[i]+1) % alphabet.size();
      if (index[i] != 0) break;
    }
    ++idx;
  }
}

int main(int argc, char **argv)
{
  map<int, string> words = get_all_words(stoi(argv[1]));
  cout << words[stoi(argv[2])] << endl;
}
