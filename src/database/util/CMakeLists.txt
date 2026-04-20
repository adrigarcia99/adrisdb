add_library(bytebuffer byte_buffer.cpp)
target_include_directories(bytebuffer
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)
