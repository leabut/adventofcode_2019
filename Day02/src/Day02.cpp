//============================================================================
// Name        : Day02.cpp
// Author      : leabut
// Version     :
// Copyright   : None
// Description : Day02 of AoC Challange 2019
//============================================================================

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

int simulate(std::vector<int> vec) {
  int programCounter = 0;
  while (vec[programCounter] != 99) {
    switch (vec[programCounter]) {
      case 1:
        vec[vec[programCounter + 3]] = vec[vec[programCounter + 1]] + vec[vec[programCounter + 2]];
        break;
      case 2:
        vec[vec[programCounter + 3]] = vec[vec[programCounter + 1]] * vec[vec[programCounter + 2]];
        break;
      default:
        // do nothing
        break;
    }
    programCounter += 4;
  }

  return vec[0];
}

int main() {
  std::ifstream file("input.txt");
  std::string line;
  std::vector<int> vec;
  std::vector<int> vecCopy;

  if (!std::getline(file, line)) {
    return 0;
  }

  std::size_t splitPos = line.find(',');
  std::size_t oldSplitPos = 0;
  while (splitPos != std::string::npos) {
    std::string subStr = line.substr(oldSplitPos, splitPos - oldSplitPos);
    vec.push_back(stoi(subStr));
    oldSplitPos = splitPos + 1;
    splitPos = line.find(',', oldSplitPos);
    if (splitPos == std::string::npos) {
      subStr = line.substr(oldSplitPos, line.size());
      vec.push_back(stoi(subStr));
    }
  }

  vecCopy = vec;

  int programCounter = 0;
  while (vec[programCounter] != 99) {
    switch (vec[programCounter]) {
      case 1:
        vec[vec[programCounter + 3]] = vec[vec[programCounter + 1]] + vec[vec[programCounter + 2]];
        break;
      case 2:
        vec[vec[programCounter + 3]] = vec[vec[programCounter + 1]] * vec[vec[programCounter + 2]];
        break;
      default:
        // do nothing
        break;
    }
    programCounter += 4;
  }

  printf("Output PartOne: %d\n", vec[0]);

  vec = vecCopy;

  for (int i = 0; i < 100; i++) {
    for (int k = 0; k < 100; k++) {
      vecCopy[1] = i;
      vecCopy[2] = k;
      if (simulate(vecCopy) == 19690720) {
        printf("Output PartTwo: i = %d, k = %d, 100 * i + k = %d\n", i, k, 100 * i + k);
      }
      vecCopy = vec;
    }
  }

  return 0;
}
