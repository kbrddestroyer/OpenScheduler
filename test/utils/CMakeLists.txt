project (OpenScheduler.tests.utils)

list_all_tests("test_*.cpp" TARGET GTest::gtest GTest::gtest_main)
target_include_directories(${TARGET} PUBLIC ${CMAKE_HOME_DIRECTORY}/libs)
target_include_directories(${TARGET} PUBLIC ${CMAKE_HOME_DIRECTORY}/libs/utils)
