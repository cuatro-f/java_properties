#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <string>
#include <vector>

/**
 * @brief Properties namespace
*/
namespace prop {

/**
 * @brief A structure representing properties of an entity.
 * 
 * This structure contains three fields: name, group, and grade.
 */
struct Properties {
  std::string name;   ///< The name of the entity.
  std::string group;  ///< The group to which the entity belongs.
  double grade;       ///< The grade of the entity.
};

/**
 * @brief Converts properties to a string in the format "name.property=value".
 *
 * This function takes a Properties object and converts its fields into a formatted string.
 *
 * @param properties The properties to convert.
 * @param name The name to prepend to each property in the output string.
 * @return A string representing the properties in the format "name.property=value".
 * @throw std::runtime_error If a memory allocation error occurs.
 */
std::string properties_to_str(const Properties& properties, const std::string& name);

/**
 * @brief Converts properties to a string in format "name.property=value".
 *
 * This function takes a Properties object and converts its field into a formatted string.
 *
 * @param properties The properties to convert.
 * @param name The name (C-string) to prepend to each property in the output string.
 * @return A string representing the properties in the format "name.property=value".
 * @throw std::runtime_error If a memory allocation error occurs.
 */
std::string properties_to_str(const Properties &properties, char *name);

/**
 * @brief Converts properties to a string in format "name.property=value".
 *
 * This function takes a Properties object and converts its field into a formatted string.
 *
 * @param properties The properties to convert.
 * @param name The name (array of char) to prepend to each property in the output string.
 * @param len The length of name.
 * @return A string representing the properties in the format "name.property=value".
 * @throw std::runtime_error If a memory allocation error occurs.

*/
std::string properties_to_str(const Properties &properties_to_str, char *name, size_t len);

/**
 * @brief Converts a string to properties.
 *
 * This function parses a formatted string and fills the provided properties object with values.
 * 
 * @param str The string representing the properties.
 * @param properties Variable to store the properties.
 * @return true If the conversion was successful.
 * @return false If the string format does not match the properties.
 */
bool str_to_properties(const std::string& str, Properties& properties);

/**
 * @brief Converts a C-style string to properties.
 *
 * This function takes a C-style string and converts its representation into properties.
 * 
 * @param str The C-style string.
 * @param properties Variable to store the properties.
 * @return true If the conversion was successful.
 * @return false If the string format does not match the properties.
 * @throw std::runtime_error If the pointer is null.
 */
bool str_to_properties(const char* str, Properties& properties);

/**
 * @brief Converts a portion of a string to properties with a specified length.
 *
 * This function allows specifying the length of the C-style string to consider for conversion.
 * 
 * @param str The C-style string.
 * @param len The length of the portion of the string.
 * @param properties Variable to store the properties.
 * @return true If the conversion was successful.
 * @return false If the string format does not match the properties.
 * @throw std::runtime_error If the pointer is null.
 */
bool str_to_properties(const char* str, size_t len, Properties& properties);

/**
 * @brief Prints the properties to standard output.
 *
 * This function outputs the properties contained in a Properties object to
 * the console in a readable format.
 * 
 * @param properties The properties to print.
 */
void print_properties(const Properties& properties);

/**
 * @brief Checks if a string represents properties in the correct format.
 *
 * This function verifies if the input string conforms to the expected format 
 * for properties.
 * 
 * @param str The string to check.
 * @return true If the string is a valid set of properties.
 * @return false If the string does not match the properties format.
 */
bool is_properties(const std::string& str);

/**
 * @brief Splits a string into tokens using the specified delimiter.
 *
 * This function breaks the input string apart based on the provided delimiter
 * and returns a vector of the resulting substrings.
 * 
 * @param str The string to split.
 * @param delimiter The delimiter to use for tokenization.
 * @return A vector of strings containing the tokens.
 * @throw std::runtime_error If a memory allocation error occurs.
 */
std::vector<std::string> split(const std::string& str, const std::string& delimiter);

} // namespace prop

#endif // !PROPERTIES_H
