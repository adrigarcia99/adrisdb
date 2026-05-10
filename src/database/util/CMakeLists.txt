add_library(command command.cpp)
target_include_directories(command PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(statement statement.cpp)
target_include_directories(statement PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(helpers helpers.cpp)
target_include_directories(helpers PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(statement PUBLIC file)
target_link_libraries(statement PUBLIC tokenizer)
