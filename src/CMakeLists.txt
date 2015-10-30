cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(main.cpp)

set(OpenCV_DIR /nfs/site/disks/lmg_output_database_01/crjoshi/opencvBin)
find_package(OpenCV PATHS ${OpenCV_DIR} REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} )

add_executable(main k_for_kmeans.cpp main.cpp )
target_link_libraries(main ${OpenCV_LIBS} )



