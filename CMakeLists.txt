cmake_minimum_required(VERSION 2.8)

project(VideoProcess)

#SET(LDFLAGS "-std=c++11 -msse4.1 -fPIC -O3 -ggdb -Wall -finline-functions -Wl,--allow-multiple-#definition -Wl,--no-whole-archive")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LDFLAGS}")

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")


# Add Subdirectory
#add_subdirectory(src)

#######################OPENCV#############
FIND_PACKAGE(OpenCV REQUIRED)


#######################FFMPEG#############
include_directories(/home/sen/projects/VideoProcess/src)
#include_directories("/usr/bin/")
link_directories(/usr/lib/)

add_compile_options(-fPIC)
add_compile_options(-std=c++11)
add_compile_options(-g)

INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

add_executable(VideoProcess src/main.cpp src/ffmpegDecode.cpp)

target_link_libraries(VideoProcess ${OpenCV_LIBS} avutil avcodec avformat swscale swresample)
