#ifndef TESTCONFIG_HPP
#define TESTCONFIG_HPP

#include <config/Config.hpp>
#include <gtest/gtest.h>


class TestConfig : public Config::Config {
    FRIEND_TEST(TEST_CONFIG, TEST_CONFIG_GENERAL);

public:
    TestConfig() = delete;
    explicit TestConfig(std::string filename) : Config(std::move(filename)) {}

protected:
    void onValuesObtained(const std::map<std::string, std::string> & result) override {
        VALUE1 = result.at("VALUE1");
        VALUE2 = std::stoi( result.at("VALUE2") );
        VALUE3 = std::stof( result.at("VALUE3") );
    }

private:
    std::string VALUE1;
    uint8_t     VALUE2;
    float       VALUE3;
};

#endif //TESTCONFIG_HPP
