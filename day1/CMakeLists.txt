add_library(input)
target_sources(input PUBLIC FILE_SET CXX_MODULES FILES input.cc)
add_library(part_one)
target_sources(part_one PUBLIC FILE_SET CXX_MODULES FILES part_one.cc)
add_library(part_two)
target_sources(part_two PUBLIC FILE_SET CXX_MODULES FILES part_two.cc)

add_executable(day1 day1.cc)
target_link_libraries(day1 input part_one part_two)
