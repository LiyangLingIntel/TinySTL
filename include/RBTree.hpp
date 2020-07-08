//
// Created by liyangling on 7/8/20.
//

#ifndef TINYSTL_RBTREE_HPP
#define TINYSTL_RBTREE_HPP

#include <memory>
#include <vector>

enum Color {
    RED, BLACK
};

struct TreeNode {
    int value;
    Color color;
    std::shared_ptr<TreeNode> parent = nullptr;
    std::shared_ptr<TreeNode> left_child = nullptr;
    std::shared_ptr<TreeNode> right_child = nullptr;

    explicit TreeNode(int val, Color cl = BLACK)
            : value(val), color(cl) {};
};

/*
 * Currently assume that only different value will be took in
 * TODO: consider dealing with multiple same values
 */
class RBTree {
public:
    RBTree() = default;

    explicit RBTree(const std::vector<int> &values);

    ~RBTree() = default;

    std::shared_ptr<TreeNode> find(int value);

    bool insert(int value);

    bool remove(int value);

private:
    std::shared_ptr<TreeNode> root_node = nullptr;
};

#endif //TINYSTL_RBTREE_HPP
