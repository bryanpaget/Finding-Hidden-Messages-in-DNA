#include <string>
#include <algorithm>

using namespace std;

class PatternCounter
{
public:
  PatternCounter() : count_(0) {}
  int get_count();
private:
  int count_;
};

int PatternCounter::get_count() {
  return count_;
}

// for each
// with a lambda function parameterized by the length of the mer.

// haplo = squashed_haplotype_results[j][4].substr(i,2); // consider the following 2-locus haplotype
