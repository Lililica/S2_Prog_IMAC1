#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}


int main(){
    std::cout << "Exercice 1 - Td4" << std::endl;
    std::cout << std::endl;

    int const max = 100;

    std::vector<int> const array {generate_random_vector(100, max)};
    // std::vector<int> const array {1, 2, 3, 5, 6};

    std::vector<int>::const_iterator end_iterator { array.end() };

    std::cout << "[";
    for(std::vector<int>::const_iterator it { array.begin() }; it != end_iterator; ++it) {
        std::cout << *it << ", ";
    }
    std::cout << "]" << std::endl;

    std::cout << std::endl;

    int userAnswer;

    std::cout << "Veuillez entrer un nombre entre 0 et " << max << " :" << std::endl;
    std::cin >> userAnswer;

    auto it{std::find(array.begin(), array.end(), userAnswer)};

    if (it != array.end())
    {
        std::cout << "Element found" << std::endl;
    }
    else
    {
        std::cout << "Element not found" << std::endl;
    }

    auto numbIt {std::count(array.begin(), array.end(), userAnswer)};

    std::cout << "Cette valeur est repete " << numbIt << " fois dans le vecteur !" << std::endl;

    std::cout << std::endl;
    std::cout << "Voici le tableau trie : " << std::endl;

    std::vector<int> sortedArray{array};
    std::sort(sortedArray.begin(), sortedArray.end());

    std::cout << "[";
    for(std::vector<int>::iterator ite { sortedArray.begin() }; ite != sortedArray.end(); ++ite) {
        std::cout << *ite << ", ";
    }
    std::cout << "]" << std::endl;

    std::cout << std::endl;
    std::cout << "Voici le resultat de la somme de tous les elements : " << std::accumulate(array.begin(), array.end(), 0) << std::endl;

}