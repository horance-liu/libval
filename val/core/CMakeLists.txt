# val
add_library(val_core SHARED)

file(GLOB all_srcs 
  *.cc
  *.cpp  
)

target_sources(val_core
  PRIVATE ${all_srcs}
)

target_include_directories(val_core
  PUBLIC ${VAL_HOME}
)

target_compile_features(val_core
  PUBLIC cxx_std_14
)
