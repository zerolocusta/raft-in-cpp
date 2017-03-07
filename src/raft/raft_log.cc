#include "raft_log.h"







RaftLogEntry::RaftLogEntry(
                uint64_t term,
                uint64_t index,
                CommandType command_type,
                std::string command_key, 
                std::string connmad_value){}
