#include "raft_message.h"

namespace raft
{

PackedMessage::PackedMessage(void *data, uint32_t size)
{
    uint32_t be32 = htobe32(size);
    data_ = new char[be32 + size];
    ::memcpy(data_, &be32, sizeof be32);
    ::memcpy(data_ + sizeof be32, data, size);
    size_ = size + sizeof be32;
}

PackedMessage::PackedMessage(const std::string &str)
{
    if (str.size() > MESSAGE_MAX_SIZE)
        return;
    uint32_t strsize = static_cast<uint32_t>(str.size());
    uint32_t be32 = htobe32(strsize);
    data_ = new char[be32 + strsize];
    ::memcpy(data_, &be32, sizeof be32);
    ::memcpy(data_ + sizeof be32, str.data(), strsize);
    size_ = strsize + sizeof be32;
}

uint32_t PackedMessage::size()
{
    return size_;
}

char *PackedMessage::data() const
{
    return data_;
}

PackedMessage::~PackedMessage()
{
    delete[] data_;
}

// KVEntryMessage
KVEntryMessage::KVEntryMessage(const raft::entry_t &entry)
    : entry_(entry)
{
}
KVEntryMessage::KVEntryMessage(const raft_msg::KVEntry &kv_entry)
    : entry_(make_pair(kv_entry.key(), kv_entry.value()))
{
}

KVEntryRawPtr_t KVEntryMessage::genProtoBufKVEntryMessage()
{
    // TODO remember  delete this pointer
    auto kv_entry = new raft_msg::KVEntry();
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

LogEntryRawPtr_t LogEntryMessage::genProtoBufLogEntryMessage()
{
    auto log_entry_ptr = new raft_msg::LogEntry();
    log_entry_ptr->set_index(index_);
    log_entry_ptr->set_term(term_);
    log_entry_ptr->set_command_type(command_type_);

    auto kv_entry_message = KVEntryMessage(kv_entry_);
    log_entry_ptr->set_allocated_entry(kv_entry_message.genProtoBufKVEntryMessage());
    return log_entry_ptr;
}

// LogEntryMessage END

// AppendEntriesRequestMessage
AppendEntriesRequestMessage::AppendEntriesRequestMessage(const uint64_t term, const uint64_t prev_log_index, const uint64_t prev_log_term,
                                                         const uint64_t commit_index, const std::string &leader_name,
                                                         const std::vector<RaftLogEntry> &entries)
    : term_(term), prev_log_index_(prev_log_index), prev_log_term_(prev_log_term),
      commit_index_(commit_index), leader_name_(leader_name), raft_log_entries_(entries)
{
}

AppendEntriesRequestMessage::AppendEntriesRequestMessage(const raft_msg::AppendEntriesRequest &append_entries_request)
    : term_(append_entries_request.term()),
      prev_log_index_(append_entries_request.prev_log_index()),
      prev_log_term_(append_entries_request.prev_log_term()),
      commit_index_(append_entries_request.commit_index()),
      leader_name_(append_entries_request.leader_name())
{
    for (auto raft_log_entry : append_entries_request.entries())
    {
        raft_log_entries_.push_back(RaftLogEntry(raft_log_entry.index(), raft_log_entry.term(), raft_log_entry.command_type(), std::make_pair(raft_log_entry.entry().key(), raft_log_entry.entry().value())));
    }
}

std::string AppendEntriesRequestMessage::serializeAsString()
{
    auto raft_message = RaftMessage();
    auto append_entries_request_ptr = raft_message.mutable_append_entries_request();
    append_entries_request_ptr->set_term(term_);
    append_entries_request_ptr->set_prev_log_index(prev_log_index_);
    append_entries_request_ptr->set_prev_log_term(prev_log_term_);
    append_entries_request_ptr->set_commit_index(commit_index_);
    append_entries_request_ptr->set_leader_name(leader_name_);
    for (auto e : raft_log_entries_)
    {
        auto add_entry_ptr = append_entries_request_ptr->add_entries();
        add_entry_ptr->set_index(e.getIndex());
        add_entry_ptr->set_term(e.getTerm());
        add_entry_ptr->set_command_type((e.getCommand_type()));

        auto kv_entry_message = KVEntryMessage(entry_t(e.getEntry().first, e.getEntry().second));
        add_entry_ptr->set_allocated_entry(kv_entry_message.genProtoBufKVEntryMessage());
    }
    auto data = raft_message.SerializeAsString();
    return data;
}
// AppendEntriesRequestMessage END

// AppendEntriesResponseMessage
AppendEntriesResponseMessage::AppendEntriesResponseMessage(
    const uint64_t term,
    const uint64_t current_index,
    const uint64_t commit_index,
    const bool success) : term_(term),
                          current_index_(current_index),
                          commit_index_(commit_index),
                          success_(success)
{
}

AppendEntriesResponseMessage::AppendEntriesResponseMessage(const raft_msg::AppendEntriesResponse &append_entries_response)
    : term_(append_entries_response.term()),
      current_index_(append_entries_response.current_index()),
      commit_index_(append_entries_response.commit_index()),
      success_(append_entries_response.success())
{
}

std::string AppendEntriesResponseMessage::serializeAsString()
{
    auto raft_message = RaftMessage();
    auto append_entries_response_ptr = raft_message.mutable_append_entries_response();
    append_entries_response_ptr->set_term(term_);
    append_entries_response_ptr->set_commit_index(commit_index_);
    append_entries_response_ptr->set_current_index(current_index_);
    append_entries_response_ptr->set_success(success_);
    return raft_message.SerializeAsString();
}
// AppendEntriesResponseMessage END

CommandRequestMessage::CommandRequestMessage(const uint64_t command_id, const std::string &passwd,
                                             const raft_msg::CommandType command_type,
                                             const entry_t &command_entry)
    : command_id_(command_id), passwd_(passwd), command_type_(command_type), command_entry_(command_entry)
{
}

CommandRequestMessage::CommandRequestMessage(const raft_msg::CommandRequest &command_request)
    : command_id_(command_request.command_id()), passwd_(command_request.passwd()), command_type_(command_request.command_type()),
      command_entry_(std::make_pair(command_request.command().key(), command_request.command().value()))
{
}

std::string CommandRequestMessage::serializeAsString()
{
    auto raft_message = RaftMessage();
    auto command_request_ptr = raft_message.mutable_command_request();
    command_request_ptr->set_command_id(command_id_);
    command_request_ptr->set_passwd(passwd_);
    command_request_ptr->set_command_type(command_type_);
    command_request_ptr->set_allocated_command(KVEntryMessage(command_entry_).genProtoBufKVEntryMessage());
    return raft_message.SerializeAsString();
}
} // namespace raft
