//
// Created by liyangling on 7/8/20.
//
#include <rbtree.hpp>

RBTree::RBTree() noexcept { root_node = nullptr; }

std::shared_ptr <TreeNode> RBTree::find(int value) {
    std::shared_ptr <TreeNode> curr_node = root_node;
    while (curr_node != nullptr) {
        if (value == curr_node->value)
            return curr_node;
        else if (value > curr_node->value)
            curr_node = curr_node->right_node;
        else
            curr_node = curr_node->left_node;
    }
    return nullptr;
}