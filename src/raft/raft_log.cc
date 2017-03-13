#include "raft_log.h"

namespace raft
{

RaftLog::RaftLog() : commit_index_(0),
                     current_term_(0),
                     last_applied(0),
                     prev_log_index_(0),
                     prev_log_term_(0)
{
}

    RaftLogEntry::RaftLogEntry(const uint64_t, const uint64_t, const raft_msg::CommandType, const raft::entry_t &) {

    }
} // namespace raft
