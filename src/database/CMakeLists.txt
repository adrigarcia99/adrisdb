add_library(database database.cpp)
target_include_directories(database
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)
