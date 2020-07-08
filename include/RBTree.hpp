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
    std::shared_ptr <TreeNode> parent;
    std::shared_ptr <TreeNode> left_node;
    std::shared_ptr <TreeNode> right_node;
};

class RBTree {
public:
    RBTree() = default;

    explicit RBTree(std::vector<int> values);

    ~RBTree() = default;

    std::shared_ptr <TreeNode> find(int value);

    void insert(int value);

    void remove(int value);

private:
    std::shared_ptr <TreeNode> root_node;
};

#endif //TINYSTL_RBTREE_HPP