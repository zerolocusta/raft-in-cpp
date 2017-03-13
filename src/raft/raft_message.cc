#include "raft_message.h"

namespace raft
{

// KVEntryMessage
KVEntryMessage::KVEntryMessage(const raft::entry_t &entry)
    : entry_(entry)
{
}
KVEntryMessage::KVEntryMessage(const raft_msg::KVEntry &kv_entry)
    : entry_(make_pair(kv_entry.key(), kv_entry.value()))
{
}

KVEntryPtr_t KVEntryMessage::genProtoBufKVEntryMessage()
{

    auto kv_entry = std::make_shared<raft_msg::KVEntry>();
    kv_entry->set_key(entry_.first);
    kv_entry->set_value(entry_.second);
    return kv_entry;
}
// KVEntryMessage END

// LogEntryMessage
LogEntryMessage::LogEntryMessage(const uint64_t index, const uint64_t term, const raft_msg::CommandType command_type, const raft_msg::KVEntry &kv_entry)
    : index_(index),
      term_(term),
      command_type_(command_type),
      kv_entry_(std::make_pair(kv_entry.key(), kv_entry.value()))
{
}

LogEntryMessage::LogEntryMessage(const raft_msg::LogEntry &log_entry)
    : index_(log_entry.index()),
      term_(log_entry.term()),
      command_type_(log_entry.command_type()),
      kv_entry_(std::make_pair(log_entry.entry().key(), log_entry.entry().value()))
{
}

LogEntryPtr_t LogEntryMessage::genProtoBufLogEntryMessage()
{
    auto log_entry = std::make_shared<raft_msg::LogEntry>();
    log_entry->set_index(index_);
    log_entry->set_term(term_);
    log_entry->set_command_type(command_type_);
    auto kv_entry_ptr = log_entry->mutable_entry();
    kv_entry_ptr->set_key(kv_entry_.first);
    kv_entry_ptr->set_value(kv_entry_.second);
    return log_entry;
}

// LogEntryMessage END

// AppendEntriesRequestMessage
AppendEntriesRequestMessage::AppendEntriesRequestMessage(const uint64_t term, const uint64_t prev_log_index, const uint64_t prev_log_term,
                                                         const uint64_t commit_index, const std::string &leader_name,
                                                         const std::vector<RaftLogEntry> &entries)
    : term_(term), prev_log_index_(prev_log_index), prev_log_term_(prev_log_term),
      commit_index_(commit_index), leader_name_(leader_name), entries_(entries)
{
}

AppendEntriesRequestMessage::AppendEntriesRequestMessage(const raft_msg::AppendEntriesRequest &append_entries_request)
    : term_(append_entries_request.term()),
      prev_log_index_(append_entries_request.prev_log_index()),
      prev_log_term_(append_entries_request.prev_log_term()),
      commit_index_(append_entries_request.commit_index()),
      leader_name_(append_entries_request.leader_name())
{
    std::vector entries_temp;
}
// AppendEntriesRequestMessage END

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
