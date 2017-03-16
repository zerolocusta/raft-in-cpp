
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(runBasicTest raft_message_test.cpp)
find_package(Protobuf REQUIRED)
INCLUDE_DIRECTORIES(${PROTOBUF_INCLUDE_DIR})


target_link_libraries(runBasicTest gtest gtest_main)
target_link_libraries(runBasicTest simple_raft_kvdb_cpp)