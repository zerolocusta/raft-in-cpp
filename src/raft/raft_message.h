#ifndef RAFT_IN_CPP_RAFT_MESSAGE_H
#define RAFT_IN_CPP_RAFT_MESSAGE_H
#include "../protobuf/raft_msg.pb.h"
#include "raft_log.h"
#include <functional>
#include <string>
#include <vector>

class RaftMessageHandler
{
    typedef std::function<void(AppendEntriesResponseMessage &)> handleAppendEntriesRequestMessageFunc_t;
    typedef std::function<void(AppendEntriesResponseMessage &)> handleAppendEntriesResponseMessageFunc_t;

};

class AppendEntriesRequestMessage
{
  public:
    AppendEntriesRequestMessage(
        const uint64_t term,
        const uint64_t prev_log_index,
        const uint64_t prev_log_term,
        const uint64_t commit_index,
        const std::string &leader_name,
        const std::vector<RaftLogEntry> &&entries) : term(term),
                                                     prev_log_index(prev_log_index),
                                                     prev_log_term(prev_log_term),
                                                     commit_index(commit_index),
                                                     leader_name(leader_name),
                                                     entries(entries)
    {
    }

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
    AppendEntriesResponseMessage(
        const uint64_t term,
        const uint64_t current_index,
        const uint64_t commit_index,
        const bool success) : term(term),
                              current_index(current_index),
                              commit_index(commit_index),
                              success(success)
    {
    }

    const uint64_t term;
    const uint64_t current_index;
    const uint64_t commit_index;
    const bool success;
};

#endif // RAFT_IN_CPP_RAFT_MESSAGE_H