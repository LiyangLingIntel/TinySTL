//
// Created by liyangling on 7/8/20.
//

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <RBTree.hpp>

class RBTreeInsertTest : public ::testing::Test {

};


// sample of insertion

TEST_F(/*test suit name*/ RBTreeInsertTest, /*test case name*/ InsertNullTree
) {
    RBTree rbtree({5, 7, 8, 3, 2, 6, 4});
    rbtree.print();
// ASSERT_EQ(6, insert(36));
// ASSERT_EQ(true, find(76));
}
