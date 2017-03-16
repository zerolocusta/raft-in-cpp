#ifndef RAFT_IN_CPP_RAFT_LOG_H
#define RAFT_IN_CPP_RAFT_LOG_H
#include "raft.h"
#include <vector>
#include "../protobuf/raft_enum.pb.h"

namespace raft
{
class RaftLogEntry
{
  public:
    RaftLogEntry();

    RaftLogEntry(const uint64_t, const uint64_t, const raft_msg::CommandType, const raft::entry_t &);

    uint64_t getIndex() const;

    uint64_t getTerm() const;

    const raft_msg::CommandType getCommand_type() const;

    const entry_t &getEntry() const;

  private:
    uint64_t index_;
    uint64_t term_;
    const raft_msg::CommandType command_type_;
    const raft::entry_t entry_;
};

class RaftLog
{
  public:
    RaftLog();

    uint64_t getCommit_index() const;

    void setCommit_index(uint64_t commit_index_);

    uint64_t getCurrent_term() const;

    void setCurrent_term(uint64_t current_term_);

    uint64_t getLast_applied() const;

    void setLast_applied(uint64_t last_applied_);

    uint64_t getPrev_log_index() const;

    void setPrev_log_index(uint64_t prev_log_index_);

    uint64_t getPrev_log_term() const;

    void setPrev_log_term(uint64_t prev_log_term_);

    const std::vector<RaftLogEntry> &getLogs() const;

  private:
    uint64_t commit_index_;
    uint64_t current_term_;
    uint64_t last_applied_;
    uint64_t prev_log_index_;
    uint64_t prev_log_term_;
    std::vector<RaftLogEntry> logs_;
};

} // namespace raft

#endif // RAFT_IN_CPP_RAFT_LOG_H