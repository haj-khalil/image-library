cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-sanitize=undefined")

project(myapp)

include(/home/hugo/Documents/vcpkg/scripts/buildsystems/vcpkg.cmake)

find_package(OpenCV REQUIRED)
find_package(Matplot++ CONFIG REQUIRED)

add_executable(myapp main.cpp Image.cpp)

target_link_libraries(Matplot++::matplot)

target_include_directories(myapp PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(myapp PRIVATE ${OpenCV_LIBS} Matplot++::cimg Matplot++::matplot)
