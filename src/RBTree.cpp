//
// Created by liyangling on 7/8/20.
//
#include <RBTree.hpp>

using namespace std;

RBTree::RBTree(const vector<int> &values) {
    for (auto val: values)
        insert(val);
}

shared_ptr<TreeNode> RBTree::find(int value) {
    shared_ptr<TreeNode> curr_node = root_node;
    while (curr_node != nullptr) {
        if (value == curr_node->value)
            return curr_node;
        if (value > curr_node->value)
            curr_node = curr_node->right_node;
        else
            curr_node = curr_node->left_node;
    }
    return nullptr;
}

shared_ptr<TreeNode> &get_ref(shared_ptr<TreeNode> &node) {
    return node;
}

bool RBTree::insert(int value) {
    if (root_node == nullptr) {
        root_node = make_shared<TreeNode>(TreeNode(value, BLACK));
        return true;
    }
    auto curr_node = root_node, parent_node = curr_node->parent;
    while (curr_node != nullptr) {
        parent_node = curr_node;
        shared_ptr<TreeNode> &insert_pos = value < curr_node->value ? curr_node->left_node : curr_node->right_node;
        curr_node = insert_pos;
        if (insert_pos == nullptr) {
            auto new_node = make_shared<TreeNode>(TreeNode(value, RED, parent_node));
            insert_pos = new_node;
            insert_fix(insert_pos);
        }
    }
    return true;
}

bool RBTree::remove(int value) {
    return false;
}

void RBTree::left_rotate(shared_ptr<TreeNode> &node) {

}

void RBTree::right_rotate(shared_ptr<TreeNode> &node) {

}

shared_ptr<TreeNode> RBTree::get_root() {
    return root_node;
}

void RBTree::insert_fix(shared_ptr<TreeNode>) {

}

void RBTree::delete_fix(shared_ptr<TreeNode>) {

}
