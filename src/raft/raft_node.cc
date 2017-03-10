#include "raft_node.h"
#include "raft.h"
namespace raft
{
RaftNode::RaftNode(const std::string &myname, boost::asio::io_service &io_service)
    : name(myname), state(raft::RAFT_STATE::RAFT_STATE_FOLLOWER),
      current_term(0), voted_count(0), voted(false),
      commit_index(0), last_applied(0), io_service_(io_service)
{
    setFollowerTimer();
}

void RaftNode::setTimerFromNow(const std::string &name, boost::posix_time::ptime deadline, std::function<void()> timeout_handler)
{
    auto dt_ptr = std::make_shared<boost::asio::deadline_timer>(io_service_);
    dt_ptr->expires_from_now(deadline);
    dt_ptr->asynv_wait(timeout_handler);
    timers[name] = dt_ptr;
    return;
}

void RaftNode::setFollowerTimer()
{
    setTimerFromNow(name, boost::posix_time::milliseconds(genRandomHeartBeatTime()),
                    becomeCandidate);
}

void RaftNode::setCandidateTimer()
{
    setTimerFromNow(name, boost::posix_time::milliseconds(ELECTION_TIMEOUT),
                    becomeCandidate);
}

} // namespace raft