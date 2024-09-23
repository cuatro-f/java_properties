find_package(Catch2 2 REQUIRED)

add_executable(properties_tests testing.cpp)

target_link_libraries(properties_tests property Catch2::Catch2)

