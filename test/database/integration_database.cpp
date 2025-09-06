#include <gtest/gtest.h>
#include <Database.hpp>
#include "TestDao.hpp"


TEST(INTEGRATION_DATABASE, MYSQL_BASIC_TEST) {
    auto backend = Utils::Singleton<Database::Backend>::instance();
    Database::Host host = {
        "localhost:3306",
        "root",
        "root",
        "unit_tests"
    };

    ASSERT_TRUE(backend->connect(host));
    const auto result = Database::QueryProcessor<TestDAO>::select("unit_test");
    ASSERT_GT(result.size(), 0);
}


TEST(INTEGRATION_DATABASE, MYSQL_SELECT_BY_PRIMARY) {
    auto backend = Utils::Singleton<Database::Backend>::instance();
    Database::Host host = {
        "localhost:3306",
        "root",
        "root",
        "unit_tests"
    };

    ASSERT_TRUE(backend->connect(host));

    const auto dao = Database::QueryProcessor<TestDAO>::selectByPK<int>("unit_test", "id", 0);
    ASSERT_TRUE(dao.get());
    ASSERT_STREQ("name", dao->getName().c_str());
}
