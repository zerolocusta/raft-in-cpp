#include "raft_message.h"

namespace raft
{

AppendEntriesResponseMessage::AppendEntriesResponseMessage(
    const uint64_t term,
    const uint64_t current_index,
    const uint64_t commit_index,
    const bool success) : term(term),
                          current_index(current_index),
                          commit_index(commit_index),
                          success(success)
{
}

AppendEntriesResponseMessage::AppendEntriesResponseMessage(
    const uint64_t term,
    const uint64_t current_index,
    const uint64_t commit_index,
    const bool success) : term(term),
                          current_index(current_index),
                          commit_index(commit_index),
                          success(success)
{
}
} // namespace raft
