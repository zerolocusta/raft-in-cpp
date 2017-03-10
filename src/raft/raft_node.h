#ifndef RAFT_IN_CPP_RAFT_NODE_H
#define RAFT_IN_CPP_RAFT_NODE_H

#include <cstdint>
#include <string>
#include <map>
#include <set>
#include "boost/asio.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
using boost::asio::ip::tcp;

namespace raft
{

class RaftNode
{
public:
  RaftNode(const std::string &, boost::asio::io_service &){};
  ~RaftNode(){};
  void handleConnection(tcp::socket &&socket)();

private:
  boost::asio::io_service io_service_;
  // for save key-value pair
  std::map<string, string> record;

  std::string name;
  raft::RAFT_STATE state;
  uint64_t current_term;

  // voed record

  //when become a candidate, for save numbers of granted and name;
  uint64_t voted_count;
  std::set<std::string> voted_names;

  //when receive first vote request in current_term, set voted_for become who you voted
  //and set voted true
  std::string voted_for;
  bool voted;

  // Volatile state on all servers:
  uint64_t commit_index;
  uint64_t last_applied;

  // Volatile state on leaders:
  std::map<std::string, uint64_t> next_index;
  std::map<std::string, uint64_t> match_index;

  std::map<string, std::shared_ptr<boost::asio::deadline_timer>> timers;

  void becomeCandidate();

  void becomeFollower();

  void setTimerFromNow(const std::string &, boost::posix_time::ptime, std::function<void()>);

  // set follower hearrtbear timer
  void setFollowerTimer();
  void setCandidateTimer();

  void onRecvRaftMesssage();

  // for handle cluster message
  void onRecvAppendEntriesRequest();
  void onRecvAppendEntriesResponse();
  void onRecvJoinRequest();
  void onRecvJoinResponse();
  void onRecvVoteRequest();
  void onRecvVoteResponse();

  // for handle client command message
  void onRecvCommandRequest();
  void onRecvCommandResponse();
};
} // namespace raft

#endif // RAFT_IN_CPP_RAFT_NODE_H