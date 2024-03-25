#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

auto const is_space = [](char letter){ return letter == ' '; };

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

int numberLetterWord(std::string const& mySentence){
    auto it {std::find(mySentence.begin(), mySentence.end(), char{' '})};

    if (it != mySentence.end())
    {
        return std::distance(mySentence.begin(), it);
    }
    else
    {
        return -1;
    }
}


int main(){
    std::cout << "Exercice 2 - Td4" << std::endl;
    std::cout << std::endl;

    std::string userAnswer;

    std::cout << "Veuillez entrer une phrase : " << std::endl;
    std::getline(std::cin, userAnswer);

    std::cout << std::endl;
    std::cout << numberLetterWord(userAnswer) << std::endl;
}