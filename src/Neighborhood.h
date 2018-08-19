#ifndef NEIGHBORS_H
#define NEIGHBORS_H

#include<set>
#include<iostream>
#include<string>

std::string tail(const std::string& pattern);

std::string head(const std::string& pattern);

std::set<std::string> neighbors(const std::string& pattern, unsigned int d);

#endif // NEIGHBORS_H
