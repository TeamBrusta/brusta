add_executable(brusta
		main.cpp
		handler.cpp predict.cpp)

target_link_libraries(brusta ${CMAKE_THREAD_LIBS_INIT} jsoncpp_lib ${TORCH_LIBRARIES} bridge)
