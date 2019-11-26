include_directories(includes)

add_library(bridge SHARED ./src/bridge.cpp ./src/model/${MODEL_TYPE}.cpp)
target_link_libraries(bridge "${TORCH_LIBRARIES}")
