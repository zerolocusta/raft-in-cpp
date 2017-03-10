#include "raft.h"
#include <random>

namespace raft
{
int genRandomHeartBeatTime()
{
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(MAX_HEARTBEAT_TIMEOUT / 2, MAX_HEARTBEAT_TIMEOUT);
    return dist6(rng);
}
}