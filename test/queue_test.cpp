
#include "gtest/gtest.h"
#include "../src/queue.cpp"

// The fixture for testing class Foo.
class QueueTest : public ::testing::Test {
 protected:
  Queue queue;
};


TEST_F(QueueTest, IsEmpty) {
    EXPECT_EQ (true, queue.IsEmpty());
    EXPECT_EQ ("[]", queue.Stringify());
}

TEST_F(QueueTest, Enqueue) {
    queue.Enqueue(new Node(10));
    EXPECT_EQ (false, queue.IsEmpty());
    EXPECT_EQ ("[ 10 ]", queue.Stringify());
    queue.Enqueue(new Node(20));
    EXPECT_EQ ("[ 10 -> 20 ]", queue.Stringify());
    queue.Enqueue(new Node(30));
    queue.Enqueue(new Node(40));
    EXPECT_EQ ("[ 10 -> 20 -> 30 -> 40 ]", queue.Stringify());
}

TEST_F(QueueTest, Dequeue) {
    queue.Dequeue();
    EXPECT_EQ (true, queue.IsEmpty());
    EXPECT_EQ ("[]", queue.Stringify());
    queue.Enqueue(new Node(10));
    queue.Dequeue();
    EXPECT_EQ (true, queue.IsEmpty());
    EXPECT_EQ ("[]", queue.Stringify());
    queue.Enqueue(new Node(10));
    queue.Enqueue(new Node(20));
    queue.Enqueue(new Node(30));
    queue.Dequeue();
    EXPECT_EQ ("[ 20 -> 30 ]", queue.Stringify());
    queue.Enqueue(new Node(40));
    queue.Enqueue(new Node(50));
    queue.Dequeue();
    queue.Dequeue();
    EXPECT_EQ ("[ 40 -> 50 ]", queue.Stringify());
    queue.Enqueue(new Node(60));
    queue.Dequeue();
    queue.Dequeue();
    queue.Dequeue();
    queue.Dequeue();
    EXPECT_EQ (true, queue.IsEmpty());
    EXPECT_EQ ("[]", queue.Stringify());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}