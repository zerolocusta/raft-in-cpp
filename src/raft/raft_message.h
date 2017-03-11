#ifndef RAFT_IN_CPP_RAFT_MESSAGE_H
#define RAFT_IN_CPP_RAFT_MESSAGE_H
#include "../protobuf/raft_msg.pb.h"
#include "../protobuf/raft_enum.pb.h"
#include "raft_log.h"
#include "raft.h"
#include <functional>
#include <string>
#include <vector>
#include <cstdint>
#include <memory>

namespace raft
{
class KVEntryMessage;
class LogEntryMessage;
class BaseMessage;
class AppendEntriesRequestMessage;
class AppendEntriesResponseMessage;
class CommandRequestMessage;
class CommandResponseMessage;
class JoinRequestMessage;
class JoinResponseMessage;
class VoteRequestMessage;
class VoteResponseMessage;
}

namespace raft
{
class KVEntryMessage
{
  public:
    KVEntryMessage(const raft::entry_t &&);
    KVEntryMessage(const raft_msg::KVEntry &);
    aft_msg::KVEntryMessage genProtoBufMessage();

    const raft::entry_t entry;
};

class LogEntryMessage
{
  public:
    LogEntryMessage(const uint64_t, const uint64_t, const raft_msg::CommandType, const KVEntryMessage &);
    LogEntryMessage(const raft_msg::LogEntry &);
    raft_msg::LogEntryMessage genProtoBufMessage();

    const uint64_t index;
    const uint64_t term;
    const raft_msg::CommandType command_type;
    const KVEntryMessage entry;
};

class BaseMessage
{
  public:
    virtual ~BaseMessage() = default;
    virtual raft_msg::RaftMessage genProtoBufMessage() = 0;
};

class AppendEntriesRequestMessage : public BaseMessage
{
  public:
    AppendEntriesRequestMessage(const uint64_t, const uint64_t, const uint64_t, const uint64_t, const std::string &, const std::vector<LogEntryMessage> &&);
    AppendEntriesRequestMessage(const raft_msg::AppendEntriesRequest &);
    raft_msg::RaftMessage genProtoBufMessage() override;

    const uint64_t term;
    const uint64_t prev_log_index;
    const uint64_t prev_log_term;
    const uint64_t commit_index;
    const std::string leader_name;
    const std::vector<LogEntryMessage> entries;
};

class AppendEntriesResponseMessage : public BaseMessage
{
  public:
    AppendEntriesResponseMessage(const uint64_t, const uint64_t, const uint64_t, const bool);
    AppendEntriesResponseMessage(const raft_msg::AppendEntriesResponse &);
    raft_msg::RaftMessage genProtoBufMessage() override;

    const uint64_t term;
    const uint64_t current_index;
    const uint64_t commit_index;
    const bool success;
};

class CommandRequestMessage : public BaseMessage
{

  public:
    CommandRequestMessage(const uint64_t, const std::string &, const raft_msg::CommandType, const KVEntryMessage &&);
    CommandRequestMessage(const raft_msg::CommandRequest &);
    raft_msg::RaftMessage genProtoBufMessage() override;

    const uint64_t command_id;
    const std::string passwd;
    const raft_msg::CommandType command_type;
    const KVEntryMessage connmad_entry;
};

class CommandResponseMessage : public BaseMessage
{
  public:
    CommandResponseMessage(const uint64_t, const bool, const std::string &, const raft_msg::CommandResponseErr, const KVEntryMessage &&);
    CommandResponseMessage(const raft_msg::CommandResponse &);
    raft_msg::RaftMessage genProtoBufMessage() override;

    const uint64_t command_id;
    const bool success;
    const std::string passwd;
    const raft_msg::CommandResponseErr err;
    const KVEntryMessage result;
};

class JoinRequestMessage : public BaseMessage
{
  public:
    JoinRequestMessage(const raft_msg::JoinRole, const std::string &, const std::string &, const std::string &);
    JoinRequestMessage(const raft_msg::JoinRequest &);
    raft_msg::RaftMessage genProtoBufMessage() override;

    const raft_msg::JoinRole role;
    const std::string ipaddr;
    const std::string passwd;
    const std::string myname;
};

class JoinResponseMessage : public BaseMessage
{
  public:
    JoinResponseMessage(const bool, const std::string &, const std::string &, const raft_msg::JoinError);
    JoinResponseMessage(const raft_msg::JoinResponse &);

    raft_msg::RaftMessage genProtoBufMessage() override;

    const bool success;
    const std::string myname;
    const std::string passwd;
    const raft_msg::JoinError join_err;
};

class VoteRequestMessage : public BaseMessage
{
  public:
    VoteRequestMessage(const uint64_t, const uint64_t, const uint64_t, const std::string);
    VoteRequestMessage(const raft_msg::VoteRequest &);

    raft_msg::RaftMessage genProtoBufMessage() override;

    const uint64_t term;
    const uint64_t last_log_index;
    const uint64_t last_log_term;
    const std::string candidate_name;
};

class VoteResponseMessage : public BaseMessage
{
  public:
    VoteResponseMessage(const uint64_t, const bool);
    VoteResponseMessage(const raft_msg::VoteResponse &);

    raft_msg::RaftMessage genProtoBufMessage() override;

    const uint64_t term;
    const bool vote_granted;
};

} // namespace raft

#endif // RAFT_IN_CPP_RAFT_MESSAGE_H