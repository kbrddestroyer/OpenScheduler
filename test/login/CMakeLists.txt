project (OpenScheduler.tests.login)

list_all_tests("test_*.cpp" TARGET GTest::gtest GTest::gtest_main login)
target_include_directories(${TARGET} PUBLIC ${CMAKE_HOME_DIRECTORY}/libs)
target_include_directories(${TARGET} PUBLIC ${CMAKE_HOME_DIRECTORY}/libs/database)
