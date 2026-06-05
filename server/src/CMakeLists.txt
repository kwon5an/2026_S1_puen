cmake_minimum_required(VERSION 3.16)
project(fortress_server)

set(CMAKE_CXX_STANDARD 17)
find_package(Boost REQUIRED COMPONENTS system)

add_executable(fortress_server main.cpp)
target_link_libraries(fortress_server Boost::system pthread)
