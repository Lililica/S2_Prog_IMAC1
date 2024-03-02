#include <iostream>
#include <vector>
#include <algorithm>

bool is_sorted(std::vector<int> const& vec){ 
    return std::is_sorted(vec.begin(), vec.end()); 
}

void bubble_sort(std::vector<int> & vec);

void selection_sort(std::vector<int> & vec);

int main(){
    std::cout << "Exercice 1 - Td2" << std::endl;
    std::cout << std::endl;



}