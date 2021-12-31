cmake_minimum_required(VERSION 3.11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(GustoScript)

find_package(OpenGL REQUIRED)

add_executable(gs
    src/main.cpp
    src/file.cpp
    src/lexer.cpp
    src/parser.cpp
)

target_include_directories(gs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(gs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (UNIX)
target_link_libraries(gs PUBLIC ${CMAKE_DL_LIBS})
endif (UNIX)

if (WIN32)
target_link_options(gs PUBLIC -static-libgcc -static-libstdc++)
endif(WIN32)