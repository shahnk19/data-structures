
#include "gtest/gtest.h"
#include "../src/linked_list_deletion.cpp"

// The fixture for testing class Foo.
class LinkedListDeletionTest : public ::testing::Test {
 protected:
  LinkedListDeletion ll;
};

TEST_F(LinkedListDeletionTest, RemoveAtPosition) {
    ll.RemoveAtPosition(0);
    EXPECT_EQ ("[]", ll.Stringify());
    ll.RemoveAtPosition(2);
    EXPECT_EQ ("[]", ll.Stringify());
    ll.RemoveAtPosition(-1);
    EXPECT_EQ ("[]", ll.Stringify());
    ll.Insert(new Node(10));
    ll.RemoveAtPosition(0);
    EXPECT_EQ ("[]", ll.Stringify());    
    ll.Insert(new Node(20));
    ll.Insert(new Node(10));
    ll.RemoveAtPosition(0);
    EXPECT_EQ ("[ 20 ]", ll.Stringify());
    ll.Insert(new Node(10));
    ll.RemoveAtPosition(1);
    EXPECT_EQ ("[ 10 ]", ll.Stringify());
    ll.Insert(new Node(20));
    ll.Insert(new Node(30));
    ll.RemoveAtPosition(1);
    EXPECT_EQ ("[ 30 -> 10 ]", ll.Stringify());
}

TEST_F(LinkedListDeletionTest, RemoveAtNode) {
    ll.RemoveAtNode(10);
    EXPECT_EQ ("[]", ll.Stringify());
    ll.Insert(new Node(10));
    ll.RemoveAtNode(10);
    EXPECT_EQ ("[]", ll.Stringify());
    ll.Insert(new Node(20));
    ll.Insert(new Node(10));
    ll.RemoveAtNode(10);
    EXPECT_EQ ("[ 20 ]", ll.Stringify());
    ll.Insert(new Node(10));
    ll.Insert(new Node(5));
    ll.RemoveAtNode(5);
    EXPECT_EQ ("[ 10 -> 20 ]", ll.Stringify());
    ll.Insert(new Node(1));
    ll.RemoveAtNode(10);
    EXPECT_EQ ("[ 1 -> 20 ]", ll.Stringify());
    ll.Insert(new Node(2));
    ll.RemoveAtNode(20);
    EXPECT_EQ ("[ 2 -> 1 ]", ll.Stringify());
}

TEST_F(LinkedListDeletionTest, RemoveAtTail) {
    ll.RemoveAtTail();
    EXPECT_EQ ("[]", ll.Stringify());
    ll.Insert(new Node(10));
    ll.RemoveAtTail();
    EXPECT_EQ ("[]", ll.Stringify());
    ll.Insert(new Node(20));
    ll.Insert(new Node(10));
    ll.RemoveAtTail();
    EXPECT_EQ ("[ 10 ]", ll.Stringify());
    ll.Insert(new Node(5));
    ll.Insert(new Node(1));
    ll.RemoveAtTail();
    EXPECT_EQ ("[ 1 -> 5 ]", ll.Stringify());
    ll.Insert(new Node(0));
    ll.RemoveAtTail();
    EXPECT_EQ ("[ 0 -> 1 ]", ll.Stringify());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}