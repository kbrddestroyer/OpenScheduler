project(AccountRegistrator LANGUAGES C CXX)

list_all_sources(SOURCES)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE login config)
target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${CMAKE_HOME_DIRECTORY}/client/config
)

add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_HOME_DIRECTORY}/resources" "${CMAKE_CURRENT_BINARY_DIR}/resources"
        COMMENT "Copy resources folder near binary"
)
