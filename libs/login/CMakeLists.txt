project (OpenScheduler.libs.login LANGUAGES C CXX)

find_package(OpenSSL REQUIRED)

list_all_sources(LIBLOGIN_SOURCES)
add_library(login STATIC ${LIBLOGIN_SOURCES})

target_link_libraries(login openssl::openssl database)
target_compile_definitions(
        login
        PUBLIC
        STATIC
)