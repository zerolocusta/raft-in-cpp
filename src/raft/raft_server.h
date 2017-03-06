#ifndef RAFT_IN_CPP_RAFT_SERVER_H
#define RAFT_IN_CPP_RAFT_SERVER_H

#include "raft.h"
#include "raft_log.h"
#include "raft_node.h"
#include <memory>
#include <boost/asio.hpp>


using boost::asio::ip::tcp;

class RaftServer
{

public:
    explicit RaftServer(boost::asio::io_service&,
                        const tcp::endpoint&);
    ~RaftServer();

    void do_accept();


private:
    RaftNode node_;
    tcp::acceptor acceptor_;
    tcp::socket socket_;
};

#endif // RAFT_IN_CPP_RAFT_SERVER_H