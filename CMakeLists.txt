CMAKE_MINIMUM_REQUIRED(VERSION 3.5.0)
PROJECT(HS16 LANGUAGES CXX)

SET(THREADS_PREFER_PTHREAD_FLAG ON)
FIND_PACKAGE(Threads REQUIRED)

SET(CMAKE_CXX_COMPILER "scorep-g++")
SET(CMAKE_CXX_FLAGS "-std=c++14")

ADD_EXECUTABLE(auto auto/auto.cpp auto/test_func.cpp)

ADD_EXECUTABLE(simple_fileio fileio/simple_fileio.cpp)

ADD_EXECUTABLE(simple_thread threads/simple_thread.cpp)
TARGET_LINK_LIBRARIES(simple_thread Threads::Threads)

ADD_EXECUTABLE(folding_sum folding_expressions/sum.cpp)

ADD_EXECUTABLE(vector_mul vector_mul/vector_mul.cpp)
