project(Money_program)

set (CMAKE_CXX_STANDARD 20)
cmake_minimum_required()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY out)

find_package(nlohmann_json 3.10.5 REQUIRED)

#excecutables
add_executable(main ./src/main.cpp)

target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)