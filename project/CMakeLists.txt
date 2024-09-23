cmake_minimum_required(VERSION 3.16)

project(first_lab)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(--coverage)
add_link_options(--coverage)

# установка флагов компилятора: CMAKE_CXX_FLAGS += -Wall -Wextra
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_subdirectory(property)

add_subdirectory(tests)

# создание исполняемого файла
# add_executable(main main.cpp)
add_executable(main main.cpp)

target_link_libraries(main property)

# для сборки из консоли:
#
# mkdir build   # создание директории для файлов сборки
# cd build      # переход в директорию сборки
# cmake ..      # генерация файлов сборки на основе CMakeLists.txt
# make          # сборка проекта
