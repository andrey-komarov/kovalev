cmake_minimum_required (VERSION 2.6)

project (segment_intersection)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

set(CMAKE_BUILD_TYPE Release)

add_executable (test1 test1.cpp)
add_custom_command (
    OUTPUT Test2.class 
    COMMAND javac Test2.java -d ${EXECUTABLE_OUTPUT_PATH}
    DEPENDS Test2.java
    )
add_custom_target (Test2 ALL DEPENDS Test2.class)
add_executable (sample sample.cpp)
