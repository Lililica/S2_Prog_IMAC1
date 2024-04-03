#include <iostream>
#include <vector>
#include <string>

#include "hachage_kit.hpp"



int main(){
    std::cout << "Exercice 1 - Td5" << std::endl;
    std::cout << std::endl; 

    std::string userAnswer;

    std::cout << "Veuillez entrer une phrase : " << std::endl;
    std::getline(std::cin, userAnswer);

    std::cout << std::endl;
    std::cout << "Hachage classic : ";
    std::cout << folding_string_hash(userAnswer, 4096*8) << std::endl;
    

    std::cout << "Hachage par multiplication : ";
    std::cout << folding_string_ordered_hash(userAnswer, 4096*8) << std::endl;
  
    std::cout << "Hachage par polynomial : ";
    std::cout << polynomial_rolling_hash(userAnswer, 7, 4096*8) << std::endl;
    return 0;
}