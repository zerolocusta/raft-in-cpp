#ifndef RAFT_IN_CPP_RAFT_H
#define RAFT_IN_CPP_RAFT_H
#include <utility>
#include "../protobuf/raft_msg.pb.h"

/** compatibility header for endian.h
 * This is a simple compatibility shim to convert
 * BSD/Linux endian macros to the Mac OS X equivalents.
 * It is public domain.
 * */

#ifdef __APPLE__
#include <libkern/OSByteOrder.h>

#define htobe16(x) OSSwapHostToBigInt16(x)
#define htole16(x) OSSwapHostToLittleInt16(x)
#define be16toh(x) OSSwapBigToHostInt16(x)
#define le16toh(x) OSSwapLittleToHostInt16(x)

#define htobe32(x) OSSwapHostToBigInt32(x)
#define htole32(x) OSSwapHostToLittleInt32(x)
#define be32toh(x) OSSwapBigToHostInt32(x)
#define le32toh(x) OSSwapLittleToHostInt32(x)

#define htobe64(x) OSSwapHostToBigInt64(x)
#define htole64(x) OSSwapHostToLittleInt64(x)
#define be64toh(x) OSSwapBigToHostInt64(x)
#define le64toh(x) OSSwapLittleToHostInt64(x)

#endif /* __APPLE__ */
namespace raft
{
typedef std::string key_t;
typedef std::string value_t;
typedef std::pair<key_t, value_t> entry_t;

typedef raft_msg::KVEntry *KVEntryRawPtr_t;
typedef raft_msg::LogEntry *LogEntryRawPtr_t;
typedef std::shared_ptr<raft_msg::RaftMessage> RaftMessageSharedPtr_t;

enum
{
    MAX_HEARTBEAT_TIMEOUT = 300,
    ELECTION_TIMEOUT = 1000,
    RANDOM_STR_LEN = 40,
    DEFAUTL_PORT = 7970,
    MESSAGE_HEADER_LEN = sizeof(uint32_t),
    MESSAGE_MAX_SIZE = UINT32_MAX
};

enum RAFT_STATE
{
    RAFT_STATE_FOLLOWER,
    RAFT_STATE_CANDIDATE,
    RAFT_STATE_LEADER
};

int genRandomHeartBeatTime();
std::string genRandomStr(const int len);
}

#endif // RAFT_IN_CPP_RAFR_H