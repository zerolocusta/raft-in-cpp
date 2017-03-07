#ifndef RAFT_IN_CPP_RAFT_NODE_H
#define RAFT_IN_CPP_RAFT_NODE_H

#include <cstdint>
#include <string>
#include <map>

class RaftNode
{
public:
    RaftNode(){};
    ~RaftNode(){};

private:
    // for save key-value pair
    std::map<string, string> record;
    
    std::string name;    
    uint64_t term;
    uint64_t prev_log_index;
    uint64_t prev_log_term;
    uint64_t commit_index;
};


#endif // RAFT_IN_CPP_RAFT_NODE_H