cmake_minimum_required(VERSION 3.6)

project(
  subarch-select
  VERSION 0.3.0
  LANGUAGES CXX)

find_package(CpuFeatures 0.7.0 QUIET)
if (NOT CpuFeatures_FOUND)
set(BUILD_TESTING OFF)
add_subdirectory("cpu_features")
add_library(CpuFeatures::cpu_features ALIAS cpu_features)
else ()
  set_target_properties(CpuFeatures::cpu_features PROPERTIES IMPORTED_GLOBAL TRUE)
  add_library(cpu_features ALIAS CpuFeatures::cpu_features)
  get_target_property(
    CpuFeatures_INCLUDE_DIR
    CpuFeatures::cpu_features
    INTERFACE_INCLUDE_DIRECTORIES)
endif ()

add_executable(subarch-select main.cpp)
target_link_libraries(subarch-select cpu_features)
