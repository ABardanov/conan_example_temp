cmake_minimum_required(VERSION 3.15)
project(etl_project CXX)

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/conanfile.txt)
    message(FATAL_ERROR Need conanfile.txt)
endif()

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/build/conanbuildinfo.cmake)
    message(STATUS Installing conan config)
    execute_process(
        COMMAND 
            conan install 
                -if ${CMAKE_CURRENT_SOURCE_DIR}/build 
                ${CMAKE_CURRENT_SOURCE_DIR} 
                --build=missing
    )
endif()

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/build/conan_toolchain.cmake) 
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/build/)
set(CMAKE_BUILD_TYPE Release)

find_package(etl)

add_executable(${PROJECT_NAME} 
    main.cpp
)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC
        etl
)