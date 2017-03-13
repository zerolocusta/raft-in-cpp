#include <functional>
#include "raft.h"
#include "raft_node_proxy.h"

namespace raft
{
RaftNodeProxy::RaftNodeProxy(raftServerPtr_t server_ptr, const std::string &myname, boost::asio::io_service &io_service)
    : name(myname), server_ptr(server_ptr), io_service_(io_service),
      voted(false), next_index(0), match_index(0)
{
}

void RaftNodeProxy::setTimerFromNow(boost::posix_time::ptime deadline, std::function<void()> timeout_handler)
{
    timer = boost::asio::deadline_timer(io_service_);
    timer.expires_from_now(deadline);
    timer.asynv_wait(timeout_handler);
}

void RaftNodeProxy::setHeartBeatTimer()
{
    setTimerFromNow(boost::posix_time::milliseconds(genRandomHeartBeatTime()), this->sendHeartBeat);
}

} // namespace raft