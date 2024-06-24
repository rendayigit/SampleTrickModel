cmake_minimum_required(VERSION 3.22)

project(tests LANGUAGES CXX)

# Enable coverage
if(${ENABLE_COVERAGE})
  message("#################### Coverage Enabled ####################")
  set(GCOV_LINK_FLAGS "--coverage -O0 -g -fprofile-arcs -ftest-coverage")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCOV_LINK_FLAGS}")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCOV_LINK_FLAGS}")
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set target directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin/)

# Include SourceFiles.cmake to access the SOURCEFILES and INCLUDEDIRS variables
include(${CMAKE_SOURCE_DIR}/SourceFiles.cmake)

add_executable(tests
    ${SOURCEFILES}
)

target_include_directories(tests PUBLIC
    ${INCLUDEDIRS}
)

target_link_libraries(tests PRIVATE 
    gtest_main
    gtest
)

include(GoogleTest)
gtest_discover_tests(tests)