cmake_minimum_required(VERSION 3.5)

project(TLOZ)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/extlibs/find/")
MESSAGE(${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED graphics window system)

file(GLOB_RECURSE INC_PRJ "include/*.hpp")
file(GLOB_RECURSE SRC_PRJ "src/*.cpp")

include_directories("include/")
include_directories(${SFML_INCLUDE_DIR})

add_executable(TLOZ	${INC_PRJ} ${SRC_PRJ})

if (SFML_FOUND)
  target_link_libraries(TLOZ ${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)

