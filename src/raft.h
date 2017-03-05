#ifndef RAFT_IN_CPP_RAFR_H
#define RAFT_IN_CPP_RAFR_H
const int NORMAL_TIMEOUT = 300;
const int ELECTION_TIMEOUT = 1000;
const int DEFAUTL_PORT = 7894;
enum RAFT_EVENT
{
    RAFT_EVENT_JOIN,
    RAFT_EVENT_QUIT,
    RAFT_EVENT_HEARTBEAT,
    RAFT_EVENT_VOTE,
    RAFT_EVENT_REQUEST,
    RAFT_EVENT_SYNC
};

enum RAFT_STATE
{
    RAFT_STATE_NONE,
    RAFT_STATE_FOLLOWER,
    RAFT_STATE_CANDIDATE,
    RAFT_STATE_LEADER
};

#endif // RAFT_IN_CPP_RAFR_H