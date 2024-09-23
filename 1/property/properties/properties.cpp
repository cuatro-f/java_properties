#include "properties.h"
#include <iostream>
#include <algorithm>
#include <regex>
#include <vector>

namespace prop {

std::string properties_to_str(const Properties& properties, const std::string& name) {
  if (name == "")
    return "";
  std::string prop_string;
  try {
    prop_string = name + ".name=" + properties.name + "\n";
    prop_string += name + ".group=" + properties.group + "\n";
    prop_string += name + ".grade=" + std::to_string(properties.grade) + "\n";
  }
  catch (const std::bad_alloc& e) {
    std::cerr << "Memory allocate error. " << e.what() << std::endl;
    throw std::runtime_error("Allocate error");
  }  
  return prop_string;
}

void print_properties(const Properties& properties) {
  std::cout << "name=" << properties.name << "\n" << "group=" << 
  properties.group << "\n" << "grade=" << properties.grade << std::endl;
}

std::vector<std::string> split(const std::string& str, const std::string& delimiter) {
  std::vector<std::string> tokens;
  std::string token;
  std::size_t start = 0, end = 0;
  while ((end = str.find(delimiter, start)) != std::string::npos) {
    token = str.substr(start, end - start);
    try {
      tokens.push_back(token);
    }
    catch (const std::bad_alloc& e) {
      std::cerr << "Memory allocate error. " << e.what() << std::endl;
      throw std::runtime_error("Allocate error");
    }
    start = end + delimiter.length();
  }

  tokens.push_back(str.substr(start));
  return tokens;
}

bool is_properties(const std::string& str) {
  std::string delimiter = ", ";
  if (str[0] != '{' || str[str.length() - 1] != '}') {
    return false;
  }
  std::string new_str = std::string(str);
  new_str = new_str.substr(1, str.length() - 2);
  std::vector<std::string> tokens = split(new_str, delimiter);
  if (tokens.size() != 3) {
    return false;
    }
  // порядок списка grade group name
  std::sort(tokens.begin(), tokens.end(), [](auto a, auto b){ return a < b; });
  std::regex group_pattern(R"(group=\"[BMS]\d{2}-\d{3}\")");
  std::regex grade_pattern(R"(grade=(?:[0-4](?:\.[0-9]+)?|[0-4]\.[0-9]+|5\.0|5))");
  std::regex name_pattern(R"(name=\"[a-zA-Z]+\")");
  if (!(std::regex_match(tokens[0], grade_pattern) &&
        std::regex_match(tokens[1], group_pattern) &&
        std::regex_match(tokens[2], name_pattern)))
    return false;
  return true;
}

bool str_to_properties(const std::string& str, Properties& properties) {
  if (!is_properties(str))
    return false;
  std::string new_str = std::string(str);
  new_str = new_str.substr(1, str.length() - 2);
  std::string delimiter = ", ";
  std::vector<std::string> tokens = split(new_str, delimiter);
  // порядок в векторе grade, group, name
  std::sort(tokens.begin(), tokens.end(), [](auto a, auto b){ return a < b; });
  properties.name = tokens[2].substr(6, tokens[2].length() - 7);
  properties.group = tokens[1].substr(7, tokens[1].length() - 8);
  properties.grade = std::stod(tokens[0].substr(6, tokens[0].length() - 6));
  return true;
}

bool str_to_properties(const char *str, Properties& properties) {
  if (str == nullptr)
    throw std::runtime_error("NULLPTR");
  std::string new_str(str);
  return str_to_properties(new_str, properties);
}

bool str_to_properties(const char* str, size_t len, Properties& properties) {
  if (str == nullptr)
    throw std::runtime_error("NULLPTR");
  char *new_str;
  try {
    new_str = new char[len + 1];
  }
  catch (const std::bad_alloc& e) {
    std::cerr << "Memory allocate error. " << e.what() << std::endl;
    throw std::runtime_error("Allocate error");
  }  
  bool check = false;
  try {
    new_str[len] = '\0';
    std::copy(str, str + len, new_str);
    std::string new_string(new_str);
    check = str_to_properties(new_string, properties);
  }
  catch (...) {
    delete[] new_str;
    throw std::runtime_error("ERROR");
  }
  delete[] new_str;
  return check;
}

std::string properties_to_str(const Properties& properties, char* name) {
  if (name == nullptr)
    throw std::runtime_error("NULLPTR");
  std::string str_name;
  try {
    str_name = std::string(name);
  }
  catch (const std::bad_alloc& e) {
    std::cerr << "Memory allocate error. " << e.what() << std::endl;
    throw std::runtime_error("Allocate error");
  }
  return properties_to_str(properties, name);
}

std::string properties_to_str(const Properties& properties, char* name, size_t len) {
  if (name == nullptr)
    throw std::runtime_error("NULLPTR");
  char* new_name;
  try {
    new_name = new char[len + 1];
  }
  catch (const std::bad_alloc& e) {
    std::cerr << "Memory allocate error. " << e.what() << std::endl;
    throw std::runtime_error("Allocate error");
  }
  std::string str;
  try {
    new_name[len] = '\0';
    std::copy(name, name + len, new_name);
    std::string new_string(new_name);
    str = properties_to_str(properties, new_string);
  }
  catch (const std::bad_alloc& e) {
    delete[] new_name;
    std::cerr << "Memory allocate error. " << e.what() << std::endl;
    throw std::runtime_error("Allocate error");
  }
  catch (...) {
    delete[] new_name;
    throw std::runtime_error("ERROR");
  }
  delete[] new_name;
  return str;
}

}
