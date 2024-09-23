#include <iostream>
#include <new>
#include "property/dialog/dialog.h"
#include "property/properties/properties.h"

int main() {
  prop::Properties *properties;
  try {
    properties = new prop::Properties;
  }
  catch (const std::bad_alloc& e) {
    std::cerr << "Memory allocate error! " <<  e.what() << std::endl;
    return 1;
  }
  properties->name = "Sasha";
  properties->group = "B23-505";
  properties->grade = 4.0;
  try {
    dialog::process(*properties);
  }
  catch (const std::exception& ex) {
    std::cout << ex.what() << std::endl;
  }
  delete properties;
  return 0;
}
