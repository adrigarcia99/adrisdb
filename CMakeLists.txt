cmake_minimum_required(VERSION 3.10.0)
project(adrisdb VERSION 0.1.0 LANGUAGES C CXX)

add_executable(adrisdb src/main.cpp)

add_subdirectory(src/database)
add_subdirectory(src/database/util)
add_subdirectory(src/database/storage)

target_include_directories(adrisdb PUBLIC src/database src/database/util src/database/storage)
target_link_libraries(adrisdb PUBLIC database file page command statement helpers)

include(CTest)
enable_testing()
