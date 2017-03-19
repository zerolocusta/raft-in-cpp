#include "raft_server.h"

namespace raft
{
RaftServer::RaftServer(boost::asio::io_service &io_service, const tcp::endpoint &endpoint, const std::string &server_name)
    : io_service_(io_service),
      socket_(io_service),
      acceptor_(io_service, endpoint),
      server_name_(server_name),
      state_(raft::RAFT_STATE::RAFT_STATE_FOLLOWER),
      timer_(io_service)
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
                                   this->handleConnection(std::move(socket_));
                               }
                               doAccept();
                           });
}

void RaftServer::handleConnection(tcp::socket &&socket)
{
    // TODO: Parse connection message
    //    auto node_proxy_ptr = std::make_shared<raft::RaftNodeProxy>(shared_from_this(), <TODO>, io_service_, std::move(socket));
    //    all_node_proxy[<TODO>] = node_proxy_ptr;
}

void RaftServer::setTimerFromNow(boost::posix_time::milliseconds deadline_ms_from_now, timeout_handler_t timeout_handler)
{
    timer_.expires_from_now(deadline_ms_from_now);
    timer_.async_wait(timeout_handler);
}

void RaftServer::setFollowerTimer()
{
    setTimerFromNow(boost::posix_time::milliseconds(genRandomHeartBeatTime()),
                    [this](const boost::system::error_code &ec) { this->becomeCandidate(); });
}

void RaftServer::setCandidateTimer()
{
    setTimerFromNow(boost::posix_time::milliseconds(ELECTION_TIMEOUT),
                    [this](const boost::system::error_code &) { this->becomeCandidate(); });
}

void RaftServer::connectTo()
{
}

void RaftNodeProxy::setTimerFromNow(boost::posix_time::milliseconds deadline, timeout_handler_t timeout_handler)
{
    timer_.expires_from_now(deadline);
    timer_.async_wait(timeout_handler);
}

void RaftNodeProxy::setHeartBeatTimer()
{
    setTimerFromNow(boost::posix_time::milliseconds(genRandomHeartBeatTime()), [this](const boost::system::error_code &ec) { this->sendHeartBeat(); });
}
} // namespace raft
