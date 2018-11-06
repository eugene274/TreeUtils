cmake_minimum_required(VERSION 3.12)
project(tree_utils)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_library(TreeUtils SHARED src/IterableTree.cxx src/TreeIterator.cxx)

install(
        TARGETS TreeUtils
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include/TreeUtils
)


if (${CMAKE_BUILD_TYPE} MATCHES Debug)
    enable_testing()

    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

    add_executable(tests test/TestRunner.cxx)
    target_link_libraries(tests TreeUtils gtest)

    add_test(
            NAME TestTreeUtils
            COMMAND tests
    )
endif () # CMAKE_BUILD_TYPE