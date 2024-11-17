cmake_minimum_required(VERSION 3.5.0)
project(amazing-maze VERSION 0.1.0 LANGUAGES C CXX)

cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)



include_directories(${CMAKE_SOURCE_DIR}/includes)


configure_file(configuration/root_directory.h.in configuration/root_directory.h)
include_directories(${CMAKE_BINARY_DIR}/configuration)


# copy shader files to build directory
file(GLOB SHADERS
"src/shaders/*.vs"
"src/shaders/*.fs"
"src/shaders/*.tcs"
"src/shaders/*.tes"
"src/shaders/*.gs"
"src/shaders/*.cs"
)
foreach(SHADER ${SHADERS})
file(COPY ${SHADER} DESTINATION ${CMAKE_SOURCE_DIR}/bin)
endforeach(SHADER)

add_executable(amazing-maze src/main.cpp src/glad.c src/stb_image.cpp ${SHADERS} src/VAO.cpp src/VBO.cpp src/EBO.cpp src/Texture.cpp)

target_link_libraries(amazing-maze glfw OpenGL::GL)