cmake_minimum_required(VERSION 3.6)
project(simple_raft_kvdb_cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/protobuf/append_entries_request.pb.cc
        src/protobuf/append_entries_request.pb.h
        src/protobuf/append_entries_response.pb.cc
        src/protobuf/append_entries_response.pb.h
        src/protobuf/command_request.pb.cc
        src/protobuf/command_request.pb.h
        src/protobuf/command_response.pb.cc
        src/protobuf/command_response.pb.h
        src/protobuf/join_request.pb.cc
        src/protobuf/join_request.pb.h
        src/protobuf/join_response.pb.cc
        src/protobuf/join_response.pb.h
        src/protobuf/log_entry.pb.cc
        src/protobuf/log_entry.pb.h
        src/protobuf/raft_enum.pb.cc
        src/protobuf/raft_enum.pb.h
        src/protobuf/raft_msg.pb.cc
        src/protobuf/raft_msg.pb.h
        src/protobuf/vote_request.pb.cc
        src/protobuf/vote_request.pb.h
        src/protobuf/vote_response.pb.cc
        src/protobuf/vote_response.pb.h
        src/raft/raft.cc
        src/raft/raft.h
        src/raft/raft_log.cc
        src/raft/raft_log.h
        src/raft/raft_message.cc
        src/raft/raft_message.h
        src/raft/raft_node_proxy.cc
        src/raft/raft_node_proxy.h
        src/raft/raft_server.cc
        src/raft/raft_server.h
        src/start.cc
        LICENSE
        README.md)

add_executable(simple_raft_kvdb_cpp ${SOURCE_FILES})

find_package(Boost 1.63.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(simple_raft_kvdb_cpp ${Boost_LIBRARIES})