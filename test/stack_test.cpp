#include "gtest/gtest.h"
#include "../src/stack.cpp"

// The fixture for testing class Foo.
class StackTest : public ::testing::Test {
 protected:
  Stack stack;
};

TEST_F(StackTest, IsEmpty) {
    EXPECT_EQ (true, stack.IsEmpty());
    EXPECT_EQ ("[]", stack.Stringify());
}

TEST_F(StackTest, Push) {
    stack.Push(10);
    EXPECT_EQ (false, stack.IsEmpty());
    EXPECT_EQ ("[ 10 ]", stack.Stringify());
    stack.Push(20);
    EXPECT_EQ ("[ 20 10 ]", stack.Stringify());
    stack.Push(30);
    stack.Push(40);
    EXPECT_EQ ("[ 40 30 20 10 ]", stack.Stringify());
    stack.Push(50);
    stack.Push(60);
    stack.Push(70);
    stack.Push(80);
    stack.Push(90);
    stack.Push(100);
    stack.Push(110);
    EXPECT_EQ ("[ 100 90 80 70 60 50 40 30 20 10 ]", stack.Stringify());
}

TEST_F(StackTest, Pop) {
    stack.Pop();
    EXPECT_EQ (true, stack.IsEmpty());
    EXPECT_EQ ("[]", stack.Stringify());
    stack.Push(10);
    stack.Pop();
    EXPECT_EQ ("[]", stack.Stringify());
    EXPECT_EQ (true, stack.IsEmpty());
    stack.Push(10);
    stack.Push(20);
    stack.Pop();
    EXPECT_EQ ("[ 10 ]", stack.Stringify());
    EXPECT_EQ (false, stack.IsEmpty());
}