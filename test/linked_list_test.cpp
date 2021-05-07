
#include "gtest/gtest.h"
#include "../src/linked_list.cpp"

// The fixture for testing class Foo.
class LinkedListTest : public ::testing::Test {
 protected:
  LinkedList ll;
};


TEST_F(LinkedListTest, IsEmpty) {
    EXPECT_EQ (true, ll.IsEmpty());
    EXPECT_EQ ("[]", ll.Stringify());
}

TEST_F(LinkedListTest, Insertion) {
    ll.Insert(new Node(10));
    EXPECT_EQ (false, ll.IsEmpty());
    EXPECT_EQ ("[ 10 ]", ll.Stringify());
}

TEST_F(LinkedListTest, Removal) {
    ll.Remove();
    EXPECT_EQ (true, ll.IsEmpty());
    EXPECT_EQ ("[]", ll.Stringify());
    ll.Insert(new Node(10));
    ll.Remove();
    EXPECT_EQ ("[]", ll.Stringify());
    EXPECT_EQ (true, ll.IsEmpty());
    ll.Insert(new Node(10));
    ll.Insert(new Node(20));
    ll.Remove();
    EXPECT_EQ ("[ 10 ]", ll.Stringify());
    EXPECT_EQ (false, ll.IsEmpty());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}