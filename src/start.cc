#include "raft/raft_server.h"
#include <iostream>

int main(int argc, char *argv[])
{
    try
    {
        boost::asio::io_service io_service;
        boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), raft::DEFAUTL_PORT);
        raft::RaftServer raftServer(io_service, endpoint, raft::genRandomStr(raft::RANDOM_STR_LEN));
        io_service.run();
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}
