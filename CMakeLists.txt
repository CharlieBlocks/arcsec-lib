# This is the root CMakeLists.txt file for the arcsec library
# Arcsec is a 3D maths library for use in 3D applications (such as game engins)
# This cmake file configures the header library as well as adding the include directories
#
# To use this library in a cmake project
# Simply add the subdirectory
# and then include the library
#
#   add_subdirectory (arcsec-lib)
#   target_link_libraries (<project> INTERFACE arcsec)


# Set minimum required version
cmake_minimum_required (VERSION 3.29)


# Create project
project("arcsec-lib")


# The arcsec project uses defines to specify which intrinsic functions it employs
# These options are:
#   -DENABLE_SSE2
#   -DENABLE_AVX2
#   -DENABLE_AVX512
#   -DENABLE_NEON
#
# Using the value of CMAKE_SYSTEM_PROCESSOR suitable defaults are set
if ("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "arm64")
    message (STATUS "[arcsec-lib] Setting default options for arm64 architecture")
    option (ENABLE_SSE2 "Are SSE2 compiler extensions enabled" OFF)
    option (ENABLE_AVX2 "Are AVX2 compiler extensions enabled" OFF)
    option (ENABLE_AVX512 "Are AVX512 compiler extensions enabled" OFF)
    option (ENABLE_NEON "Are Arm-Neon compiler extensions enabled" ON)
else () # Assume other architectures are x64. Potentially update later
    message (STATUS "[arcsec-lib] Setting default options for x64 architecture")
    option (ENABLE_SSE2 "Are SSE2 compiler extensions enabled" ON)
    option (ENABLE_AVX2 "Are AVX2 compiler extensions enabled" ON)
    option (ENABLE_AVX512 "Are AVX512 compiler extensions enabled" OFF)
    option (ENABLE_NEON "Are Arm-Neon compiler extensions enabled" OFF)
endif ()


set (
    INCLUDE_FILES

    # Include
    "include/vectors.h"
    "include/intrinsics.h"

    # Include/Ops
    "include/ops/vops.h"
    "include/ops/selectors/operation_selector.h"

    # Include/Ops/Vectors
    "include/ops/vectors/generic_ops.h"
    "include/ops/vectors/vector_generic.h"
    "include/ops/vectors/vector_vectorised.h"

    # Include/Vectors
    "include/vectors/vector.h"
    "include/vectors/vector2.h"

    # Include/Vfn
    "include/vfn/vmag.h"
    "include/vfn/vnorm.h"
    "include/vfn/vdot.h"
    "include/vfn/vcross.h"
)

# Here we create an empty interface library
# The library has no source files to build but does expose
# and include directory
add_library(arcsec INTERFACE)
target_include_directories(arcsec INTERFACE include) # Add `include` directory
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_STANDARD_REQUIRED ON)

# The corresponding compile definitions are now set
# Some of these may be set by the compiler (MSVC does I think)
# But they are set here to ensure compiler agnostics
if (ENABLE_SSE2)
    add_compile_definitions(__SSE2__)
endif ()
if (ENABLE_AVX2)
    add_compile_definitions(__AVX2__)
endif ()
if (ENABLE_AVX512)
    add_compile_definitions(__AVX512__)
endif ()
if (ENABLE_NEON)
    add_compile_definitions(__NEON__)
endif ()


# Add testing files
include (CTest)
enable_testing ()
add_subdirectory (tests)
