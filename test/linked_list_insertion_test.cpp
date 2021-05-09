
#include "gtest/gtest.h"
#include "../src/linked_list_insertion.cpp"

// The fixture for testing class Foo.
class LinkedListInsertionTest : public ::testing::Test {
 protected:
  LinkedListInsertion ll;
};

TEST_F(LinkedListInsertionTest, InsertionAtPosition) {
    ll.InsertAtPosition(0, new Node(10));
    EXPECT_EQ ("[ 10 ]", ll.Stringify());
    ll.InsertAtPosition(0, new Node(20));
    EXPECT_EQ ("[ 10 -> 20 ]", ll.Stringify());    
    ll.InsertAtPosition(1, new Node(30));
    EXPECT_EQ ("[ 10 -> 20 -> 30 ]", ll.Stringify());    
    ll.InsertAtPosition(1, new Node(25));
    EXPECT_EQ ("[ 10 -> 20 -> 25 -> 30 ]", ll.Stringify());    
    ll.Insert(new Node(0));
    EXPECT_EQ ("[ 0 -> 10 -> 20 -> 25 -> 30 ]", ll.Stringify());    
}

TEST_F(LinkedListInsertionTest, InsertionAtPositionWithValidations) {
    ll.InsertAtPosition(-1, new Node(10));
    EXPECT_EQ ("[]", ll.Stringify());
    ll.InsertAtPosition(0, new Node(10));
    ll.InsertAtPosition(1, new Node(20));
    EXPECT_EQ ("[ 10 ]", ll.Stringify());
}

TEST_F(LinkedListInsertionTest, InsertionAfter) {
    Node *firstNode = new Node(10);
    ll.Insert(firstNode);
    ll.InsertAfter(firstNode, new Node(20));
    EXPECT_EQ ("[ 10 -> 20 ]", ll.Stringify());
    ll.InsertAfter(firstNode, new Node(30));
    EXPECT_EQ ("[ 10 -> 30 -> 20 ]", ll.Stringify());
}

TEST_F(LinkedListInsertionTest, InsertionAtNode) {
    Node *firstNode = new Node(10);
    ll.Insert(firstNode);
    ll.InsertAtNode(10, new Node(20));
    EXPECT_EQ ("[ 10 -> 20 ]", ll.Stringify());
    ll.InsertAtNode(10, new Node(30));
    EXPECT_EQ ("[ 10 -> 30 -> 20 ]", ll.Stringify());
}

TEST_F(LinkedListInsertionTest, InsertionAtTail) {
    ll.InsertAtTail(new Node(10));
    EXPECT_EQ ("[ 10 ]", ll.Stringify());
    ll.InsertAtTail(new Node(20));
    EXPECT_EQ ("[ 10 -> 20 ]", ll.Stringify());
    ll.InsertAtTail(new Node(30));
    EXPECT_EQ ("[ 10 -> 20 -> 30 ]", ll.Stringify());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}