#include "input.h"
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

namespace input {

bool correct_input(std::string& str) {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::getline(std::cin, str);
  if (std::cin.eof())
    throw std::runtime_error("EOF");
  if (std::cin.bad())
    throw std::runtime_error("Broken input");
  if (std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
  }
  return true;
}

std::string input() {
  std::string str;
  while (!correct_input(str));
  return str;
}

};
