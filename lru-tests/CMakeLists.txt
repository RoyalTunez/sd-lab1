cmake_minimum_required (VERSION 3.8)

include_directories(
	../lru-src
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests ListTest.cpp LruCacheTest.cpp)

target_link_libraries(tests gtest_main)