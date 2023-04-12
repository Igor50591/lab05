cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" ON)

project(lab05)

find_package(GTest CONFIG REQUIRED)

add_library(lab05lib STATIC
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Account.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sources/Transaction.cpp)

target_include_directories(lab05lib PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  "$<INSTALL_INTERFACE:include>"
)

if(BUILD_TESTS)
add_executable(tests
	${CMAKE_CURRENT_SOURCE_DIR}/tests/accountTest.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/tests/transactionTest.cpp)
target_link_libraries(tests lab05lib GTest::gtest_main)

enable_testing()
add_test(NAME unit_tests COMMAND tests)
endif()

