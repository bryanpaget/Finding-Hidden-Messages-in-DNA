#include "Entropy.h"

using namespace std;

vector<double> entropy_vector(vector<vector<double> > profile)
{
  vector<double> entropy_of_columns;
  double entropy_of_column;

  for (auto c : profile) {
    entropy_of_column = 0;
    for (auto d : c) {
      if (d == 0)
        entropy_of_column += 0;
      else
        entropy_of_column += -d*log2(d);
    }
    entropy_of_columns.push_back(entropy_of_column);
  }

  return entropy_of_columns;
}

double entropy(vector<string> motifs)
{

  vector<vector<double> > my_profile = profile(counts(motifs));

  double my_entropy = 0;

  vector<double> my_entropy_vector = entropy_vector(my_profile);
  for (auto e : my_entropy_vector)
    my_entropy += e;

  return my_entropy;
}

vector<double> motif_logo(vector<vector<double> > profile)
{
  vector<double> my_motif_logo = entropy_vector(profile);

  for (auto &e : my_motif_logo)
    e = (2 - e);

  return my_motif_logo;
}

char integer_to_allele(unsigned int i)
{
  char c;
  switch(i) {
  case 0:
    c = 'A';
    break;
  case 1:
    c = 'C';
    break;
  case 2:
    c = 'G';
    break;
  case 3:
    c = 'T';
    break;
  }
  return c;
}

template <typename T>
unsigned int my_max(vector<T> v)
{
  double max;
  double d;

  max = v[0];
  for (unsigned int i = 0; i < v.size(); ++i) {
    d = v[i];
    if (d > max) {
      max = d;
    }
  }
  return max;
}

unsigned int locate_max(vector<double> v)
{
  unsigned int index;
  double max;
  double d;

  for (unsigned int i = 0; i < v.size(); ++i) {
    max = v[0];
    d = v[i];
    if (d > max) {
      max = d;
      index = i;
    }
  }
  return index;
}

vector<unsigned int> count_alleles(string seq)
{
  vector<unsigned int> count {0, 0, 0, 0};
  for (auto allele : seq)
    switch(allele) {
    case 'A':
      ++count[0];
      break;
    case 'C':
      ++count[1];
      break;
    case 'G':
      ++count[2];
      break;
    case 'T':
      ++count[3];
      break;
    } // switch
  return count;
}

vector<string> transpose(vector<string> matrix)
{
  unsigned int rows = matrix.size();
  unsigned int columns = matrix[0].size();
  string place_holder("", rows);

  vector<string> t(columns, place_holder);

  for (unsigned int i = 0; i < rows; ++i)
    for (unsigned int j = 0; j < columns; ++j)
      t[j][i] = matrix[i][j];

  return t;
}

vector<vector<unsigned int> > counts(vector<string> motifs)
{
  vector<vector<unsigned int> > my_counts;
  vector<string> motifs_as_columns = transpose(motifs);
  for (auto column : motifs_as_columns) {
    my_counts.push_back(count_alleles(column));
  }
  return my_counts;
}

vector<vector<double> > profile(vector<vector<unsigned int> > counts)
{
  unsigned int d = 0;
  for (auto &i : counts[0])
    d += i;

  vector<vector<double> > my_profile;
  vector<double> p(4);
  for (auto &collection : counts) {
    for (unsigned int i = 0; i < 4; ++i) {
      ++collection[i];
      p[i] = (double)collection[i]/(d+4);
    }
    my_profile.push_back(p);
  }

  return my_profile;
}

vector<vector<double> > profile(vector<string> motifs)
{
  return profile(counts(motifs));
}


string consensus(vector<vector<double> > profile)
{
  string consensus;
  for (auto &elem : profile)
    consensus += integer_to_allele(locate_max(elem));
  return consensus;
}

unsigned int score(vector<string> motifs)
{
  unsigned int d = motifs.size();
  unsigned int my_score = 0;
  vector<vector<unsigned int> > my_counts = counts(motifs);
  for (auto &v: my_counts)
    my_score += (d - my_max<unsigned int>(v));
  return my_score;
}

// int main()
// {
//   vector<vector<double> > my_profile;
//   vector<vector<int> > my_counts;
//   string my_consensus;
//   unsigned int my_score;
//   double my_entropy;
//   vector<double> my_motif_logo;
//
//   vector<string> motifs = { "TCGGGGGTTTTT",
//                             "CCGGTGACTTAC",
//                             "ACGGGGATTTTC",
//                             "TTGGGGACTTTT",
//                             "AAGGGGACTTCC",
//                             "TTGGGGACTTCC",
//                             "TCGGGGATTCAT",
//                             "TCGGGGATTCCT",
//                             "TAGGGGAACTAC",
//                             "TCGGGTATAACC" };
//
//   my_counts = counts(motifs);
//   my_profile = profile(my_counts);
//   my_consensus = consensus(my_profile);
//   my_score = score(motifs);
//   my_entropy = entropy(my_profile);
//   my_motif_logo = motif_logo(my_profile);
//
//   return 0;
// }
