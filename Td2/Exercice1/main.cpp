#include <iostream>
#include <vector>
#include <algorithm>
#include "the_sorted_kit.hpp"
#include "ScopedTimer.hpp"

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

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

    std::vector<int> const array {generate_random_vector(1000)};

    std::vector<int> arrayCopy = array;
    display_sorted(arrayCopy);
    
    std::cout << "Selection sort :" << std::endl;
    
    {    
        ScopedTimer timer("Chrono pour Tri par selection");
        selection_sort(arrayCopy);
    }
    display_sorted(arrayCopy);
    
    std::cout << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << std::endl;

    arrayCopy = array;
    display_sorted(arrayCopy);
    
    std::cout << "Selection bubble :" << std::endl;

    {    
        ScopedTimer timer("Chrono pour Tri a Bulle");
        bubble_sort(arrayCopy);
    }
    display_sorted(arrayCopy);



    std::cout << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << std::endl;

    // std::vector<float> vecFloat = {24.5, 2, 3, 17, 8.1, 16.8, 6, 18, 1};
    // display_sorted(vecFloat);
    arrayCopy = array;
    std::vector<float> arrayCopyFloat(arrayCopy.begin(), arrayCopy.end());
    display_sorted(arrayCopyFloat);

    std::cout << "Tri fusion :" << std::endl;
    {    
        ScopedTimer timer("Chrono pour Tri par Fusion");
        merge_sort(arrayCopyFloat, 0, arrayCopyFloat.size() - 1);
    }
    display_sorted(arrayCopyFloat);

    std::cout << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << std::endl;

    arrayCopy = array;
    display_sorted(arrayCopy);
    
    std::cout << "Selection by STD :" << std::endl;

    {    
        ScopedTimer timer("Chrono pour Tri par STD");
        std::sort(arrayCopy.begin(), arrayCopy.end());
    }
    display_sorted(arrayCopy);


    std::cout << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "Test pour la dichotomie : " << std::endl;

    std::vector<int> vecTest {1, 2, 2, 3, 4, 8, 12};
    std::cout << "Test 1 : " << search(vecTest, 8) << std::endl;

    vecTest = {1, 2, 3, 3, 6, 14, 12, 15};
    std::cout << "Test 2 : " << search(vecTest, 15) << std::endl;

    vecTest = {2, 2, 3, 4, 5, 8, 12, 15, 16};
    std::cout << "Test 3 : " << search(vecTest, 16) << std::endl;

    vecTest = {5, 6, 7, 8, 9, 10, 11, 12, 13};
    std::cout << "Test 4 : " << search(vecTest, 6) << std::endl;

    vecTest = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Test 5 : " << search(vecTest, 10) << std::endl;
}