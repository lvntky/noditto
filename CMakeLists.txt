cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    noditto
    VERSION 0.1.0
    DESCRIPTION "AST Based Code Duplication Finder"
    HOMEPAGE_URL "https://leventkaya.dev"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    noditto_lib OBJECT
    source/lexer.cpp
    source/file_util.cpp
    source/tostring.cpp
)

target_include_directories(
    noditto_lib ${warning_guard}
    PUBLIC
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/noditto>"
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source>"
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/source/util>"
)

target_compile_features(noditto_lib PUBLIC cxx_std_17)

find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)

target_link_libraries(noditto_lib PRIVATE fmt::fmt spdlog::spdlog)

# ---- Declare executable ----

add_executable(noditto_elf source/main.cpp)
add_executable(noditto::elf ALIAS noditto_elf)

set_property(TARGET noditto_elf PROPERTY OUTPUT_NAME noditto)

target_compile_features(noditto_elf PRIVATE cxx_std_17)

target_link_libraries(noditto_elf PRIVATE noditto_lib)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT noditto_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of noditto"
  )
endif()