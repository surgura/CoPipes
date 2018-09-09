cmake_minimum_required(VERSION 3.10.1)

set(CMAKE_CXX_STANDARD 17)

# set include as include directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/test)

# create executables
add_executable(test1 test/test1.cpp)

# add boost
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_SILENCE_CXX17_ALLOCATOR_VOID_DEPRECATION_WARNING")
set (Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system date_time regex fiber)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(test1 ${Boost_LIBRARIES})
else()
    message(FATAL_ERROR "Cannot find Boost. Please install or provide BOOST_ROOT as argument. Try setting Boost_DEBUG=ON")
endif()

IF (WIN32)
    add_definitions(-D_WIN32_WINNT=0x0501)
ENDIF()