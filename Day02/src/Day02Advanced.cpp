//============================================================================
// Name        : Day02Advanced.cpp
// Author      : leabut
// Version     :
// Copyright   : None
// Description : Day02 of AoC Challange 2019
//             : Over engineered edition with multi threading
//============================================================================

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <thread>

using namespace std;

std::vector<int> vec{};
int i = 0;
int k = 0;

void simulate(void) {
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

  if (vec[0] == 19690720) {
    printf("Output PartTwo: i = %d, k = %d, 100 * i + k = %d\n", i, k, 100 * i + k);
  }
}

std::vector<int> vec2{};
int i2 = 0;
int k2 = 0;

void simulate2(void) {
  int programCounter = 0;
  while (vec2[programCounter] != 99) {
    switch (vec2[programCounter]) {
      case 1:
        vec2[vec2[programCounter + 3]] = vec2[vec2[programCounter + 1]] + vec2[vec2[programCounter + 2]];
        break;
      case 2:
        vec2[vec2[programCounter + 3]] = vec2[vec2[programCounter + 1]] * vec2[vec2[programCounter + 2]];
        break;
      default:
        // do nothing
        break;
    }
    programCounter += 4;
  }

  if (vec2[0] == 19690720) {
    printf("Output PartTwo: i = %d, k = %d, 100 * i + k = %d\n", i2, k2, 100 * i2 + k2);
  }
}

std::vector<int> vec3{};
int i3 = 0;
int k3 = 0;

void simulate3(void) {
  int programCounter = 0;
  while (vec3[programCounter] != 99) {
    switch (vec3[programCounter]) {
      case 1:
        vec3[vec3[programCounter + 3]] = vec3[vec3[programCounter + 1]] + vec3[vec3[programCounter + 2]];
        break;
      case 2:
        vec3[vec3[programCounter + 3]] = vec3[vec3[programCounter + 1]] * vec3[vec3[programCounter + 2]];
        break;
      default:
        // do nothing
        break;
    }
    programCounter += 4;
  }

  if (vec3[0] == 19690720) {
    printf("Output PartTwo: i = %d, k = %d, 100 * i + k = %d\n", i3, k3, 100 * i3 + k3);
  }
}

std::vector<int> vec4{};
int i4 = 0;
int k4 = 0;

void simulate4(void) {
  int programCounter = 0;
  while (vec4[programCounter] != 99) {
    switch (vec4[programCounter]) {
      case 1:
        vec4[vec4[programCounter + 3]] = vec4[vec4[programCounter + 1]] + vec4[vec4[programCounter + 2]];
        break;
      case 2:
        vec4[vec4[programCounter + 3]] = vec4[vec4[programCounter + 1]] * vec4[vec4[programCounter + 2]];
        break;
      default:
        // do nothing
        break;
    }
    programCounter += 4;
  }

  if (vec4[0] == 19690720) {
    printf("Output PartTwo: i = %d, k = %d, 100 * i + k = %d\n", i4, k4, 100 * i4 + k4);
  }
}

int main() {
  std::ifstream file("input.txt");
  std::string line;
  std::vector<int> _vec;
  std::vector<int> vecCopy;

  if (!std::getline(file, line)) {
    return 0;
  }

  std::size_t splitPos = line.find(',');
  std::size_t oldSplitPos = 0;
  while (splitPos != std::string::npos) {
    std::string subStr = line.substr(oldSplitPos, splitPos - oldSplitPos);
    _vec.push_back(stoi(subStr));
    oldSplitPos = splitPos + 1;
    splitPos = line.find(',', oldSplitPos);
    if (splitPos == std::string::npos) {
      subStr = line.substr(oldSplitPos, line.size());
      _vec.push_back(stoi(subStr));
    }
  }

  vecCopy = _vec;

  int programCounter = 0;
  while (_vec[programCounter] != 99) {
    switch (_vec[programCounter]) {
      case 1:
        _vec[_vec[programCounter + 3]] = _vec[_vec[programCounter + 1]] + _vec[_vec[programCounter + 2]];
        break;
      case 2:
        _vec[_vec[programCounter + 3]] = _vec[_vec[programCounter + 1]] * _vec[_vec[programCounter + 2]];
        break;
      default:
        // do nothing
        break;
    }
    programCounter += 4;
  }

  printf("Output PartOne: %d\n", _vec[0]);

  vec = vecCopy;
  vec2 = vec;
  vec3 = vec;
  vec4 = vec;

  for (int _i = 0; _i < 100; _i += 4) {
    for (int _k = 0; _k < 100; _k += 4) {
      vec[1] = _i;
      vec[2] = _k;
      i = _i;
      k = _k;
      vec2[1] = _i + 1;
      vec2[2] = _k + 1;
      i2 = _i + 1;
      k2 = _k + 1;
      vec3[1] = _i + 2;
      vec3[2] = _k + 2;
      i3 = _i + 2;
      k3 = _i + 2;
      vec4[1] = _i + 3;
      vec4[2] = _k + 3;
      i4 = _i + 3;
      k4 = _k + 3;
      std::thread t1(simulate);
      std::thread t2(simulate2);
      std::thread t3(simulate3);
      std::thread t4(simulate4);

      t1.join();
      t2.join();
      t3.join();
      t4.join();

      vec = vecCopy;
      vec2 = vec;
      vec3 = vec;
      vec4 = vec;
    }
  }

  return 0;
}

