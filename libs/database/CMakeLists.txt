project (OpenScheduler.libs.database)

list_all_sources(SOURCES)
add_library(database STATIC ${SOURCES})

if (WIN32 OR WIN64)
    target_include_directories(database PUBLIC ${MYSQL_CONNECTOR_DIRECTORY}/include)
    target_include_directories(database PUBLIC ${MYSQL_CONNECTOR_DIRECTORY}/include/jdbc)
    target_link_directories(database PUBLIC ${MYSQL_CONNECTOR_DIRECTORY}/lib64)
endif()

target_link_libraries(database PUBLIC mysql_database)

target_link_libraries(database PUBLIC libmysql)
target_include_directories(database PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
