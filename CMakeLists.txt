cmake_minimum_required(VERSION 3.21)
project(Project1 VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread -g -rdynamic -std=c++1z -DGLEW_STATIC -DNDEBUG -w")

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/imgui
)

FILE(GLOB imgui_srcs ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/imgui/*)
add_library(
    ${PROJECT_NAME}
    SHARED
    
    # Sources
    ${CMAKE_CURRENT_SOURCE_DIR}/core/app.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core/car_preview.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core/track_session.cpp    
    ${CMAKE_CURRENT_SOURCE_DIR}/core/image.cpp    



    # GUI
    ${imgui_srcs}
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/imgui/backends/imgui_impl_glfw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/imgui/backends/imgui_impl_opengl2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/imgui/misc/cpp/imgui_stdlib.cpp
)

target_link_libraries(${PROJECT_NAME}
    glfw
    OpenGL::GL
    GLEW::GLEW
    dl
)
if(NOT APPLE)
    target_link_libraries(${PROJECT_NAME} stdc++fs)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
add_executable(project_1 core/main.cpp)
target_link_libraries(project_1 ${PROJECT_NAME})