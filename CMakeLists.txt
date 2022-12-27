cmake_minimum_required(VERSION 3.15)
project(etl_project CXX)


if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/conanfile.txt)
    message(FATAL_ERROR Need conanfile.txt)
endif()

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake)
    message(STATUS Installing conan config)
    execute_process(COMMAND conan install -if ${CMAKE_CURRENT_SOURCE_DIR}/build ${CMAKE_CURRENT_SOURCE_DIR})
endif()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})