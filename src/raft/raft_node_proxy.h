#ifndef RAFT_IN_CPP_RAFT_NODE_H
#define RAFT_IN_CPP_RAFT_NODE_H

#include <cstdint>
#include <string>
#include "boost/asio.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
using boost::asio::ip::tcp;

namespace raft
{

class RaftNodeProxy
{
  typedef std::shared_ptr<raft::RaftServer> raftServerPtr_t;

public:
  RaftNodeProxy(raftServerPtr_t, const std::string &, boost::asio::io_service &, tcp::socket &&socket){};
  ~RaftNodeProxy(){};

private:
  boost::asio::io_service io_service_;

  raftServerPtr_t server_ptr;
  std::string name;

  // Volatile state on leaders:
  uint64_t next_index;
  uint64_t match_index;

  // when server request vote
  bool voted;

  boost::asio::deadline_timer timer;

  void setTimerFromNow(boost::posix_time::ptime, std::function<void()>);
  void setHeartBeatTimer();

  void sendHeartBeat();
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