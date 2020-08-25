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
    std::shared_ptr<TreeNode> parent;
    std::shared_ptr<TreeNode> left_node;
    std::shared_ptr<TreeNode> right_node;

    TreeNode() = delete;

    explicit TreeNode(int val, Color cl = RED, const std::shared_ptr<TreeNode> &p_node = nullptr) {
        value = val;
        color = cl;
        parent = p_node;
        left_node = nullptr;
        right_node = nullptr;
    }
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

    std::shared_ptr<TreeNode> get_root();

    void print(const std::shared_ptr<TreeNode> &node = nullptr, int node_count = 0);

protected:
    void left_rotate(std::shared_ptr<TreeNode> &node);

    void right_rotate(std::shared_ptr<TreeNode> &node);

    void insert_fix(std::shared_ptr<TreeNode>);

    void delete_fix(std::shared_ptr<TreeNode>);

private:
    std::shared_ptr<TreeNode> root_node = nullptr;
};

#endif //TINYSTL_RBTREE_HPP
