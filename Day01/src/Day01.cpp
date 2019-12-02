//============================================================================
// Name        : Day01.cpp
// Author      : leabut
// Version     :
// Copyright   : None
// Description : Day01 of AoC Challange 2019
//============================================================================

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
  std::ifstream file("input.txt");
  std::string line;

  int sum = 0;

  while (std::getline(file, line)) {
    int lineInt = stoi(line, nullptr, 10);
    lineInt /= 3;
    lineInt = std::floor(lineInt);
    lineInt -= 2;
    sum += lineInt;
  }

  printf("Output PartOne: %d\n", sum);

  file.clear();
  file.seekg(0, ios::beg);

  sum = 0;
  while (std::getline(file, line)) {
    int lineInt = stoi(line, nullptr, 10);
    lineInt /= 3;
    lineInt = std::floor(lineInt);
    lineInt -= 2;
    sum += lineInt;
    while (lineInt > 0) {
      lineInt /= 3;
      lineInt = std::floor(lineInt);
      lineInt -= 2;
      if (lineInt > 0) {
        sum += lineInt;
      }
    }
  }

  printf("Output PartTwo: %d\n", sum);
  return 0;
}
