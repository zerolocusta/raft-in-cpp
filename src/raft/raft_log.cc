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

} // namespace raft
