//============================================================================
// Name        : Day04.cpp
// Author      : leabut
// Version     :
// Copyright   : None
// Description : Day04 of AoC Challange 2019
//============================================================================

#include <iostream>
#include <regex>
using namespace std;

constexpr int lower = 372037;
constexpr int upper = 905157;

int main() {
  int count = 0;
  for (auto i = lower; i <= upper; i++) {
    std::string str = std::to_string(i);
    std::smatch sm;
    std::regex reg(".*((0{2})|(1{2})|(2{2})|(3{2})|(4{2})|(5{2})|(6{2})|(7{2})|(8{2})|(9{2})).*");
    //std::regex reg("([1-9]*[0]{2}[1-9]*)|([0,2-9]*[1]{2}[0,2-9]*)|([0-1,3-9]*[2]{2}[0-1,3-9]*)|([0-2,4-9]*[3]{2}[0-2,4-9]*)|([0-3,5-9]*[4]{2}[0-3,5-9]*)|([0-4,6-9]*[5]{2}[0-4,6-9]*)|([0-5,7-9]*[6]{2}[0-5,7-9]*)|([0-6,8-9]*[7]{2}[0-6,8-9]*)|([0-7,9]*[8]{2}[0-7,9]*)|([1-8]*[9]{2}[1-8]*)");

    bool increasing = false;
    for (auto k = 1u; k < str.size(); k++) {
      if (str.at(k - 1) <= str.at(k)) {
        increasing = true;
      } else {
        increasing = false;
        break;
      }
    }

    if (sm.size() != 0 && increasing) {
      count++;
    }
  }

  printf("Result PartOne: %d\n", count);
  //printf("Result PartTwo: %d\n", count);

  cout << "!!!Hello World!!!" << endl;  // prints !!!Hello World!!!
  return 0;
}
