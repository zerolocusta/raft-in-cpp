#include "raft_message.h"
#include "../protobuf/raft_msg.pb.h"

namespace raft
{
KVEntryMessage::KVEntryMessage(const raft::entry_t &entry) : entry(entry) {}
KVEntryMessage::KVEntryMessage(const raft::entry_t &entry) : entry(entry) {}


raft_msg::KVEntryMessage KVEntryMessage::genProtoBufMessage(){
    
    auto kv_entry = raft_msg::KVEntry();
    kv_entry.set_key(entry.first);
    kv_entry.set_value(entry.second);
    return kv_entry;
    
    
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
