

add_executable (v4add "${CMAKE_CURRENT_SOURCE_DIR}/v4-add.cpp")

set_property (TARGET v4add PROPERTY CMAKE_CXX_STANDARD 17)
set_property (TARGET v4add PROPERTY CMAKE_CXX_STAnDARD_REQUIRED ON)

target_link_libraries (v4add PRIVATE arcsec)

add_compile_options(v4add "-g" "--fno-ommit-frame-pointers")
