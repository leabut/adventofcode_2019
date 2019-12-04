//============================================================================
// Name        : Day03.cpp
// Author      : leabut
// Version     :
// Copyright   : None
// Description : Day03 of AoC Challange 2019
//============================================================================

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <thread>
#include <utility>

using namespace std;

#define DEBUG

constexpr int arrSize = 20;  // 44000

std::array<std::array<char, arrSize>, arrSize> arr;

std::vector<std::string> commandsOne;
std::vector<std::string> commandsTwo;

void updatePos(std::pair<int, int> oldPos, std::pair<int, int> newPos) {
  if (oldPos.first > newPos.first) {
    for (auto i = oldPos.first - 1; i >= newPos.first; i--) {
      if (arr.at(i).at(oldPos.second) == '#') {
        arr.at(i).at(oldPos.second) = '-';
      } else {
        arr.at(i).at(oldPos.second) = 'X';
      }
    }
  }

  if (oldPos.first < newPos.first) {
    for (auto i = oldPos.first + 1; i <= newPos.first; i++) {
      if (arr.at(i).at(oldPos.second) == '#') {
        arr.at(i).at(oldPos.second) = '-';
      } else {
        arr.at(i).at(oldPos.second) = 'X';
      }
    }
  }

  if (oldPos.second > newPos.second) {
    for (auto i = oldPos.second - 1; i >= newPos.second; i--) {
      if (arr.at(oldPos.first).at(i) == '#') {
        arr.at(oldPos.first).at(i) = '-';
      } else {
        arr.at(oldPos.first).at(i) = 'X';
      }
    }
  }

  if (oldPos.second < newPos.second) {
    for (auto i = oldPos.second + 1; i <= newPos.second; i++) {
      if (arr.at(oldPos.first).at(i) == '#') {
        arr.at(oldPos.first).at(i) = '-';
      } else {
        arr.at(oldPos.first).at(i) = 'X';
      }
    }
  }
}

int findShortestX() {
  std::pair<int, int> minDistPoint = {0, 0};
  int dist = INT_MAX;
  for (int i = 0u; i < arr.size(); i++) {
    for (int k = 0u; k < arr.at(i).size(); k++) {
      if (arr.at(i).at(k) == 'X') {
        if ((std::abs(i - (arrSize / 2)) + std::abs(k - (arrSize / 2))) < dist) {
          dist = std::abs(i - (arrSize / 2)) + std::abs(k - (arrSize / 2));
          minDistPoint.first = i;
          minDistPoint.second = k;
        }
      }
    }
  }

  return dist;
}

int main() {
  std::ifstream file("input.txt");
  std::string line;

  for (auto i = 0u; i < arr.size(); i++) {
    for (auto k = 0u; k < arr.at(i).size(); k++) {
      arr.at(i).at(k) = '#';
    }
  }
  arr.at(arrSize / 2).at(arrSize / 2) = 'o';

  if (!std::getline(file, line)) {
    return 0;
  }

  std::string tmp = "";
  for (auto i = 0u; i < line.size(); i++) {
    if (line.at(i) != ',') {
      tmp += line.at(i);
    } else {
      commandsOne.push_back(tmp);
      tmp = "";
    }
  }
  commandsOne.push_back(tmp);
  tmp = "";

  if (!std::getline(file, line)) {
    return 0;
  }

  for (auto i = 0u; i < line.size(); i++) {
    if (line.at(i) != ',') {
      tmp += line.at(i);
    } else {
      commandsTwo.push_back(tmp);
      tmp = "";
    }
  }
  commandsTwo.push_back(tmp);
  tmp = "";

  std::pair<int, int> oldPos = {arrSize / 2, arrSize / 2};
  for (auto i = 0u; i < commandsOne.size(); i++) {
    int steps = stoi(commandsOne.at(i).substr(1, commandsOne.at(i).size() - 1));
    std::pair<int, int> newPos = {0, 0};
    switch (commandsOne.at(i).at(0)) {
      case 'U':
        newPos.second = oldPos.second + steps;
        newPos.first = oldPos.first;
        break;
      case 'D':
        newPos.second = oldPos.second - steps;
        newPos.first = oldPos.first;
        break;
      case 'L':
        newPos.first = oldPos.first - steps;
        newPos.second = oldPos.second;
        break;
      case 'R':
        newPos.first = oldPos.first + steps;
        newPos.second = oldPos.second;
        break;
    }
    updatePos(oldPos, newPos);
    oldPos = newPos;
  }

  oldPos = {arrSize / 2, arrSize / 2};
  for (auto i = 0u; i < commandsTwo.size(); i++) {
    int steps = stoi(commandsTwo.at(i).substr(1, commandsTwo.at(i).size() - 1));
    std::pair<int, int> newPos = {0, 0};
    switch (commandsTwo.at(i).at(0)) {
      case 'U':
        newPos.second = oldPos.second + steps;
        newPos.first = oldPos.first;
        break;
      case 'D':
        newPos.second = oldPos.second - steps;
        newPos.first = oldPos.first;
        break;
      case 'L':
        newPos.first = oldPos.first - steps;
        newPos.second = oldPos.second;
        break;
      case 'R':
        newPos.first = oldPos.first + steps;
        newPos.second = oldPos.second;
        break;
    }
    updatePos(oldPos, newPos);
    oldPos = newPos;
  }

#ifdef DEBUG
  for (auto i = arr.size() - 1; i > 0; i--) {
    for (auto k = 0u; k < arr.at(i).size(); k++) {
      printf("%c", arr.at(k).at(i));
    }
    printf("\n");
  }
#endif

  printf("Result PartOne: %d\n", findShortestX());

  return 0;
}
