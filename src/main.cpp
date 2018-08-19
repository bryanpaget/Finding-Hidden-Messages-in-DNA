#include "genome.h"

using namespace std;

int main(int argc,  char **argv)
{
  string genome = "CGGAGGACTCTAGGTAACGCTTATCAGGTCCATAGGACATTCA";
  Genome my_genome(genome);

    vector<string> m = my_genome.most_popular_k_mers(3);

    for (auto &elem : m) {
      cout << elem << endl;
    }
}
