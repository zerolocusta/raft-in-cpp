#ifndef RAFT_IN_CPP_RAFT_LOG_H
#define RAFT_IN_CPP_RAFT_LOG_H
#include "raft.h"
#include <vector>
#include "../protobuf/raft_enum.pb.h"
class RaftLog
{
public:

private:
    
};


class RaftLogEntry
{
public:
    RaftLogEntry(const uint64_t,const uint64_t,
                const CommandType, const std::string&, const std::string&);
    ~RaftLogEntry();

private:
    const uint64_t index_;
    const uint64_t term_;
    const CommandType command_type_;
    const std::string command_key_;
    const std::string connmad_value_;
}

#endif // RAFT_IN_CPP_RAFT_LOG_H