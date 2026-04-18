cmake_minimum_required(VERSION 3.10.0)
project(adrisdb VERSION 0.1.0 LANGUAGES C CXX)

add_executable(adrisdb src/main.cpp)

add_subdirectory(include/database)
add_subdirectory(external/glfw)

target_include_directories(adrisdb PUBLIC include/database external/glfw/include)
target_link_libraries(adrisdb PUBLIC database glfw)

include(CTest)
enable_testing()

