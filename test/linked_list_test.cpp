
#include "gtest/gtest.h"
#include "../src/linked_list.cpp"

// The fixture for testing class Foo.
class LinkedListTest : public ::testing::Test {
 protected:
  LinkedList ll;
};


TEST_F(LinkedListTest, IsEmpty) { 
    EXPECT_EQ (true, ll.IsEmpty());
}

TEST_F(LinkedListTest, Insertion) {
    ll.Insert(new Node(10));
    EXPECT_EQ (false, ll.IsEmpty());    
}

TEST_F(LinkedListTest, Removal) {
    ll.Remove();
    EXPECT_EQ (true, ll.IsEmpty());
    ll.Insert(new Node(10));
    ll.Remove();
    EXPECT_EQ (true, ll.IsEmpty());
    ll.Insert(new Node(10));
    ll.Insert(new Node(20));
    ll.Remove();
    EXPECT_EQ (false, ll.IsEmpty());
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}