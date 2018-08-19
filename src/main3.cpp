#include "MotifEnumeration.h"
#include "Neighborhood.h"

#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
  unsigned int k = atoi(argv[1]);
  unsigned int d = atoi(argv[2]);
  ifstream file(argv[3]);

  string line;
  set<string> DNA;
  if (file.is_open())
    while (getline(file, line))
      DNA.insert(line);

  cout << "Genome:" << endl << endl;
  for (auto &elem : DNA)
    cout << elem << endl;
  cout << endl;

  cout << "MotifEnumeration!" << endl << endl;
  set<string> output;
  output = MotifEnumeration(k, d, DNA);

  for (auto &elem : output)
    cout << elem << endl;

  return 0;
}
