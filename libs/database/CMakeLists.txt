project (OpenScheduler.libs.database)

set(CMAKE_CXX_STANDARD 17)

include (${CMAKE_HOME_DIRECTORY}/cmake/build_utils.cmake)

list_all_sources(SOURCES)
add_library(database STATIC ${SOURCES})

if (WIN32 OR WIN64)
    target_include_directories(database PUBLIC ${MYSQL_CONNECTOR_DIRECTORY}/include)
    target_include_directories(database PUBLIC ${MYSQL_CONNECTOR_DIRECTORY}/include/jdbc)
    target_link_directories(database PUBLIC ${MYSQL_CONNECTOR_DIRECTORY}/lib64)
    target_link_directories(database PUBLIC ${MYSQL_CONNECTOR_DIRECTORY}/lib64/vs14)
    target_link_directories(database PUBLIC ${MYSQL_CONNECTOR_DIRECTORY}/lib64/vs14/debug)
endif()

target_compile_definitions(database PUBLIC -DCPPCONN_PUBLIC_FUNC=)
target_link_libraries(database PUBLIC
        mysqlcppconn
)
target_include_directories(database PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
