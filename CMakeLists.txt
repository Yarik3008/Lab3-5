cmake_minimum_required(VERSION 2.8...3.13) 
set (CMAKE_CXX_STANDARD 20)

set(PROJECT_NAME cpplabs) 
project(${PROJECT_NAME})

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release) 
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(gtest)
add_subdirectory(stack)
add_subdirectory(queue)
add_subdirectory(postfix)
add_subdirectory(polinom)
