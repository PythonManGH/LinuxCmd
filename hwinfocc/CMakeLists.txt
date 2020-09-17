cmake_minimum_required(VERSION 3.7)

project(hwinfocc)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Find the library
find_package(PkgConfig REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(DtkWidget REQUIRED)

#添加第三方库
link_libraries("hd")

#Include all third
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rdparty)

file(GLOB_RECURSE DEVICE_SRC ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)
file(GLOB_RECURSE THIRD_PARTY ${CMAKE_CURRENT_LIST_DIR}/3rdparty/*.c)
add_executable(${PROJECT_NAME} ${DEVICE_SRC} ${THIRD_PARTY} resources.qrc)

target_include_directories(hwinfocc PUBLIC ${DtkWidget_INCLUDE_DIRS} ${OBJECT_BINARY_DIR})
target_link_libraries(hwinfocc
    ${DtkWidget_LIBRARIES}
    ${Qt5Widgets_LIBRARIES}
)
