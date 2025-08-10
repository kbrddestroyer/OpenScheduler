project (OpenScheduler.tests.database)

set(CMAKE_CXX_STANDARD 17)
find_package(GTest REQUIRED)
enable_testing()

list_all_tests("integration_*.cpp" GTest::gtest GTest::gtest_main database)
include_directories(${CMAKE_HOME_DIRECTORY}/libs)
include_directories(${CMAKE_HOME_DIRECTORY}/libs/database)
