#include "raft_server.h"

namespace raft
{
RaftServer::RaftServer(boost::asio::io_service &io_service, const tcp::endpoint &endpoint, const std::string &my_name)
    : io_service_(io_service),
      socket_(io_service),
      acceptor_(io_service, endpoint),
      my_name_(my_name),
      state_(raft::RAFT_STATE::RAFT_STATE_FOLLOWER)
{
    // TODO:  connectTo() or doAccept();
    // becomeFollower();
}

void RaftServer::doAccept()
{
    acceptor_.async_accept(socket_,
                           [this](boost::system::error_code ec) {
                               if (!ec)
                               {
                                   handleConnection(std::move(socket_));
                               }
                               doAccept();
                           });
}

void RaftServer::handleConnection(tcp::socket &&socket)
{
    // TODO: Parse connection message
    auto node_proxy_ptr = std::make_shared<raft::RaftNodeProxy>(shared_from_this(), <TODO>, io_service_, std::move(socket));
    all_node_proxy[<TODO>] = node_proxy_ptr;
}

void RaftServer::setTimerFromNow(boost::posix_time::ptime deadline, std::function<void()> timeout_handler)
{
    timer = boost::asio::deadline_timer(io_service_);
    timer.expires_from_now(deadline);
    timer.asynv_wait(timeout_handler);
}

void RaftServer::setFollowerTimer()
{
    setTimerFromNow(boost::posix_time::milliseconds(genRandomHeartBeatTime()),
                    this->becomeCandidate);
}

void RaftServer::setCandidateTimer()
{
    setTimerFromNow(boost::posix_time::milliseconds(ELECTION_TIMEOUT),
                    this->becomeCandidate);
}
} // namespace raft
