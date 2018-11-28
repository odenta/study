cmake_minimum_required(VERSION 3.10)

if(MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(study main.cpp)
target_compile_features(study PUBLIC cxx_std_11)
