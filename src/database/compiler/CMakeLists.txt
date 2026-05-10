add_library(tokenizer tokenizer.cpp)
target_include_directories(tokenizer PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(tokenizer PUBLIC helpers)
