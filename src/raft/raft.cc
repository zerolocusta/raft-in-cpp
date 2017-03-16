#include "raft.h"
#include <random>

namespace raft
{
std::string genRandomStr(const int len)
{
    static const std::string alphanum =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string rand_str;
    for (int i = 0; i < len; ++i)
    {
        rand_str += alphanum[rand() % (alphanum.size() - 1)];
    }
    return rand_str;
}

int genRandomHeartBeatTime()
{
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(MAX_HEARTBEAT_TIMEOUT / 2, MAX_HEARTBEAT_TIMEOUT);
    return dist6(rng);
}
}