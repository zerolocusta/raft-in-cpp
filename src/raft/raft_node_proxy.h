//
// Created by 陈达 on 2017/3/20.
//

#ifndef SIMPLE_RAFT_KVDB_CPP_RAFT_NODE_PROXY_H
#define SIMPLE_RAFT_KVDB_CPP_RAFT_NODE_PROXY_H

#include <boost/date_time/posix_time/posix_time_duration.hpp>
#include <boost/asio.hpp>
#include <boost/asio/deadline_timer.hpp>
#include "raft_server.h"

namespace raft
{
class RaftServer;
class RaftNodeProxy;
}

namespace raft
{

class RaftNodeProxy
{
  typedef std::shared_ptr<raft::RaftServer> raftServerPtr_t;

public:
  RaftNodeProxy(raftServerPtr_t server_ptr, const std::string &name, boost::asio::io_service &io_service, tcp::socket &&socket)
      : io_service_(io_service), socket_(std::move(socket)), timer_(io_service), server_ptr_(server_ptr), name_(name),
        next_index(0), match_index(0), voted(false){};
  ~RaftNodeProxy(){};

private:
  void setTimerFromNow(boost::posix_time::milliseconds, timeout_handler_t);
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

private:
  boost::asio::io_service &io_service_;
  boost::asio::ip::tcp::socket socket_;
  boost::asio::deadline_timer timer_;

  raftServerPtr_t server_ptr_;

  std::string name_;

  // Volatile state on leaders:
  uint64_t next_index;
  uint64_t match_index;

  // when server request vote
  bool voted;
};
}

#endif //SIMPLE_RAFT_KVDB_CPP_RAFT_NODE_PROXY_H
