//============================================================================
// Name        : Day09.cpp
// Author      : leabut
// Version     :
// Copyright   : None
// Description : Day09 of AoC Challange 2019
//============================================================================

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <limits>
#include <array>

using namespace std;

int main() {
  std::ifstream file("input.txt");
  std::string line;
  std::array<long long, 50000u> vec = {0u};

  if (!std::getline(file, line)) {
    return 0;
  }

  std::size_t splitPos = line.find(',');
  std::size_t oldSplitPos = 0u;

  std::size_t i = 0u;
  while (splitPos != std::string::npos) {
    std::string subStr = line.substr(oldSplitPos, splitPos - oldSplitPos);
    vec[i] = stoll(subStr);
    oldSplitPos = splitPos + 1;
    splitPos = line.find(',', oldSplitPos);
    i++;
    if (splitPos == std::string::npos) {
      subStr = line.substr(oldSplitPos, line.size());
      vec[i] = stoll(subStr);
    }
  }

  long long inputParam = 1;
  long long paramOut = 0u;
  long long base = 0u;
  long long programCounter = 0u;
  while (vec[programCounter] != 99) {
    long long opcode = vec[programCounter] % 100;
    long long modeParam1 = (vec[programCounter] / 100) % 10;
    long long modeParam2 = (vec[programCounter] / 1000) % 10;
    long long modeParam3 = (vec[programCounter] / 10000) % 10;

    long long param1 = 0u;
    long long param2 = 0u;
    //long long param3 = 0u;

    if (modeParam1 == 0) {
      param1 = vec[vec[programCounter + 1]];
    } else if (modeParam1 == 1) {
      param1 = vec[programCounter + 1];
    } else if (modeParam1 == 2) {
      param1 = vec[vec[programCounter + 1] + base];
    }

    if (opcode != 3 && opcode != 4) {
      if (modeParam2 == 0) {
        param2 = vec[vec[programCounter + 2]];
      } else if (modeParam2 == 1) {
        param2 = vec[programCounter + 2];
      } else if (modeParam2 == 2) {
        param2 = vec[vec[programCounter + 2] + base];
      }
    }

    /*
    if (modeParam3 == 0) {
      param3 = vec[vec[programCounter + 3]];
    } else if (modeParam3 == 1) {
      param3 = vec[programCounter + 3];
    } else if (modeParam3 == 2) {
      param3 = vec[vec[programCounter + 3] + base];
    }
    */

    switch (opcode) {
      case 1:
        if (modeParam3 == 0) {
          vec[vec[programCounter + 3]] = param1 + param2;
        } else if (modeParam3 == 2) {
          vec[vec[programCounter + 3] + base] = param1 + param2;
        }
        programCounter += 4;
        break;
      case 2:
        if (modeParam3 == 0) {
          vec[vec[programCounter + 3]] = param1 * param2;
        } else if (modeParam3 == 2) {
          vec[vec[programCounter + 3] + base] = param1 * param2;
        }
        programCounter += 4;
        break;
      case 3:
        if (modeParam1 == 0) {
          vec[vec[programCounter + 1]] = inputParam;
        } else if (modeParam1 == 2) {
          vec[vec[programCounter + 1] + base] = inputParam;
        }
        programCounter += 2;
        break;
      case 4:
        printf("%llu\n", param1);
        programCounter += 2;
        paramOut = param1;
        break;
      case 5:
        if (param1 != 0) {
          programCounter = param2;
        } else {
          programCounter += 3;
        }
        break;
      case 6:
        if (param1 == 0) {
          programCounter = param2;
        } else {
          programCounter += 3;
        }
        break;
      case 7:
        if (param1 < param2) {
          if (modeParam3 == 0) {
            vec[vec[programCounter + 3]] = 1;
          } else if (modeParam3 == 2) {
            vec[vec[programCounter + 3] + base] = 1;
          }
        } else {
          if (modeParam3 == 0) {
            vec[vec[programCounter + 3]] = 0;
          } else if (modeParam3 == 2) {
            vec[vec[programCounter + 3] + base] = 0;
          }
        }
        programCounter += 4;
        break;
      case 8:
        if (param1 == param2) {
          if (modeParam3 == 0) {
            vec[vec[programCounter + 3]] = 1;
          } else if (modeParam3 == 2) {
            vec[vec[programCounter + 3] + base] = 1;
          }
        } else {
          if (modeParam3 == 0) {
            vec[vec[programCounter + 3]] = 0;
          } else if (modeParam3 == 2) {
            vec[vec[programCounter + 3] + base] = 0;
          }
        }
        programCounter += 4;
        break;
      case 9:
        base += param1;
        programCounter += 2;
        break;
      default:
        // do nothing
        break;
    }
  }

  printf("Result PartOne: %llu\n", paramOut);

  return 0;
}
