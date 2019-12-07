//============================================================================
// Name        : Day07.cpp
// Author      : leabut
// Version     :
// Copyright   : None
// Description : Day07 of AoC Challange 2019
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

  int max = 0;

  for (int m = 0; m < 10; m++) {
    for (int k = 0; k < 10; k++) {
      for (int j = 0; j < 10; j++) {
        for (int l = 0; l < 10; l++) {
          for (int n = 0; n < 10; n++) {
            std::array<int, 5> paramList = {m, k, j, l, n};
            int paramOut = 0u;
            for (auto i = 0u; i < paramList.size(); i++) {
              bool checkInputArg = false;
              int programCounter = 0;
              while (vec[programCounter] != 99) {
                int opcode = vec[programCounter] % 100;
                int modeParam1 = (vec[programCounter] / 100) % 10;
                int modeParam2 = (vec[programCounter] / 1000) % 10;
                //int modeParam3 = (vec[programCounter] / 10000) % 10;

                int param1 = 0;
                int param2 = 0;

                if (modeParam1 == 0) {
                  param1 = vec[vec[programCounter + 1]];
                } else {
                  param1 = vec[programCounter + 1];
                }

                if (opcode < 3 || opcode > 4) {
                  if (modeParam2 == 0) {
                    param2 = vec[vec[programCounter + 2]];
                  } else {
                    param2 = vec[programCounter + 2];
                  }
                }

                /*
                if (modeParam3 == 0) {
                  param3 = vec[vec[programCounter + 3]];
                } else {
                  param3 = vec[programCounter + 3];
                }
                */

                switch (opcode) {
                  case 1:
                    vec[vec[programCounter + 3]] = param1 + param2;
                    programCounter += 4;
                    break;
                  case 2:
                    vec[vec[programCounter + 3]] = param1 * param2;
                    programCounter += 4;
                    break;
                  case 3:
                    if (checkInputArg == false) {
                      vec[vec[programCounter + 1]] = paramList[i];
                      checkInputArg = true;
                    } else {
                      vec[vec[programCounter + 1]] = paramOut;
                    }
                    programCounter += 2;
                    break;
                  case 4:
                    //printf("%d\n", param1);
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
                      vec[vec[programCounter + 3]] = 1;
                    } else {
                      vec[vec[programCounter + 3]] = 0;
                    }
                    programCounter += 4;
                    break;
                  case 8:
                    if (param1 == param2) {
                      vec[vec[programCounter + 3]] = 1;
                    } else {
                      vec[vec[programCounter + 3]] = 0;
                    }
                    programCounter += 4;
                    break;
                  default:
                    // do nothing
                    break;
                }

                /*
                if (programCounter == 99999) {
                  break;
                }
                */
              }
            }
            //printf("%d\n", paramOut);
            if (paramOut > max) {
              max = paramOut;
            }
          }
        }
      }
    }
  }

  printf("Result PartOne: %d\n", max);

  return 0;
}
