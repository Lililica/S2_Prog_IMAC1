#include <iostream>
#include "node.hpp"
#include <vector>

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}

int main(){
    std::cout << "Exercice 1 - Td6" << std::endl;
    std::cout << std::endl;

    std::vector<int> list {5, 7, 2, 4, 6, 8, 1, 9, 0};

    Node* myroot {new Node {3, nullptr, nullptr}};

    for(int value : list){
        // std::cout << value << std::endl;
        myroot->insert(value);
    }

    pretty_print_left_right(*myroot);

    std::cout << std::endl;
    std::cout << "Display Infixe : ";
    myroot->display_infixe();
    std::cout << std::endl;

    std::cout << "Display Prefixe : ";

    std::vector<Node const*> me = myroot->prefixe();
    std::cout << "[";
    for(Node const* nodes : me){
        std::cout << nodes->value << ",";
    }
    std::cout << "]" << std::endl;
    std::cout << std::endl;

    std::cout << "Remove 10 : " << remove(myroot, 10) << std::endl;
    std::cout << "Remove 5 : " << remove(myroot, 5) << std::endl;

    pretty_print_left_right(*myroot);

    std::cout << std::endl;
    std::cout << "Voici la valeur max : " << myroot->max() << " et la valeur min : " << myroot->min() << std::endl;
    std::cout << std::endl;

    std::cout << "Voici la somme des elements : ";
    int sum {0};
    for(Node const* node : myroot->prefixe()){
        sum =+ node->value;
    }
    std::cout << sum << std::endl;
    std::cout << std::endl;

    std::cout << "Voici sa hauteur : " << myroot->height() << std::endl;
    std::cout << std::endl;
}