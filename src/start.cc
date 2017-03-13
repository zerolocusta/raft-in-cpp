#include "raft/raft_server.h"
#include <iostream>

int main(int argc, char *argv[])
{
    try
    {
        boost::asio::io_service io_service;
        boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), DEFAUTL_PORT);
        raft::RaftServer raftServer(io_service, endpoint);
        io_service.run();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}
