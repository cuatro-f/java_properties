#define CATCH_CONFIG_MAIN
#include "../property/properties/properties.h"
#include <catch2/catch.hpp>
#include <string>

TEST_CASE("STR_TO_PROPERTIES (FOR STD::STRING)") {
  prop::Properties *properties_ptr = new prop::Properties;
  prop::Properties pr = *properties_ptr;
  pr.name = "sasha";
  pr.group = "B23-595";
  pr.grade = 4.5;
  REQUIRE(prop::str_to_properties("{name=\"Alex\", group=\"B23-405\", grade=4.5}", pr) == true);
  REQUIRE(prop::str_to_properties("{name=Alex, group=\"B23-405\", grade=4.5}", pr) == false);
  REQUIRE(prop::str_to_properties("{name=\"Alex\", group=\"K23-405\", grade=4.5}", pr) == false);
  delete properties_ptr;
}

TEST_CASE("IS_PROPERTIES") {
  prop::Properties *properties_ptr = new prop::Properties;
  prop::Properties pr = *properties_ptr;
  pr.name = "sasha";
  pr.group = "B23-595";
  pr.grade = 4.5;
  REQUIRE(prop::is_properties("{grade=3.5, name=\"Max\", group=\"S23-412\"}") == true);
  REQUIRE(prop::is_properties("{grade=4.5, name=\"Sasha\", group=\"B23-505\"") == false);
  REQUIRE(prop::is_properties("grade=4.5, name=\"Sasha\", group=\"B23-505\"}") == false);
  REQUIRE(prop::is_properties("{name=\"Surname\", grade=4.5, group=\"B23-595\", what is it}") == false);
  delete properties_ptr;
}

TEST_CASE("PROPERTIES_TO_STR") {
  prop::Properties *properties_ptr = new prop::Properties;
  prop::Properties pr = *properties_ptr;
  pr.name = "sasha";
  pr.group = "B23-595";
  pr.grade = 4.5;
  std::string name = "student";
  std::string result = name + ".name=" + pr.name + "\n" + name + ".group=" + pr.group + "\n" + name + ".grade=" + std::to_string(pr.grade) + "\n";
  REQUIRE(prop::properties_to_str(pr, name) == result);
  REQUIRE(prop::properties_to_str(pr, "") == "");
  delete properties_ptr;
}

TEST_CASE("STR_TO_PROPERTIES (FOR CSTRING)") {
  prop::Properties *properties_ptr = new prop::Properties;
  prop::Properties pr = *properties_ptr;
  pr.name = "sasha";
  pr.group = "B23-595";
  pr.grade = 4.5;
  char str[] = "{name=\"Loop\", group=\"B23-505\", grade=4.2}\0";
  char str1[] = "{name=\"Surname\", grade=4.5, group=\"B23-595\", what is it}\0";
  char str2[] = "grade=4.5, name=\"Sasha\", group=\"B23-505\"}\0";
  REQUIRE(prop::str_to_properties(str, pr) == true);
  REQUIRE(prop::str_to_properties(str1, pr) == false);
  REQUIRE(prop::str_to_properties(str2, pr) == false);
  REQUIRE_THROWS_AS(prop::str_to_properties(nullptr, pr), std::runtime_error);
  delete properties_ptr;
}

TEST_CASE("STR_TO_PROPERTIES (FOR CHAR ARRAY WITH LENGTH)") {
  prop::Properties *properties_ptr = new prop::Properties;
  prop::Properties pr = *properties_ptr;
  pr.name = "sasha";
  pr.group = "B23-595";
  pr.grade = 4.5;
  char str[] = "{name=\"Loop\", group=\"B23-505\", grade=4.2}";
  char str1[] = "{name=\"Surname\", grade=4.5, group=\"B23-595\", what is it}";
  char str2[] = "grade=4.5, name=\"Sasha\", group=\"B23-505\"}";
  REQUIRE(prop::str_to_properties(str, 41, pr) == true);
  REQUIRE(prop::str_to_properties(str1, 55, pr) == false);
  REQUIRE(prop::str_to_properties(str2, 41, pr) == false);
  REQUIRE_THROWS_AS(prop::str_to_properties(nullptr, 0, pr), std::runtime_error);
  delete properties_ptr;
}

TEST_CASE("PRINT PROPERTIES") {
  prop::Properties *properties_ptr = new prop::Properties;
  prop::Properties pr = *properties_ptr;
  pr.name = "sasha";
  pr.group = "B23-595";
  pr.grade = 4.5;
  REQUIRE(prop::print_properties);
  delete properties_ptr;
}

