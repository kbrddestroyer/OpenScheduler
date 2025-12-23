#include <gtest/gtest.h>
#include <Logger/Logger.hpp>


TEST(TEST_LOGGER, TEST_LOGGER_GENERAL) {
    Logger::Logger logger{};
    logger << "Hello World!";
}