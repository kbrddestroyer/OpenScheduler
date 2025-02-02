# Client core sources
cmake_minimum_required(VERSION 3.16)

project(OpenSchedulerClient LANGUAGES CXX)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
        Core
        Gui
        Widgets
)

set(PROJECT_SOURCES
    main.cpp
    OpenScheduler.ui
    OpenScheduler.h
    OpenScheduler.cpp
)

qt_add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

if (WIN32)
    set_target_properties(${PROJECT_NAME}
        PROPERTIES
            WIN32_EXECUTABLE TRUE
    )
endif()

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
