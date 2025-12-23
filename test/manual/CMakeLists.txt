project(OpenScheduler.Testing.Manual LANGUAGES C CXX)

list_all_sources(MANUALTESTS_SRC)
add_executable(
        ManualTestTool ${MANUALTESTS_SRC}
)
target_link_libraries(
        ManualTestTool PUBLIC login
)

add_custom_command(TARGET ManualTestTool POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy -t $<TARGET_FILE_DIR:ManualTestTool> $<TARGET_RUNTIME_DLLS:ManualTestTool>
        COMMAND_EXPAND_LISTS
)
