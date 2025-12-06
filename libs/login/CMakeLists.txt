project (OpenScheduler.libs.login LANGUAGES C CXX)

find_package(OpenSSL REQUIRED)

utils_add_library(login STATIC)
target_link_libraries(login openssl::openssl database)
