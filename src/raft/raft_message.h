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

namespace raft
{
class BaseMessage;
class KVEntryMessage;
class LogEntryMessage;
class RaftMessageHandler;
class AppendEntriesRequestMessage;
class AppendEntriesResponseMessage;
class CommandRequestMessage;
class CommandResponseMessage;
class JoinRequestMessage;
class JoinResponseMessage;
}

namespace raft
{

class RaftMessageHandler
{
    typedef std::function<void(AppendEntriesResponseMessage &)> handleAppendEntriesRequestMessageFunc_t;
    typedef std::function<void(AppendEntriesResponseMessage &)> handleAppendEntriesResponseMessageFunc_t;
    typedef std::function<void(CommandRequestMessage &)> handleCommandRequestMessageFunc_t;
    typedef std::function<void(CommandResponseMessage &)> handleCommandResponseMessageFunc_t;
};

class BaseMessage
{
  public:
    virtual ~BaseMessage() = default;
    virtual raft_msg::RaftMessage genProtoBufMessage() = 0;
};

class KVEntryMessage : public BaseMessage
{
  public:
    KVEntryMessage(const std::string &, const std::string &);
    KVEntryMessage(const raft_msg::KVEntry &);

    const std::string key;
    const std::string value;
};

class LogEntryMessage : public BaseMessage
{
  public:
    LogEntryMessage(const uint64_t, const uint64_t, const raft_msg::CommandType, const KVEntryMessage &);
    LogEntryMessage(const raft_msg::LogEntry &);

    const uint64_t index;
    const uint64_t term;
    const raft_msg::CommandType command_type;
    const KVEntryMessage entry;
};

class AppendEntriesRequestMessage : public BaseMessage
{
  public:
    AppendEntriesRequestMessage(const uint64_t, const uint64_t, const uint64_t, const uint64_t, const std::string &, const std::vector<LogEntryMessage> &&);
    AppendEntriesRequestMessage(const raft_msg::AppendEntriesRequest &);

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

    const uint64_t term;
    const uint64_t current_index;
    const uint64_t commit_index;
    const bool success;
};

class CommandRequestMessage : public BaseMessage
{

  public:
    CommandRequestMessage(const uint64_t, const std::string &, const raft_msg::CommandType, const raft::entry_t &&);

    const uint64_t command_id;
    const std::string passwd;
    const raft_msg::CommandType command_type;
    const raft::entry_t connmad_entry;
};

class CommandResponseMessage : public BaseMessage
{
  public:
    CommandResponseMessage(const uint64_t, const bool, const std::string &, const raft_msg::CommandResponseErr, const raft::entry_t &&);

    const uint64_t command_id;
    const bool success;
    const std::string passwd;
    const raft_msg::CommandResponseErr err;
    const raft::entry_t result;
};

class JoinRequestMessage : public BaseMessage
{
  public:
    JoinRequestMessage(const raft_msg::JoinRole, const std::string &, const std::string &, const std::string &);

    const raft_msg::JoinRole role;
    const std::string ipaddr;
    const std::string passwd;
    const std::string myname;
};

class JoinResponseMessage : public BaseMessage
{
  public:
    JoinResponseMessage(const bool, const std::string &, const std::string &, const raft_msg::JoinError);

    const bool success;
    const std::string myname;
    const std::string passwd;
    const raft_msg::JoinError join_err;
};

} // namespace raft

#endif // RAFT_IN_CPP_RAFT_MESSAGE_H