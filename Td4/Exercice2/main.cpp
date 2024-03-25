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

std::vector<std::string> split_string(std::string const& str){
    std::vector<std::string> result;
    auto it = str.begin();


    while(it != str.end()){
        std::string word;
        auto newIt = std::find(it, str.end(), char{' '});
        std::copy(it, newIt, std::back_inserter(word));
        result.push_back(word);
        if(newIt == str.end()){
            break;
        }
        it = newIt + 1;
        
    }
    
    return result;

}


int main(){
    std::cout << "Exercice 2 - Td4" << std::endl;
    std::cout << std::endl;

    std::string userAnswer;

    std::cout << "Veuillez entrer une phrase : " << std::endl;
    std::getline(std::cin, userAnswer);

    std::cout << std::endl;
    std::cout << numberLetterWord(userAnswer) << std::endl;
    
    std::cout << std::endl;
    std::vector<std::string> haha{split_string(userAnswer)};
    for(std::string word : haha){
        std::cout << word << std::endl;
    }
    std::cout << std::endl;

}