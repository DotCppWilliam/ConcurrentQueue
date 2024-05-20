cmake_minimum_required(VERSION 3.2)
project(ConQueue)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

aux_source_directory(. CONQUEUE_SOURCES)
set(CONQUEUE_DIRS ${CMAKE_CURRENT_LIST_DIR})

# 编译为静态库
add_library(${PROJECT_NAME} STATIC ${CONQUEUE_SOURCES})
target_include_directories(ConQueue PUBLIC ${CONQUEUE_DIRS})


# 编译为动态态库
# add_library(${PROJECT_NAME} SHARED ${CONQUEUE_SOURCES})
# target_include_directories(ConQueue PUBLIC ${CONQUEUE_DIRS})

# 增加测试文件
add_executable(test test.cpp)
target_link_libraries(test PRIVATE ConQueue)