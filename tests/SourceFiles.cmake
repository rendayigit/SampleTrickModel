set(SOURCEFILES
    # Model Source Files
    ${CMAKE_SOURCE_DIR}/../models/math/math.cpp
    ${CMAKE_SOURCE_DIR}/../models/modelDummy/modelDummy.cpp
    # Mock Files
    ${CMAKE_SOURCE_DIR}/mocks/exec_proto/mock_exec_proto.cpp
    # Unit Test Files
    ${CMAKE_SOURCE_DIR}/models/math/test_math.cpp
    ${CMAKE_SOURCE_DIR}/models/modelX/test_modelDummy.cpp
)

set(INCLUDEDIRS
    # Trick Header File Dirs
    $ENV{TRICK_HOME}/include/
    $ENV{TRICK_HOME}/include/trick/
    $ENV{TRICK_HOME}/include/trick/compat/
    # Model Header File Dirs
    ${CMAKE_SOURCE_DIR}/../models/
    ${CMAKE_SOURCE_DIR}/../models/math/
    ${CMAKE_SOURCE_DIR}/../models/modelDummy/
)