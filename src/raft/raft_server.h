#ifndef RAFT_IN_CPP_RAFT_SERVER_H
#define RAFT_IN_CPP_RAFT_SERVER_H

#include "raft.h"
#include "raft_log.h"
#include "raft_node.h"

#include "boost/date_time/posix_time/posix_time.hpp"

#include <set>
#include <memory>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

namespace raft
{

/* RaftServer represent local raft node*/
class RaftServer : public std::enable_shared_from_this<RaftServer>
{

  typedef std::shared_ptr<raft::RaftNodeProxy> RaftNodeProxyPtr_t;

public:
  explicit RaftServer(boost::asio::io_service &,
                      const tcp::endpoint &,
                      const std::string &);
  ~RaftServer();


private:

  void connectTo();
  void doAccept();

  void setTimerFromNow(const std::string &, boost::posix_time::ptime, std::function<void()>);
  // set hearrtbear timer for this server
  void setFollowerTimer();
  void setCandidateTimer();

  void becomeCandidate();
  void becomeFollower();

  //Boost.asio member
  boost::asio::io_service io_service_;
  tcp::acceptor acceptor_;

  std::map<std::string, RaftNodeProxyPtr_t> all_node_proxy;

  std::string my_name_;
  raft::RAFT_STATE state_;
  raft::RaftLog raft_log_;

  // become candidate, count vote granted
  uint64_t voted_count_;
  
  // receive request vote or become candidate, did this node voted;
  bool voted_;
  std::string voted_for_;

    // for save key-value pair
  std::map<string, string> kv_record;
};
} // namespace raft

#endif // RAFT_IN_CPP_RAFT_SERVER_H