add_library(file file.cpp)
target_include_directories(file
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

add_library(page page.cpp)
target_include_directories(page
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)
