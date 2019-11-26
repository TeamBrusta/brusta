cmake_minimum_required(VERSION 3.10)
project(BrustaCPlusPlus)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(includes)

find_package(Torch REQUIRED)
find_package(jsoncpp CONFIG REQUIRED)
find_package(Threads)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_subdirectory(bridge)
add_subdirectory(src)