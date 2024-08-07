#ifndef INCLUDE_HPP
#define INCLUDE_HPP


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <cmath>
#include <stdio.h>
using namespace std;


template <typename Container>
void print_container(const Container &container);

template <typename Container>
void print_nested_container(const Container &container);

#include "include.tpp"

#endif