cmake_minimum_required(VERSION 3.9)
project(CORRIDOR)

# set variables
set(CMAKE_BUILD_TYPE "Release")
set(CGAL_DIR "$ENV{HOME}/CGAL-5.5.1")

 message("${CGAL_DIR}")

# find packages
find_package(CGAL REQUIRED)
find_package (Eigen3 REQUIRED NO_MODULE)
find_package(Boost 1.45.0 COMPONENTS filesystem)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 


add_executable(corridor_generator main.cpp)
file(GLOB GEOMETRY_SRC_FILES geometry/*.cpp)
add_library(geometry ${GEOMETRY_SRC_FILES})
target_include_directories(geometry PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/geometry)
target_link_libraries(geometry PUBLIC CGAL::CGAL)
target_link_libraries(geometry PUBLIC Eigen3::Eigen)

target_link_libraries(corridor_generator Eigen3::Eigen)
target_link_libraries(corridor_generator CGAL::CGAL)
target_link_libraries(corridor_generator geometry)

if (Boost_FOUND)
    target_link_libraries(corridor_generator ${Boost_LIBRARIES})
endif()