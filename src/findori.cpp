#include "skew.h"
#include "findori.h"

using namespace std;

vector<int> find_max(vector<int> my_skew)
{
  int max = my_skew[0];
  vector<int> max_pos;

  for (auto &elem : my_skew)
    if (elem > max) max = elem;
  for (unsigned int i = 0; i < my_skew.size(); ++i)
    if (my_skew[i] == max ) max_pos.push_back(i);

  return max_pos;
}

vector<int> find_min(vector<int> my_skew)
{
  int min = my_skew[0];
  vector<int> min_pos;

  for (auto &elem : my_skew)
    if (elem < min) min = elem;
  for (unsigned int i = 0; i < my_skew.size(); ++i)
    if (my_skew[i] == min) min_pos.push_back(i);

  return min_pos;
}
