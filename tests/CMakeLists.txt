# This CMakeLists.txt defines the tests used to test arcsec

# Define the project that holds all the tests
project ("arcsec-tests")
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set (
    TEST_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/vec-arithmetic.cpp" # Test for basic lhs arithmetric
    "${CMAKE_CURRENT_SOURCE_DIR}/vec-mag.cpp" # Test arc::magnitude and arc::magnitude2
)

# We iterate over TEST_FILES to create executables for each test
# These executables are then executed by the CTest framework
foreach (TEST_FILE ${TEST_FILES})
    message (STATUS "Build test file -> ${TEST_FILE}")
    get_filename_component (TEST_EXE ${TEST_FILE} NAME_WE)
    message (STATUS "Test file without extension -> ${TEST_EXE}")
    set (TEST_EXE "test-${TEST_EXE}")
    message (STATUS "Test file name -> ${TEST_EXE}")
    add_executable (${TEST_EXE} ${TEST_FILE})

    # Link to arcsec
    target_link_libraries (${TEST_EXE} PRIVATE arcsec)
    add_compile_definitions("__NEON__")

    # Add test
    add_test(NAME ${TEST_EXE} COMMAND ${TEST_EXE})
endforeach ()
