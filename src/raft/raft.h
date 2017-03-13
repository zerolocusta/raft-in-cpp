#ifndef RAFT_IN_CPP_RAFR_H
#define RAFT_IN_CPP_RAFR_H
#include <utility>
#include <raft_message.h>
#include "raft_message.h"
#include "../protobuf/raft_msg.pb.h"
namespace raft
{
typedef std::string key_t;
typedef std::string value_t;
typedef std::pair<key_t, value_t> entry_t;

typedef std::shared_ptr<raft_msg::KVEntry> KVEntryPtr_t;
typedef std::shared_ptr<raft_msg::LogEntry> LogEntryPtr_t;
typedef std::shared_ptr<raft_msg::RaftMessage> RaftMessagePtr_t;

// handle Message callback function type
typedef std::function<void(BaseMessage &)> handleBaseMessageMessageFunc_t;
typedef std::function<void(KVEntryMessage &)> handleKVEntryMessageFunc_t;
typedef std::function<void(LogEntryMessage &)> handleLogEntryMessageFunc_t;
typedef std::function<void(AppendEntriesRequestMessage &)> handleAppendEntriesRequestMessageFunc_t;
typedef std::function<void(AppendEntriesResponseMessage &)> handleAppendEntriesResponseMessageFunc_t;
typedef std::function<void(CommandRequestMessage &)> handleCommandRequestMessageFunc_t;
typedef std::function<void(CommandResponseMessage &)> handleCommandResponseMessageFunc_t;
typedef std::function<void(JoinRequestMessage &)> handleJoinRequestMessageFunc_t;
typedef std::function<void(JoinResponseMessage &)> handleJoinResponseMessageFunc_t;
typedef std::function<void(VoteRequestMessage &)> handleVoteRequestMessageFunc_t;
typedef std::function<void(VoteResponseMessage &)> handleVoteResponseMessageFunc_t;

enum
{
    MAX_HEARTBEAT_TIMEOUT = 300,
    ELECTION_TIMEOUT = 1000,
    DEFAUTL_PORT = 7970
};

enum RAFT_STATE
{
    RAFT_STATE_FOLLOWER,
    RAFT_STATE_CANDIDATE,
    RAFT_STATE_LEADER
};

int genRandomHeartBeatTime();
}

#endif // RAFT_IN_CPP_RAFR_H