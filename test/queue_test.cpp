
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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}