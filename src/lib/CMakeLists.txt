cmake_minimum_required(VERSION 3.17)
project(relay_serialize C)

set(CMAKE_C_STANDARD 99)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(isDebug TRUE)
else()
  message("no debug")
  set(isDebug FALSE)
endif()

if(isDebug)
  message("Debug build detected")
  add_compile_definitions(CONFIGURATION_DEBUG TYRAN_CONFIGURATION_DEBUG)
  set(CONFIGURATION_DEBUG 1)
endif()

set(DEPS ../../deps/)

file(GLOB lib_src FOLLOW_SYMLINKS "*.c")

add_library(relay_serialize STATIC ${lib_src})

target_compile_options(
  relay_serialize
  PRIVATE -Weverything -Werror -Wno-declaration-after-statement # bug in clang?
          -Wno-padded)

target_include_directories(relay_serialize PUBLIC ${DEPS}piot/clog/src/include)

target_include_directories(relay_serialize
                           PUBLIC ${DEPS}piot/tiny-libc/src/include)

target_include_directories(relay_serialize
                           PUBLIC ${DEPS}piot/imprint/src/include)

target_include_directories(relay_serialize
                           PUBLIC ${DEPS}piot/flood-c/src/include)

target_include_directories(relay_serialize PUBLIC ../include)
