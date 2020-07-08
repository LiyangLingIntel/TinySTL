//
// Created by liyangling on 7/8/20.
//

#include <RBTree.hpp>

RBTree::RBTree(const std::vector<int> &values) {
    for (auto val : values)
        insert(val);
}

std::shared_ptr<TreeNode> RBTree::find(int value) {
    auto curr_node = root_node;
    while (curr_node != nullptr) {
        if (value == curr_node->value)
            return curr_node;
        else if (value > curr_node->value)
            curr_node = curr_node->right_child;
        else
            curr_node = curr_node->left_child;
    }
    return curr_node;
}

bool RBTree::insert(int value) {
    auto new_node = TreeNode(value, BLACK);
    auto insert_node = std::make_shared<TreeNode>(new_node);

    if (root_node == nullptr) {
        root_node = insert_node;
    }
    auto parent = root_node;
    auto current = parent;

    while (current->value != value) { // assume there is no same value in this tree
        if (value < parent->value) {
            current = parent->left_child;
            if (current == nullptr) {
                current = insert_node;
                current->parent = parent;
            } else {
                parent = current;
            }
        } else { // value > parent->value
            current = parent->right_child;
            if (current == nullptr) {
                current = insert_node;
                current->parent = parent;
            } else {
                parent = current;
            }
        }
    }
    // TODO: rotate and coloring

}

bool RBTree::remove(int value) {}
