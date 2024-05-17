#include "node.hpp"
#include <iostream>

Node* create_node(int value){
    Node* root {new Node {value, nullptr, nullptr}};
    return root;
}

bool Node::is_leaf() const{
    return ((this->left == nullptr) && (this->right == nullptr));
}

void Node::insert(int value){
    if(this->is_leaf()){
        if(value < this->value){
            this->left = create_node(value);
        }
        else{
            this->right = create_node(value);
        }
    }else{
        if(value < this->value){
            if(this->left == nullptr){
                this->left = create_node(value);
            }else{
                this->left->insert(value);
            }
        }else{
            if(this->right == nullptr){
                this->right = create_node(value);
            }else{
                this->right->insert(value);
            }
        }
    }
}

int Node::height() const{
    if(this->is_leaf()){
        return 1;
    }
    if(this->right == nullptr){
        return this->left->height();
    }
    if(this->left == nullptr){
        return this->right->height();
    }
    return (right->height() > left->height()) ? right->height() + 1 : left->height() + 1;
}

void Node::delete_childs(){
    if(this->is_leaf()){
        delete this;
    }else{
        if(this->right != nullptr){
            this->right->delete_childs();
        }
        if(this->left != nullptr){
            this->left->delete_childs();
        }
    }
}

void Node::display_infixe_recur() const{
    if(this->is_leaf()){
        std::cout << value << ",";
    }else{
        if(this->left != nullptr){
            this->left->display_infixe_recur();
        }        
        std::cout << value << ",";
        if(this->right != nullptr){
            this->right->display_infixe_recur();
        }  
    }
    
}

void Node::display_infixe() const{
    std::cout << "[";
    display_infixe_recur();
    std::cout << "]" << std::endl;
}


std::vector<Node const*> Node::prefixe() const{
    std::vector<Node const*> me{this};
    if(this->is_leaf()){
        return me;
    }else{
        if(this->left != nullptr){
            auto left_nodes {left->prefixe()};
            me.insert(me.end(), left_nodes.begin(), left_nodes.end());
        }
        if(this->right != nullptr){
            auto right_nodes {right->prefixe()};
            me.insert(me.end(), right_nodes.begin(), right_nodes.end());
        }
    }
    return me;
}

Node*& most_left(Node*& node){
    if(node->left != nullptr){
        return most_left(node->left);
    }
    return node;
}

bool remove(Node*& node, int value){
    if(node->value == value){
        if(node->is_leaf()){
            delete node;
            node = nullptr;
            return true;
        }
        else if(node->left == nullptr || node->right == nullptr){
            Node*& leftAdressTemp {node->left};
            delete node;
            node = leftAdressTemp;
            return true;
        }else{
            Node*& newNodeWhichReplaceNode {most_left(node->right)};
            node->value = newNodeWhichReplaceNode->value;
            return remove(newNodeWhichReplaceNode, newNodeWhichReplaceNode->value);
        }
    }else{
        if(value < node->value){
            if(node->left != nullptr){
                return remove(node->left, value);
            }else{
                return false;
            }
        }else{
            if(node->right != nullptr){
                return remove(node->right, value);
            }else{
                return false;
            }
            
        }
    }
}



void delete_tree(Node* node){
    if(node->right != nullptr){
        delete_tree(node->right);
    }
    if(node->left != nullptr){
        delete_tree(node->left);
    }
    delete node;
}

int Node::min(){
    if(this->left == nullptr){
        return this->value;
    }
    return this->left->min();
}

int Node::max(){
    if(this->right == nullptr){
        return this->value;
    }
    return this->right->max();
}