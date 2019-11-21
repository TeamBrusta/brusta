include_directories(include ../includes)

find_package(jsoncpp CONFIG REQUIRED)
add_executable(BrustaCPlusPlus
		main.cpp
		handler.cpp predict.cpp)
target_link_libraries(BrustaCPlusPlus PRIVATE jsoncpp_lib)
