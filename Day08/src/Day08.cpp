//============================================================================
// Name        : Day08.cpp
// Author      : leabut
// Version     :
// Copyright   : None
// Description : Day08 of AoC Challange 2019
//============================================================================

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <limits>
#include <array>
#include <cstring>

using namespace std;

int main() {
  std::ifstream file("input.txt");
  std::string line;
  std::vector<std::vector<int>*> layers;

  if (!std::getline(file, line)) {
    return 0;
  }

  std::vector<int>* vec;
  for (auto i = 0u; i < line.size(); i++) {
    if (i % (25 * 6) == 0) {
      vec = new std::vector<int>();
      layers.push_back(vec);
    }
    std::array<char, 2> charArr = {0u};
    charArr[0] = line.at(i);
    vec->push_back(atoi(charArr.data()));
  }

  int min = INT_MAX;
  std::vector<int>* minLayer = nullptr;
  for (auto itLayer : layers) {
    int numZeros = 0u;
    for (auto itVec : *itLayer) {
      if (itVec == 0u) {
        numZeros++;
      }
    }
    if (numZeros < min) {
      min = numZeros;
      minLayer = itLayer;
    }
  }

  int numOnes = 0u;
  int numTwos = 0u;
  for (auto itVec : *minLayer) {
    if (itVec == 1u) {
      numOnes++;
      continue;
    }
    if (itVec == 2u) {
      numTwos++;
    }
  }

  printf("Result PartOne: %d\n", numOnes * numTwos);

  std::array<uint8_t, 25 * 6> output = {0u};
  std::memset(&output, 2u, output.size());

  for (auto itLayer : layers) {
    for (auto i = 0u; i < itLayer->size(); i++) {
      if (itLayer->at(i) == 2u) {
        continue;
      } else if (output[i] == 2u) {
        output[i] = itLayer->at(i);
      }
    }
  }

  for (auto i = 0u; i < output.size(); i++) {
    if (output[i] == 1) {
      printf("#");
    } else {
      printf(" ");
    }
    if (i % 25 == 0u) {
      printf("\n");
    }
  }

  return 0;
}
