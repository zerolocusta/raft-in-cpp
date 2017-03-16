//
// Created by 陈达 on 2017/3/16.
//

#include "gtest/gtest.h"
#include "raft/raft_message.h"


using namespace raft;

void testingPackedMessage(const std::string &str)
{
    PackedMessage pm(str);
    auto be32 = htobe32(str.size());

    // testing the size of PackedMessage.size() equal to str.size() + sizeof(uint32_t)
    ASSERT_EQ(pm.size(),str.size() + sizeof(uint32_t));
    ASSERT_EQ(std::memcmp(pm.data() + sizeof(uint32_t), str.data(), str.size()), 0);
    ASSERT_EQ(std::memcmp(pm.data(), &be32, sizeof(be32)), 0);
}


TEST(raft_message_test, test_packed_message){
    std::string str_123("123");
    std::string str_empty;
    testingPackedMessage(str_123);
    testingPackedMessage(str_empty);
}

