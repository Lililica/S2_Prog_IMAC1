#include <iostream>
#include <vector>
#include <algorithm>
#include "the_sorted_kit.hpp"

bool is_sorted(std::vector<int> const& vec){ 
    return std::is_sorted(vec.begin(), vec.end()); 
}

bool is_sorted(std::vector<float> const& vec){ 
    return std::is_sorted(vec.begin(), vec.end()); 
}

void display_sorted(std::vector<int> array){
    if (is_sorted(array)) {
        std::cout << "Le tableau est trie" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trie" << std::endl;
    }
}

void display_sorted(std::vector<float> array){
    if (is_sorted(array)) {
        std::cout << "Le tableau est trie" << std::endl;
    } else {
        std::cout << "Le tableau n'est pas trie" << std::endl;
    }
}

int main(){
    std::cout << "Exercice 1 - Td2" << std::endl;
    std::cout << std::endl;

    std::vector<int> array {24, 2, 3, 6, 8, 17, 16, 18, 26};

    display_sorted(array);
    std::cout << "Selection sort :" << std::endl;
    
    selection_sort(array);
    display_sorted(array);

    std::cout << std::endl;
    

    array = {24, 2, 3, 6, 8, 17, 16, 18, 26};
    display_sorted(array);
    
    std::cout << "Selection bubble :" << std::endl;
    bubble_sort(array);
    display_sorted(array);

    std::vector<float> vecFloat = {24.5, 2, 3, 17, 8.1, 16.8, 6, 18, 1};
    display_sorted(vecFloat);

    std::cout << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "Tri fusion :" << std::endl;
    merge_sort(vecFloat, 0, vecFloat.size() - 1);
    display_sorted(vecFloat);
}