project (database.backends.mysql)

list_all_sources(SOURCES)
add_library(mysql_backend STATIC ${SOURCES})
