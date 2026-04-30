add_library(file file.cpp)
target_include_directories(file
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

add_library(command command.cpp)
target_include_directories(command
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

add_library(statement statement.cpp)
target_include_directories(statement
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)
