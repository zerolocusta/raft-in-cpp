cmake_minimum_required(VERSION 3.6)
project(simple_raft_kvdb_cpp)

include_directories(${PROJECT_SOURCE_DIR}/src)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(src)
add_subdirectory(test)

add_executable(simple_raft_kvdb_cpp_run src/start.cc)
