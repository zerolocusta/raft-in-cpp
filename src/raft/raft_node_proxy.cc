#include <functional>
#include "raft.h"
#include "raft_node_proxy.h"

namespace raft
{
RaftNodeProxy::RaftNodeProxy(raftServerPtr_t server_ptr, const std::string &myname, boost::asio::io_service &io_service)
    : name(myname), server_ptr(server_ptr), io_service_(io_service),
      voted(false), next_index(0), match_index(0), timer_(boost::asio::deadline_timer(io_service))
{
}

void RaftNodeProxy::setTimerFromNow(boost::posix_time::milliseconds deadline, std::function<void()> timeout_handler)
{
    timer_.expires_from_now(deadline);
    timer_.async_wait(timeout_handler);
}

void RaftNodeProxy::setHeartBeatTimer()
{
    setTimerFromNow(boost::posix_time::milliseconds(genRandomHeartBeatTime()), [this]{this->sendHeartBeat();});
}

} // namespace raft