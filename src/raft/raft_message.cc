#include "raft_message.h"
#include "../protobuf/raft_msg.pb.h"

namespace raft
{
KVEntryMessage::KVEntryMessage(const raft::entry_t &entry) : entry(entry) {}
KVEntryMessage::KVEntryMessage(const raft::entry_t &entry) : entry(entry) {}


std::unique_ptr<raft_msg::RaftMessage> KVEntryMessage::genProtoBufMessage(){
    
    auto p =  std::make_unique<raft_msg::RaftMessage>()
    p->set_
    
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
