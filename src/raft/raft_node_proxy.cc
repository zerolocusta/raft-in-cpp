#include "raft_node_proxy.h"

namespace raft
{

void RaftNodeProxy::setTimerFromNow(boost::posix_time::milliseconds deadline, timeout_handler_t timeout_handler)
{
    timer_.expires_from_now(deadline);
    timer_.async_wait(timeout_handler);
}

void RaftNodeProxy::setHeartBeatTimer()
{
    setTimerFromNow(boost::posix_time::milliseconds(genRandomHeartBeatTime()), [this](const boost::system::error_code &ec) { this->sendHeartBeat(); });
}
}