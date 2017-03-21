cmake_minimum_required(VERSION 3.6)
project(simple_raft_kvdb_cpp)

set(HEADER_FILES
        protobuf/append_entries_request.pb.h
        protobuf/append_entries_response.pb.h
        protobuf/command_request.pb.h
        protobuf/command_response.pb.h
        protobuf/join_request.pb.h
        protobuf/join_response.pb.h
        protobuf/log_entry.pb.h
        protobuf/raft_enum.pb.h
        protobuf/raft_msg.pb.h
        protobuf/vote_request.pb.h
        protobuf/vote_response.pb.h
        raft/raft.h
        raft/raft_log.h
        raft/raft_message.h
        raft/raft_server.h
        raft/raft_node_proxy.h
        )
set(SOURCE_FILES
        protobuf/append_entries_request.pb.cc
        protobuf/append_entries_response.pb.cc
        protobuf/command_request.pb.cc
        protobuf/command_response.pb.cc
        protobuf/join_request.pb.cc
        protobuf/join_response.pb.cc
        protobuf/log_entry.pb.cc
        protobuf/raft_enum.pb.cc
        protobuf/raft_msg.pb.cc
        protobuf/vote_request.pb.cc
        protobuf/vote_response.pb.cc
        raft/raft.cc
        raft/raft_log.cc
        raft/raft_message.cc
        raft/raft_server.cc
        raft/raft_node_proxy.cc)

add_library(simple_raft_kvdb_cpp STATIC ${SOURCE_FILES} ${HEADER_FILES})
find_package(Boost 1.63.0 COMPONENTS system filesystem REQUIRED)
find_package(Protobuf REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${PROTOBUF_INCLUDE_DIR})
include_directories(protobuf)
target_link_libraries(simple_raft_kvdb_cpp ${Boost_LIBRARIES})
target_link_libraries(simple_raft_kvdb_cpp ${PROTOBUF_LIBRARY})