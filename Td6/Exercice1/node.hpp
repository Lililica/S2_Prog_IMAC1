#pragma once
#include <vector>

struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    void insert(int value);
    bool is_leaf() const;
    int height() const;
    void delete_childs();
    void display_infixe() const;
    void display_infixe_recur() const;
    std::vector<Node const*> prefixe() const;
    int min();
    int max();
};


Node* create_node(int value);
Node*& most_left(Node*& node);
bool remove(Node*& node, int value);
bool remove_Fanny(Node*& node, int value);
void delete_tree(Node* node);



