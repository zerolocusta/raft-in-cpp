#include "raft_log.h"

namespace raft
{

RaftLog::RaftLog() : commit_index_(0),
                     current_term_(0),
                     last_applied_(0),
                     prev_log_index_(0),
                     prev_log_term_(0)
{
}

uint64_t RaftLog::getCommit_index() const
{
    return commit_index_;
}

void RaftLog::setCommit_index(uint64_t commit_index_)
{
    RaftLog::commit_index_ = commit_index_;
}

uint64_t RaftLog::getCurrent_term() const
{
    return current_term_;
}

void RaftLog::setCurrent_term(uint64_t current_term_)
{
    RaftLog::current_term_ = current_term_;
}

uint64_t RaftLog::getLast_applied() const
{
    return last_applied_;
}

void RaftLog::setLast_applied(uint64_t last_applied_)
{
    RaftLog::last_applied_ = last_applied_;
}

uint64_t RaftLog::getPrev_log_index() const
{
    return prev_log_index_;
}

void RaftLog::setPrev_log_index(uint64_t prev_log_index_)
{
    RaftLog::prev_log_index_ = prev_log_index_;
}

uint64_t RaftLog::getPrev_log_term() const
{
    return prev_log_term_;
}

void RaftLog::setPrev_log_term(uint64_t prev_log_term_)
{
    RaftLog::prev_log_term_ = prev_log_term_;
}

const std::vector<RaftLogEntry> &RaftLog::getLogs() const
{
    return logs_;
}

RaftLogEntry::RaftLogEntry(const uint64_t index, const uint64_t term, const raft_msg::CommandType command_type, const raft::entry_t &entry)
    : index_(index), term_(term), command_type_(command_type), entry_(entry)
{
}

uint64_t RaftLogEntry::getIndex() const
{
    return index_;
}

uint64_t RaftLogEntry::getTerm() const
{
    return term_;
}

const raft_msg::CommandType RaftLogEntry::getCommand_type() const
{
    return command_type_;
}

const entry_t &RaftLogEntry::getEntry() const
{
    return entry_;
}

} // namespace raft
