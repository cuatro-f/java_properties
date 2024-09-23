#include <iostream>
#include <limits>
#include <stdexcept>

#include "../properties/properties.h"
#include "dialog.h"
#include "../input/input.h"

namespace dialog {

int get_command() {
  int a;
  do {
    std::cin >> a;
    if (!std::cin.good())
      throw std::runtime_error("Failed to read number");
    else if (std::cin.eof())
      throw std::runtime_error("Failed to read number: EOF");
    else if (std::cin.fail() || a > 6 || a < 0) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Wrong number, repeat" << std::endl; 
    }
    else
      return a;
  } while(true);
  return 0;
}

int dialog(const std::string msgs[], const int len) {
  std::string errmsg = "";
  int number = 0;
  do {
    std::cout << errmsg;
    errmsg = "Repeat input";
    for (int i = 0; i < len; i++) {
      std::cout << msgs[i] << std::endl;
    }
    number = get_command();
  } while(number < 0 || number >= len);
  return number;
}

int process(prop::Properties& properties) {
  const std::string msgs[] = {"0. Quit", "1. String to properties",
  "2. Properties to string", "3. String to properties cstring",
  "4. String to properties array", "5. Properties to string cstring",
  "6. Properties to string array"};
  const int len = sizeof(msgs) / sizeof(msgs[0]);
  int check = 0;
  int flag = 1;
  int (*funcs[]) (prop::Properties&) = {&dialog_exit, &dialog_str_to_properties,
  &dialog_properties_to_str, &dialog_str_to_properties_cstring, &dialog_str_to_properties_array,
  &dialog_properties_to_str_cstr, &dialog_properties_to_str_array};
  while (flag) {
    int index = dialog(msgs, len);
    check = funcs[index](properties);
    if (check == -1) {
      flag = 0;
      return EOF;
    }
  }
  return 0;
}

int dialog_exit(prop::Properties& properties) {
  return -1;
}

int dialog_properties_to_str(prop::Properties& properties) {
  std::cout << "Enter structure name: " << std::endl;
  std::string name = input::input();
  std::string prop_string = properties_to_str(properties, name);
  if (prop_string == "")
    std::cout << "Bad string" << std::endl;
  else
    std::cout << prop_string << std::endl;
  return 0;
}

int dialog_str_to_properties(prop::Properties& properties) {
  std::cout << "Enter properties string: " << std::endl;
  std::string prop_string = input::input();
  bool check = prop::str_to_properties(prop_string, properties);
  if (check) {
    prop::print_properties(properties);
  }
  else {
    std::cout << "Your string is bad" << std::endl;
  }
  return 0;
}

int dialog_str_to_properties_cstring(prop::Properties& properties) {
  std::cout << "Enter string: " << std::endl;
  std::string str = input::input();
  const char *cstr = str.c_str();
  bool check = prop::str_to_properties(cstr, properties);
  if (check)
    prop::print_properties(properties);
  else
    std::cout << "Your string is bad" << std::endl;
  return 0;
}

int dialog_str_to_properties_array(prop::Properties& properties) {
  std::cout << "Enter string: " << std::endl;
  std::string str = input::input();
  char *new_str;
  try {
    new_str = new char[str.length()];
    for (size_t i = 0; i < str.length(); i++) {
      new_str[i] = str[i];
    }
    bool check = prop::str_to_properties(new_str, str.length(), properties);
    if (check)
      prop::print_properties(properties);
    else
      std::cout << "Your string is bad" << std::endl;
  }
  catch (const std::bad_alloc& e) {
    std::cerr << "Memory allocate error. " << e.what() << std::endl;
    throw std::runtime_error("Allocate error");
  }  
  catch (...) {
    delete[] new_str;
    throw std::runtime_error("ERROR");
  }
  delete[] new_str;
  return 0;
}

int dialog_properties_to_str_array(prop::Properties &properties) {
  std::cout << "Enter name: " << std::endl;
  std::string str = input::input();
  char *new_str;
  try {
    new_str = new char[str.length()];
    for (size_t i = 0; i < str.length(); i++) {
      new_str[i] = str[i];
    }
    std::string prop_string = prop::properties_to_str(properties, new_str, str.length());
    if (prop_string == "")
      std::cout << "Bad string" << std::endl;
    else
      std::cout << prop_string << std::endl;
 
  }
  catch (const std::bad_alloc& e) {
    std::cerr << "Memory allocate error. " << e.what() << std::endl;
    throw std::runtime_error("Allocate error");
  }  
  catch (...) {
    delete[] new_str;
    throw std::runtime_error("ERROR");
  }
  delete[] new_str;
  return 0;
}

int dialog_properties_to_str_cstr(prop::Properties& properties) {
  std::cout << "Enter name: " << std::endl;
  std::string name = input::input();
  const char *cname = name.c_str();
  std::string prop_string = prop::properties_to_str(properties, cname);
  if (prop_string == "")
    std::cout << "Bad string" << std::endl;
  else
    std::cout << prop_string << std::endl;
  return 0;
}

}

