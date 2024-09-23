#ifndef DIALOG_H
#define DIALOG_H

#include "../properties/properties.h"
#include <string>

namespace dialog {

int dialog_exit(prop::Properties&);
int dialog_properties_to_str(prop::Properties&);
int dialog_properties_to_str_cstr(prop::Properties&);
int dialog_properties_to_str_array(prop::Properties&);
int dialog_str_to_properties(prop::Properties&);
int get_command();
int dialog(const std::string[], const int);
int process(prop::Properties&);
int dialog_str_to_properties_cstring(prop::Properties&);
int dialog_str_to_properties_array(prop::Properties&);

};

#endif
