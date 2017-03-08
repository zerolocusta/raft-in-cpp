#ifndef RAFT_IN_CPP_RAFT_NODE_H
#define RAFT_IN_CPP_RAFT_NODE_H

#include <cstdint>
#include <string>
#include <map>
#include <boost/asio.hpp>
using boost::asio::ip::tcp;

namespace raft
{

class RaftNode
{
public:
  RaftNode(){};
  ~RaftNode(){};
  void handleConnection(tcp::socket &&socket)();

private:
  // for save key-value pair
  std::map<string, string> record;

  std::string name;
  uint64_t current_term;

  // Volatile state on all servers:
  uint64_t commit_index;
  uint64_t last_applied;

  // Volatile state on leaders:
  std::map<string, int> next_index;
  std::map<string, int> match_index;

  onRecvRaftMesssage();

  // for handle cluster message
  onRecvAppendEntriesRequest();
  onRecvAppendEntriesResponse();
  onRecvJoinRequest();
  onRecvJoinResponse();
  onRecvVoteRequest();
  onRecvVoteResponse();

  // for handle client command message
  onRecvCommandRequest();
  onRecvCommandResponse();
};
} // namespace raft

#endif // RAFT_IN_CPP_RAFT_NODE_H