cmake_minimum_required(VERSION 3.0.0)
project(hilbertcurve)

include(CTest)
enable_testing()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -O")

include_directories(inc)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR lib/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS audio graphics network system window)

add_executable(hilbertcurve src/main.cpp src/utility.cpp)

target_link_libraries(hilbertcurve sfml-audio sfml-graphics sfml-network sfml-system sfml-window)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
