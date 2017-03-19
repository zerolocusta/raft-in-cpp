#ifndef RAFT_IN_CPP_RAFT_MESSAGE_H
#define RAFT_IN_CPP_RAFT_MESSAGE_H
#include "../protobuf/raft_msg.pb.h"
#include "../protobuf/raft_enum.pb.h"
#include "raft.h"
#include "raft_log.h"
#include <functional>
#include <string>
#include <string.h>
#include <vector>
#include <cstdint>
#include <memory>

using namespace raft_msg;
namespace raft
{
class PackedMessage;

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

class PackedMessage
{
public:
  PackedMessage(void *data, uint32_t size);
  PackedMessage(const std::string &data);
  ~PackedMessage();
  uint32_t size();
  char *data() const;

private:
  uint32_t size_;
  char *data_;
};

class KVEntryMessage
{
public:
  KVEntryMessage(const entry_t &);
  KVEntryMessage(const raft_msg::KVEntry &);
  KVEntryRawPtr_t genProtoBufKVEntryMessage();

private:
  const entry_t entry_;
};

class LogEntryMessage
{
public:
  LogEntryMessage(const uint64_t, const uint64_t, const raft_msg::CommandType, const raft_msg::KVEntry &);
  LogEntryMessage(const raft_msg::LogEntry &);

  LogEntryRawPtr_t genProtoBufLogEntryMessage();

private:
  const uint64_t index_;
  const uint64_t term_;
  const raft_msg::CommandType command_type_;
  const entry_t kv_entry_;
};

class BaseMessage
{
public:
  virtual ~BaseMessage() = default;
  virtual std::string serializeAsString() = 0;
};

class AppendEntriesRequestMessage : public BaseMessage
{
public:
  AppendEntriesRequestMessage(const uint64_t, const uint64_t, const uint64_t, const uint64_t, const std::string &, const std::vector<RaftLogEntry> &);
  AppendEntriesRequestMessage(const raft_msg::AppendEntriesRequest &);

  std::string serializeAsString() override;

private:
  const uint64_t term_;
  const uint64_t prev_log_index_;
  const uint64_t prev_log_term_;
  const uint64_t commit_index_;
  const std::string leader_name_;
  std::vector<RaftLogEntry> raft_log_entries_;
};

class AppendEntriesResponseMessage : public BaseMessage
{
public:
  AppendEntriesResponseMessage(const uint64_t, const uint64_t, const uint64_t, const bool);
  AppendEntriesResponseMessage(const raft_msg::AppendEntriesResponse &);
  std::string serializeAsString() override;

private:
  const uint64_t term_;
  const uint64_t current_index_;
  const uint64_t commit_index_;
  const bool success_;
};

class CommandRequestMessage : public BaseMessage
{

public:
  CommandRequestMessage(const uint64_t command_id, const std::string &passwd, const raft_msg::CommandType command_type, const entry_t &command_entry);
  CommandRequestMessage(const raft_msg::CommandRequest &command_request);
  std::string serializeAsString() override;

private:
  const uint64_t command_id_;
  const std::string passwd_;
  const raft_msg::CommandType command_type_;
  const entry_t command_entry_;
};

class CommandResponseMessage : public BaseMessage
{
public:
  CommandResponseMessage(const uint64_t, const bool, const std::string &, const raft_msg::CommandResponseErr, const entry_t &);
  CommandResponseMessage(const raft_msg::CommandResponse &);
  std::string serializeAsString() override;

private:
  const uint64_t command_id;
  const bool success;
  const std::string passwd;
  const raft_msg::CommandResponseErr err;
  const entry_t result;
};

class JoinRequestMessage : public BaseMessage
{
public:
  JoinRequestMessage(const raft_msg::JoinRole, const std::string &, const std::string &, const std::string &);
  JoinRequestMessage(const raft_msg::JoinRequest &);
  std::string serializeAsString() override;

private:
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

  std::string serializeAsString() override;

private:
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

  std::string serializeAsString() override;

private:
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

  std::string serializeAsString() override;

private:
  const uint64_t term;
  const bool vote_granted;
};

} // namespace raft

#endif // RAFT_IN_CPP_RAFT_MESSAGE_H