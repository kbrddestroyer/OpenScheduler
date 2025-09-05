function(add_all_subdirs)
    file(GLOB V_GLOB LIST_DIRECTORIES true "*")
    foreach(item ${V_GLOB})
        if(IS_DIRECTORY ${item})
            FILE(GLOB IS_CMAKE "${item}/CMakeLists.txt")
            if (IS_CMAKE)
                add_subdirectory(${item})
            endif()
        endif()
    endforeach()
endfunction()


function(list_all_sources result)
    file(GLOB_RECURSE SOURCES "*.c" "*.h" "*.cpp" "*.hpp")

    set (${result} ${SOURCES})
    return (PROPAGATE ${result})
endfunction()


function(list_all_tests name_pattern target_name_return)
    file (GLOB_RECURSE TEST_SOURCES ${name_pattern})
    get_filename_component(FOLDER ${CMAKE_CURRENT_SOURCE_DIR} NAME_WE)
    string (TOUPPER ${FOLDER} FOLDER)

    add_executable(TEST_${FOLDER}_TARGET ${TEST_SOURCES} "entry.cpp")
    add_test(NAME TEST_${FOLDER} COMMAND $<TARGET_FILE:TEST_${FOLDER}_TARGET>)
    target_link_libraries(TEST_${FOLDER}_TARGET PRIVATE ${ARGN})

    add_custom_command(TARGET TEST_${FOLDER}_TARGET POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy -t $<TARGET_FILE_DIR:TEST_${FOLDER}_TARGET> $<TARGET_RUNTIME_DLLS:TEST_${FOLDER}_TARGET>
            COMMAND_EXPAND_LISTS
    )

    message ("Loaded test folder: TEST_${FOLDER}")

    set (${target_name_return} TEST_${FOLDER}_TARGET)
    return (PROPAGATE ${target_name_return})
endfunction()
