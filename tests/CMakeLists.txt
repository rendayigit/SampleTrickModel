cmake_minimum_required(VERSION 3.22)

project(tests LANGUAGES C CXX)

# Enable coverage
if(${ENABLE_COVERAGE})
  message("#################### Coverage Enabled ####################")
  set(GCOV_LINK_FLAGS "--coverage -O0 -g")
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

# Find the udunits2 library
find_library(UDUNITS2_LIB udunits2)
find_path(UDUNITS2_INCLUDE udunits2.h)

add_executable(tests
    ${SOURCEFILES}
)

target_include_directories(tests PUBLIC
    ${INCLUDEDIRS}
    ${UDUNITS2_INCLUDE}
)

target_link_libraries(tests PRIVATE 
    gtest_main
    gtest
    $ENV{TRICK_HOME}/lib/liber7_utils.a
    $ENV{TRICK_HOME}/lib/libtrick.a
    $ENV{TRICK_HOME}/lib/libtrick_comm.a
    $ENV{TRICK_HOME}/lib/libtrick_connection_handlers.a
    $ENV{TRICK_HOME}/lib/libtrick_math.a
    $ENV{TRICK_HOME}/lib/libtrick_mm.a
    $ENV{TRICK_HOME}/lib/libtrick_pyip.a
    $ENV{TRICK_HOME}/lib/libtrick_units.a
    $ENV{TRICK_HOME}/lib/libtrick_var_binary_parser.a
    $ENV{TRICK_HOME}/trick_source/data_products/DPX/lib_Linux_11.4_x86_64/libDPC.a
    $ENV{TRICK_HOME}/trick_source/data_products/DPX/lib_Linux_11.4_x86_64/libDPM.a
    $ENV{TRICK_HOME}/trick_source/data_products/DPX/lib_Linux_11.4_x86_64/libDPV.a
    $ENV{TRICK_HOME}/trick_source/data_products/lib_Linux_11.4_x86_64/libeqparse.a
    $ENV{TRICK_HOME}/trick_source/data_products/lib_Linux_11.4_x86_64/liblog.a
    $ENV{TRICK_HOME}/trick_source/data_products/lib_Linux_11.4_x86_64/libtrick_units.a
    $ENV{TRICK_HOME}/trick_source/data_products/lib_Linux_11.4_x86_64/libvar.a
    ${UDUNITS2_LIB}
    # TRICK OBJECT FILES
    $ENV{TRICK_HOME}/trick_source/trick_utils/trick_adt/object_Linux_11.4_x86_64/bubble_sort.o
    $ENV{TRICK_HOME}/trick_source/trick_utils/trick_adt/object_Linux_11.4_x86_64/dllist.o
    $ENV{TRICK_HOME}/trick_source/sim_services/CheckPointAgent/object_Linux_11.4_x86_64/CheckPointAgent.o
    $ENV{TRICK_HOME}/trick_source/sim_services/CheckPointAgent/object_Linux_11.4_x86_64/ClassicCheckPointerAgent.o
    $ENV{TRICK_HOME}/trick_source/sim_services/EventManager/object_Linux_11.4_x86_64/EventManager.o
    $ENV{TRICK_HOME}/trick_source/sim_services/EventManager/object_Linux_11.4_x86_64/EventInstrument.o
    $ENV{TRICK_HOME}/trick_source/sim_services/EventManager/object_Linux_11.4_x86_64/EventProcessor.o
    $ENV{TRICK_HOME}/trick_source/sim_services/EventManager/object_Linux_11.4_x86_64/EventManager_c_intf.o
    $ENV{TRICK_HOME}/trick_source/sim_services/VariableServer/object_Linux_11.4_x86_64/var_server_ext.o
    $ENV{TRICK_HOME}/trick_source/sim_services/VariableServer/object_Linux_11.4_x86_64/VariableServerSession_write_stdio.o
    $ENV{TRICK_HOME}/trick_source/sim_services/VariableServer/object_Linux_11.4_x86_64/VariableServer_open_additional_servers.o
    $ENV{TRICK_HOME}/trick_source/sim_services/VariableServer/object_Linux_11.4_x86_64/VariableServer_get_next_freeze_call_time.o
    $ENV{TRICK_HOME}/trick_source/sim_services/VariableServer/object_Linux_11.4_x86_64/VariableServer_get_next_sync_call_time.o
    $ENV{TRICK_HOME}/trick_source/sim_services/CheckPointAgent/object_Linux_11.4_x86_64/ChkPtParseContext.o
    $ENV{TRICK_HOME}/trick_source/sim_services/CheckPointAgent/object_Linux_11.4_x86_64/input_parser.lex.o
    $ENV{TRICK_HOME}/trick_source/sim_services/CheckPointAgent/object_Linux_11.4_x86_64/input_parser.tab.o
)

include(GoogleTest)
gtest_discover_tests(tests)