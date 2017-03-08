#ifndef RAFT_IN_CPP_RAFT_MESSAGE_H
#define RAFT_IN_CPP_RAFT_MESSAGE_H
#include "../protobuf/raft_msg.pb.h"
#include "../protobuf/raft_enum.pb.h"
#include "raft_log.h"
#include "raft.h"
#include <functional>
#include <string>
#include <vector>
#include <cstdint>

namespace raft
{
class RaftMessageHandler
{
    typedef std::function<void(AppendEntriesResponseMessage &)> handleAppendEntriesRequestMessageFunc_t;
    typedef std::function<void(AppendEntriesResponseMessage &)> handleAppendEntriesResponseMessageFunc_t;
};

class AppendEntriesRequestMessage
{
  public:
    AppendEntriesRequestMessage(const uint64_t, const uint64_t, const uint64_t, const uint64_t, const std::string &, const std::vector<RaftLogEntry> &&);

    const uint64_t term;
    const uint64_t prev_log_index;
    const uint64_t prev_log_term;
    const uint64_t commit_index;
    const std::string leader_name;
    const std::vector<RaftLogEntry> entries;
};

class AppendEntriesResponseMessage
{
  public:
    AppendEntriesResponseMessage(const uint64_t, const uint64_t, const uint64_t, const bool);

    const uint64_t term;
    const uint64_t current_index;
    const uint64_t commit_index;
    const bool success;
};

class CommandRequestMessage
{

  public:
    CommandRequestMessage(const uint64_t, const std::string &, const entry &);

    const uint64_t command_id;
    const std::string passwd;
    const raft::entry_t connmad_entry;
};
}

#endif // RAFT_IN_CPP_RAFT_MESSAGE_H