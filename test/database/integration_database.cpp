#include <gtest/gtest.h>
#include <Database.hpp>
#include <Backend.hpp>

#include "TestDao.hpp"


TEST(INTEGRATION_DATABASE, MYSQL_BASIC_TEST) {
    Database::Backend backend;
    Database::Host host = {
        "localhost:3306",
        "root",
        "root",
        "unit_tests"
    };

    ASSERT_TRUE(backend.connect(host));

    Database::DAOBase * dao = backend.getByID<uint32_t, TestDAO>("unit_test", "id", 0);
    TestDAO * testDao = dynamic_cast<TestDAO*>(dao);
    ASSERT_TRUE(testDao);
    ASSERT_STREQ("name", testDao->getName().c_str());
}