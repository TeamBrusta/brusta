cmake_minimum_required(VERSION 3.15)
project(BrustaCPlusPlus)

set(CMAKE_CXX_STANDARD 17)
find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_executable(BrustaCPlusPlus main.cpp)
target_link_libraries(BrustaCPlusPlus "${TORCH_LIBRARIES}")
