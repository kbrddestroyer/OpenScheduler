project (OpenScheduler.tests)

set(CMAKE_CXX_STANDARD 17)
find_package(GTest REQUIRED)
enable_testing()

add_all_subdirs()
