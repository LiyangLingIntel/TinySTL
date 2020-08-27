//
// Created by liyangling on 7/8/20.
//
#include <iomanip>
#include <iostream>
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
        curr_node = (value > curr_node->value) ? curr_node->right_node : curr_node->left_node;
    }
    return nullptr;
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
    auto tgt_node = find(value);
    if (tgt_node == nullptr)
        return false;

    remove_fix(tgt_node);
    return true;
}

shared_ptr<TreeNode> &RBTree::get_ref(shared_ptr<TreeNode> &node) {
    if (!node->parent)
        return root_node;
    if (node == node->parent->left_node)
        return node->parent->left_node;
    else
        return node->parent->right_node;
}

// TODO use one rotate function instead of left & right rotate
void RBTree::left_rotate(shared_ptr<TreeNode> &node) {
    auto parent = node->parent;
    auto left_node = node->left_node;
    auto parent_pos = get_ref(parent);

    node->parent = parent->parent;
    node->left_node = parent;
    parent->parent = node;
    parent->right_node = left_node;
    if (left_node)
        left_node->parent = parent;
    parent_pos = node;
}

void RBTree::right_rotate(shared_ptr<TreeNode> &node) {
    auto parent = node->parent;
    auto right_node = node->right_node;
    auto parent_pos = get_ref(parent);

    node->parent = parent->parent;
    node->right_node = parent;
    parent->parent = node;
    parent->left_node = right_node;
    if (right_node)
        right_node->parent = parent;
    parent_pos = node;
}

shared_ptr<TreeNode> RBTree::get_root() {
    return root_node;
}

void RBTree::insert_fix(shared_ptr<TreeNode> &node) {

}

void RBTree::remove_fix(shared_ptr<TreeNode> &node) {

}

void RBTree::print(const shared_ptr<TreeNode> &node, int node_count) {
    auto curr_node = (node == nullptr) ? root_node : node;
    cout.flags(ios::right);
    if (curr_node != nullptr) {
        auto clr = (curr_node->color) ? 'B' : 'R';
        cout << "(" << clr << "," << setw(3) << curr_node->value << ")";

        if (curr_node->right_node != nullptr) {
            cout << " - ";
            print(curr_node->right_node, node_count + 1);
        }
        if (curr_node->left_node != nullptr) {
            cout << "\n";
            for (int i = 0; i < (7 + 10 * node_count); i++)
                cout << " ";
            cout << " \\ \n";
            for (int i = 0; i < (7 + 10 * node_count); i++)
                cout << " ";
            cout << "   ";
            print(curr_node->left_node, node_count + 1);
        }
    }
}
