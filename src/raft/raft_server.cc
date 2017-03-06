#include "raft_server.h"

RaftServer::RaftServer(boost::asio::io_service& io_service, const tcp_endpoint& endpoint, RaftNode& node):
    acceptor_(io_service, endpoint),
    socket_(io_service),
{
    do_accept();
}


void RaftServer::do_accept()
{
    acceptor_.async_accept(socket_, 
        [this](boost::system::error_code ec)
        {
            if (!ec)
            {
                (node_).handle_connection(std::move(socket_));
            }
            do_accept();
        });
}