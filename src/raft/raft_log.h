#ifndef RAFT_IN_CPP_RAFT_LOG_H
#define RAFT_IN_CPP_RAFT_LOG_H
#include "raft.h"
#include <vector>
#include "../protobuf/raft_enum.pb.h"
class RaftLog
{
  public:
  private:
    uint64_t current_index_;
    uint64_t current_term_;
    std::vector<RaftLogEntry> log_;
};

class RaftLogEntry
{
  public:
    RaftLogEntry(
        const uint64_t prev_log_term,
        const uint64_t prev_log_index,
        const CommandType command_type,
        const std::string &command_key,
        const std::string &connmad_value) : prev_log_term(prev_log_term),
                                            prev_log_index(prev_log_index),
                                            command_type(command_type),
                                            command_key(command_key),
                                            connmad_value(command_value)
    {
    }

    ~RaftLogEntry();

    const uint64_t prev_log_index;
    const uint64_t prev_log_term;
    const CommandType command_type;
    const std::string command_key;
    const std::string connmad_value;
}

#endif // RAFT_IN_CPP_RAFT_LOG_H