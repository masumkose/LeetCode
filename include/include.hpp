#ifndef INCLUDE_HPP
#define INCLUDE_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>
#include <tuple>
#include <stack>
#include <set>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#include "structs.hpp"

//ListNode
void printList(ListNode *head);
void addNodeToBack(ListNode *&head, int value);
void clearList(ListNode *&head);
ListNode *getEnd(ListNode *head);

TreeNode *createTree(const vector<int> &arr, int index);
void printInOrder(TreeNode* root);
void printLevelOrder(TreeNode *root);

vector<string> split(const string &s, char delimiter);

template <typename Container>
void print_container(const Container &container);

template <typename Container>
void print_nested_container(const Container &container);


#include "include.tpp"

#endif