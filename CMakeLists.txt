cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(DataStructures)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# add the executable
add_executable(LinkedListTest test/linked_list_test.cpp)
add_executable(LinkedListInsertionTest test/linked_list_insertion_test.cpp)
add_executable(LinkedListDeletionTest test/linked_list_deletion_test.cpp)
add_executable(StackTest test/stack_test.cpp)
add_executable(StackBracketBalancer src/stack_bracket_balancer.cpp)
add_executable(QueueTest test/queue_test.cpp)

target_link_libraries(LinkedListTest gtest_main)
target_link_libraries(LinkedListInsertionTest gtest_main)
target_link_libraries(LinkedListDeletionTest gtest_main)
target_link_libraries(StackTest gtest_main)
target_link_libraries(StackBracketBalancer gtest_main)
target_link_libraries(QueueTest gtest_main)
