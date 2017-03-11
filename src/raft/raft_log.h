#ifndef RAFT_IN_CPP_RAFT_LOG_H
#define RAFT_IN_CPP_RAFT_LOG_H
#include "raft.h"
#include <vector>
#include "../protobuf/raft_enum.pb.h"

namespace raft
{

class RaftLog
{
public:
  RaftLog();
private:
  uint64_t commit_index_;
  uint64_t current_term_;
  uint64_t last_applied;
  uint64_t prev_log_index;
  uint64_t prev_log_term;
  std::vector<RaftLogEntry> log_;
};

class RaftLogEntry
{
public:
  RaftLogEntry(const uint64_t, const uint64_t, const CommandType, const raft::entry_t &);

  ~RaftLogEntry();

  uint64_t index;
  uint64_t term;
  const CommandType command_type;
  const raft::entry_t entry;
};
} // namespace raft

#endif // RAFT_IN_CPP_RAFT_LOG_H