cmake_minimum_required(VERSION 3.16)
project(OpenScheduler.Client LANGUAGES CXX)

include(qt.cmake)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 6.5 COMPONENTS Quick REQUIRED)

find_package(Qt${QT_VERSION_MAJOR}
        COMPONENTS
        Core
        Gui
        Widgets
)

# For QTQuick support
qt_standard_project_setup(REQUIRES 6.5)

list_all_sources(PROJECT_SOURCES)

qt_add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
set_target_properties(${PROJECT_NAME}
        PROPERTIES
        WIN32_EXECUTABLE TRUE
)
target_link_libraries(${PROJECT_NAME}
        PUBLIC
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        login
        config
)
target_include_directories(
        ${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_HOME_DIRECTORY}/resources" "${CMAKE_CURRENT_BINARY_DIR}/resources"
        COMMENT "Copy resources folder near binary"
)
