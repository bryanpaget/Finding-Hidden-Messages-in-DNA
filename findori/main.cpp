#include <iostream>
#include <vector>
#include <string>

#include "skew.h"
#include "findori.h"

using namespace std;

int main(int argc, char **argv)
{
  string genome = argv[1];
  vector<int> my_skew = skew(genome);
  vector<int> my_mins = find_min(my_skew);
  for (auto &elem : my_mins)
    cout << elem << " ";
  cout << endl;
}
