#ifndef RAFT_IN_CPP_RAFR_H
#define RAFT_IN_CPP_RAFR_H

namespace raft
{
typedef std::string key_t;
typedef std::string value_t;
typedef std::pair< key_t, value_t > entry_t;

enum
{
    NORMAL_TIMEOUT = 300;
    ELECTION_TIMEOUT = 1000;
    DEFAUTL_PORT = 7970;
};

enum RAFT_STATE
{
    RAFT_STATE_NONE,
    RAFT_STATE_FOLLOWER,
    RAFT_STATE_CANDIDATE,
    RAFT_STATE_LEADER
};
}

#endif // RAFT_IN_CPP_RAFR_H