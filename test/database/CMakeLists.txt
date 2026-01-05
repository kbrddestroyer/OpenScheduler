project (OpenScheduler.tests.database)

if (DBTEST_ENABLED)
    list_all_tests("integration_*.cpp" TARGET database)
    target_include_directories(${TARGET} PUBLIC ${CMAKE_HOME_DIRECTORY}/libs)
    target_include_directories(${TARGET} PUBLIC ${CMAKE_HOME_DIRECTORY}/libs/database)
endif()
