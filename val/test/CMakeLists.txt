# val_test
add_executable(val_test)

target_sources(val_test
  PRIVATE value_test.cc
)

target_link_libraries(val_test
  PRIVATE val_core cctest_main cctest
)

add_test(NAME val_test COMMAND val_test)