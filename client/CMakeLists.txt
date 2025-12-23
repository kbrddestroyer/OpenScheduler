cmake_minimum_required(VERSION 3.16)
project(OpenScheduler.Client LANGUAGES CXX)

include(qt.cmake)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR}
        COMPONENTS
        Core
        Gui
        Widgets
)
qt_standard_project_setup()

list_all_sources(PROJECT_SOURCES)

qt_add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        WIN32_EXECUTABLE TRUE
)

target_link_libraries(${PROJECT_NAME}
        PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Widgets
        login
)

