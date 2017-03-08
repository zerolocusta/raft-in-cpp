#include "raft_log.h"

namespace raft
{
RaftLogEntry::RaftLogEntry(
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

} // namespace raft
