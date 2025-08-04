project (OpenScheduler.tests.database)

find_package(GTest REQUIRED)
enable_testing()

list_all_tests("test_*.cpp" GTest::gtest GTest::gtest_main)
