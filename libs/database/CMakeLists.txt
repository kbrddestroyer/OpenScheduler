project (OpenScheduler.libs.database)

set(CMAKE_CXX_STANDARD 17)

include (${CMAKE_HOME_DIRECTORY}/cmake/build_utils.cmake)
include (${CMAKE_HOME_DIRECTORY}/cmake/mysql-connector-win.cmake)

list_all_sources(SOURCES)
add_library(database STATIC ${SOURCES})

message ("MySQL ROOT: ")
message (${MYSQL_INCLUDE_ROOT})
message (${MYSQL_LIB_PATH})

target_include_directories(database PUBLIC ${MYSQL_INCLUDE_ROOT})
target_include_directories(database PUBLIC ${MYSQL_INCLUDE_ROOT}/jdbc)
target_include_directories(database PUBLIC ${MYSQL_INCLUDE_ROOT}/mysql)
target_link_directories(database PUBLIC ${MYSQL_LIB_PATH})
target_link_libraries(database PUBLIC mysqlcppconn)
target_include_directories(database PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
