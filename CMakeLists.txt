cmake_minimum_required(VERSION 3.14)

project(val CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB all_srcs 
  val/*.cc
)

file(GLOB all_tests 
  val/*_test.cc
)

list(REMOVE_ITEM all_srcs ${all_tests})

# val
add_library(val SHARED)

target_sources(val
  PRIVATE ${all_srcs}
)

target_include_directories(val
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}
)

target_compile_features(val 
  PUBLIC cxx_std_14
)

# val_test
add_executable(val_test)

target_sources(val_test
  PRIVATE val/value_test.cc
)

target_link_libraries(val_test
  PRIVATE val cctest cctest_main
)

add_test(NAME val_test COMMAND val_test)