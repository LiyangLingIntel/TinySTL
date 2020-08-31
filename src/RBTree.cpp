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

    shared_ptr<TreeNode> &tgt_slot = get_ref(tgt_node);
    if (tgt_node->left_node == nullptr && tgt_node->right_node == nullptr)
        tgt_slot = nullptr;
    else if (tgt_node->left_node == nullptr)
        tgt_slot = tgt_node->right_node;
    else if (tgt_node->right_node == nullptr)
        tgt_slot = tgt_node->left_node;
    else {
        auto left_max = get_max(tgt_node->left_node);
        left_max->parent->right_node = nullptr;
        left_max->parent = tgt_node->parent;
        left_max->right_node = tgt_node->right_node;
        tgt_node->right_node->parent = left_max;

        auto new_left_node = (left_max == tgt_node->left_node) ? tgt_node->left_node->left_node : tgt_node->left_node;
        left_max->left_node = new_left_node;
        if (new_left_node != nullptr)
            new_left_node->parent = left_max;
        tgt_slot = left_max;
    }
//    remove_fix(tgt_node);
    return true;
}

std::shared_ptr<TreeNode> RBTree::get_max(const std::shared_ptr<TreeNode> &node) {
    auto curr_node = (node != nullptr) ? node : root_node;
    if (curr_node->right_node == nullptr)
        return curr_node;
    return get_max(curr_node->right_node);
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
    shared_ptr<TreeNode> &parent_pos = get_ref(parent);

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
    shared_ptr<TreeNode> &parent_pos = get_ref(parent);

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
    auto parent = node->parent;
    // case1: insert node is root node
    if (!parent) {
        node->color = BLACK;
        return;
    }
    // case2: insert node has BLACK parent
    if (parent->color == BLACK)
        return;
    // case34: RED parent and BLACK uncle
    auto curr = node;
    auto grandparent = parent->parent;
    auto is_left_parent = parent == grandparent->left_node;
    auto uncle = (is_left_parent) ? grandparent->right_node : grandparent->left_node;
    if (uncle == nullptr || uncle->color == BLACK) {
        if (is_left_parent) {
            if (node == parent->right_node) {
                left_rotate(node);
                insert_fix(parent);
            } else {
                right_rotate(parent);
            }
        } else {
            if (node == parent->left_node) {
                right_rotate(node);
                insert_fix(parent);
            } else {
                parent->color = BLACK;
                grandparent->color = RED;
                left_rotate(parent);
            }
        }
        return;
    }
    // case5: RED parent and RED uncle
    if (uncle->color == RED) {
        parent->color = BLACK;
        uncle->color = BLACK;
        grandparent->color = RED;
        insert_fix(grandparent);
    }
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
    if (node_count==0)
        cout << endl;
}
