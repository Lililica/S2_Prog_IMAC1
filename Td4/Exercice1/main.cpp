#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}


int main(){
    std::cout << "Exercice 1 - Td4" << std::endl;
    std::cout << std::endl;

    std::vector<int> const array {generate_random_vector(100)};

    std::vector<int>::const_iterator end_iterator { array.end() };

    for(std::vector<int>::const_iterator it { array.begin() }; it != end_iterator; ++it) {
        std::cout << array[*it] << " ";
    }
    std::cout << std::endl;
}