cmake_minimum_required(VERSION 3.5.0)
project(tillen VERSION 0.1.0 LANGUAGES C CXX)

include_directories(glad/include)

file(GLOB SOURCES *.h *.cpp)
add_executable(${PROJECT_NAME} ${SOURCES} glad/src/glad.c)

add_subdirectory(glfw)
target_link_libraries(${PROJECT_NAME} glfw)

