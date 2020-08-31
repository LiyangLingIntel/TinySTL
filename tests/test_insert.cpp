//
// Created by liyangling on 7/8/20.
//

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <RBTree.hpp>

class RBTreeInsertTest : public ::testing::Test {

};

class RBTreeRemoveTest : public ::testing::Test {

};



TEST_F(/*test suit name*/ RBTreeInsertTest, /*test case name*/ InsertTree) {
    RBTree rbtree({5, 7, 8, 6, 3, 2, 36, 4, 17});
    rbtree.print();
    ASSERT_NE(rbtree.find(36), nullptr);
    ASSERT_NE(rbtree.find(6), nullptr);
    ASSERT_NE(rbtree.find(17), nullptr);
}

TEST_F(/*test suit name*/ RBTreeInsertTest, /*test case name*/ InsertNullTree) {
    RBTree rbtree;
    rbtree.print();
    ASSERT_EQ(rbtree.find(36), nullptr);
    ASSERT_EQ(rbtree.find(6), nullptr);
    ASSERT_EQ(rbtree.find(17), nullptr);
}

TEST_F(/*test suit name*/ RBTreeRemoveTest, /*test case name*/ RemoveNode) {
    RBTree rbtree({5, 7, 8, 6, 3, 2, 36, 4, 17});
    rbtree.print();
    ASSERT_EQ(rbtree.remove(36), true);
    ASSERT_EQ(rbtree.remove(2), true);
    ASSERT_EQ(rbtree.remove(5), true);
    ASSERT_EQ(rbtree.remove(999), false);
    rbtree.print();
}
