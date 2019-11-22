include_directories(include ../includes)

find_package(jsoncpp CONFIG REQUIRED)
find_package(Threads)
add_executable(brusta
		main.cpp
		handler.cpp predict.cpp)

target_link_libraries(brusta ${CMAKE_THREAD_LIBS_INIT} jsoncpp_lib)
