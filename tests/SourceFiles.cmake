set(SOURCEFILES
    # Model Source Files
    ${CMAKE_SOURCE_DIR}/../models/modelX/ModelX.cpp
    ${CMAKE_SOURCE_DIR}/../models/modelY/ModelY.cpp
    # Mock Files
    ${CMAKE_SOURCE_DIR}/mocks/exec_proto/mock_exec_proto.cpp
    # Unit Test Files
    ${CMAKE_SOURCE_DIR}/models/modelX/test_modelX.cpp
)

set(INCLUDEDIRS
    # Trick Header File Dirs
    $ENV{TRICK_HOME}/include/
    $ENV{TRICK_HOME}/include/trick/
    $ENV{TRICK_HOME}/include/trick/compat/
    # Model Header File Dirs
    ${CMAKE_SOURCE_DIR}/../models/
    ${CMAKE_SOURCE_DIR}/../models/modelX/
)