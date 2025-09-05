#include <gtest/gtest.h>
#include <../../include/Singleton.hpp>


class TestSingleton final : public Utils::Singleton<TestSingleton> {};


TEST(TEST_SINGLETON, TEST_SINGLETON) {
    ASSERT_TRUE(Utils::Singleton<TestSingleton>::instance());
}

