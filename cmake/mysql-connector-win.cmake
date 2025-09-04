# CMake script to find MySQL Connector C++ on Windows systems
# on Windows system please provide MYSQL_CONNECTOR_DIRECTORY to MySQL Connector C++
# and MYSQL_SERVER

if (WIN32)
    # Debug MySQL Connector
    # assuming that MYSQL_CONNECTOR_DIRECTORY is leading to debug library

    set (MYSQL_LIB_PATH ${MYSQL_CONNECTOR_DIRECTORY}\\lib64\\vs14)
    set (MYSQL_DLL_PATH ${MYSQL_CONNECTOR_DIRECTORY}\\lib64)

    set (MYSQL_INCLUDE_ROOT ${MYSQL_CONNECTOR_DIRECTORY}\\include)

    if (${CMAKE_BUILD_TYPE} STREQUAL Debug)
        # For some reason regular connector c++ is not working with Debug configuration.
        # We need special Debug build
        set (MYSQL_LIB_PATH ${MYSQL_LIB_PATH}\\debug)
        set (MYSQL_DLL_PATH ${MYSQL_DLL_PATH}\\debug)
    endif()
else()
    # TODO:
    # Create Linux config
    # or port this garbage to find_package instruction
endif()

set (MYSQL_LIB_PATH ${MYSQL_LIB_PATH} PARENT_SCOPE)
set (MYSQL_DLL_PATH ${MYSQL_DLL_PATH} PARENT_SCOPE)
set (MYSQL_INCLUDE_ROOT ${MYSQL_INCLUDE_ROOT} PARENT_SCOPE)
