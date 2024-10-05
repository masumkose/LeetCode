#ifndef INCLUDE_HPP
#define INCLUDE_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <tuple>
#include <stack>
#include <cmath>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#include "structs.hpp"

//ListNode
void printList(ListNode *head);
void addNodeToBack(ListNode *&head, int value);
void clearList(ListNode *&head);
ListNode *getEnd(ListNode *head);


template <typename Container>
void print_container(const Container &container);

template <typename Container>
void print_nested_container(const Container &container);


#include "include.tpp"

#endif