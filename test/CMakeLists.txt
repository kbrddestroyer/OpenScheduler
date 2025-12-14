project (OpenScheduler.tests)

if (${TESTING})
  find_package(GTest REQUIRED)
  enable_testing()
  
  add_all_subdirs()
endif()
