#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <cctype>

std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s);
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

bool is_floating(std::string const& s){
    
    int i{0};

    while(std::isdigit(s[i]) || s[i] == '.'){
        if(i == s.size() - 1){
            return true;
        }
        i++;
    }
    return false;
}

void display_vec(std::vector<std::string> vec){
    for(std::string element : vec){
        std::cout << element << std::endl;
    }
}

int main(){
    std::cout << "Exercice 1 - Td3" << std::endl;
    std::cout << std::endl;

    std::string input;

    std::cout << "Veuiller rentrer un calcul sous format NPI : ";
    std::getline(std::cin, input);
    std::cout << std::endl;

    std::vector<std::string> mySplitString {split_string(input)};

    for(std::string element : mySplitString){
        std::cout << is_floating(element);
    }
    std::cout << std::endl;

}