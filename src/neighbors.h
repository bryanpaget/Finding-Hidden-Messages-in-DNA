#ifndef NEIGHBORS_H
#define NEIGHBORS_H

#include<vector>
#include<iostream>
#include<string>

unsigned int hamming_distance(const std::string &pattern1, const std::string &pattern2);

std::string tail(const std::string& pattern);

std::string head(const std::string& pattern);

std::vector<std::string> neighbors(const std::string& pattern, unsigned int d);

#endif // NEIGHBORS_H
