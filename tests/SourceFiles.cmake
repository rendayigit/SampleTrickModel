set(SOURCEFILES
    # Model Source Files
    ${CMAKE_SOURCE_DIR}/../models/ModelX.cpp
    # Mock Files
    ${CMAKE_SOURCE_DIR}/mocks/exec_proto/mock_exec_proto.cpp
    # Unit Test Files
    ${CMAKE_SOURCE_DIR}/test_modelX.cpp
)

set(INCLUDEDIRS
    # Trick Header File Dirs
    $ENV{TRICK_HOME}/include/
    $ENV{TRICK_HOME}/include/trick/
    $ENV{TRICK_HOME}/include/trick/compat/
    # Model Header File Dirs
    ${CMAKE_SOURCE_DIR}/../models/
)