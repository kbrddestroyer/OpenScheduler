#include <gtest/gtest.h>
#include <config/Config.hpp>

#include "TestConfig.hpp"

TEST(TEST_CONFIG, TEST_CONFIG_GENERAL) {
    /*
     * General purpose test
     * Parsing, value obtainment, etc.
     */

    TestConfig config(R"(F:\Work\OpenScheduler\test\config\data\test_config.conf)");

    ASSERT_TRUE(config.prepare());
    ASSERT_TRUE(config.parse());

    ASSERT_TRUE(config.VALUE1 == "blah");
    ASSERT_EQ(config.VALUE2, 123);
    ASSERT_FLOAT_EQ(config.VALUE3, 123.45);
}
