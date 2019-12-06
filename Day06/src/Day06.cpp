//============================================================================
// Name        : Day06.cpp
// Author      : leabut
// Version     :
// Copyright   : None
// Description : Day06 of AoC Challange 2019
//============================================================================

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <limits>

using namespace std;

struct Node {
  Node* parent = nullptr;
  std::vector<Node*> childs;
  std::string name = "";
};

int main() {
  std::ifstream file("input.txt");
  std::string line;
  std::vector<Node*> vec;

  while (std::getline(file, line)) {
    std::size_t splitPos = line.find(')');

    std::string subStr = line.substr(0u, splitPos);
    std::string subStr2 = line.substr(splitPos + 1u, line.size() - splitPos);

    if (vec.size() == 0u) {
      Node* childNode = new Node();
      childNode->name = subStr2;

      Node* parentNode = new Node();
      childNode->parent = parentNode;

      parentNode->name = subStr;
      parentNode->parent = nullptr;
      parentNode->childs.push_back(childNode);

      vec.push_back(parentNode);
      vec.push_back(childNode);
      continue;
    }

    bool foundParent = false;
    Node* childNode = new Node();
    childNode->name = subStr2;
    for (auto itNode : vec) {
      if (itNode->name == subStr) {
        childNode->parent = itNode;
        itNode->childs.push_back(childNode);
        foundParent = true;
        break;
      }
    }

    if (foundParent == false) {
      Node* parentNode = new Node();
      childNode->parent = parentNode;
      parentNode->name = subStr;
      parentNode->childs.push_back(childNode);
      vec.push_back(parentNode);
    }

    vec.push_back(childNode);
  }

  int sum = 0u;

  for (auto itNode : vec) {
    int count = 0;
    Node* tmp = itNode;
    while (tmp->parent != nullptr) {
      tmp = tmp->parent;
      count++;
    }
    sum += count;
  }

  printf("Sum %d \n", sum);

  return 0;
}
