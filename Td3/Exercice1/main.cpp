#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <cctype>
#include <stack>

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

// enum operator_name {Addition, Soustraction, Multiplication, Division};

void make_the_calcul(std::stack<float> & stack, std::string const& token){
    float resultTemp = stack.top();
    stack.pop();
    int const nbrItemInstack = stack.size();
    
    if(token == std::string{"+"}){        
        resultTemp += stack.top();
        stack.pop();
    }
    if(token == std::string{"-"}){        
        resultTemp = stack.top() - resultTemp;
        stack.pop();
    }
    if(token == std::string{"*"}){        
        resultTemp *= stack.top();
        stack.pop();
    }
    if(token == std::string{"/"}){        
        resultTemp = stack.top() / resultTemp;
        stack.pop();
    }
    if(token == std::string{"^"}){        
        resultTemp = pow(resultTemp, stack.top());
        stack.pop();
    }

    stack.push(resultTemp);
}

float calcul(std::string const& input){
    std::stack<float> stack;
    std::vector<std::string> mySplitString {split_string(input)};

    if(mySplitString == std::vector<std::string>{}){
        return 0;
    }

    for(std::string token : mySplitString){
        if(is_floating(token)){
            stack.push(std::stof(token));
        }else{
            make_the_calcul(stack, token);
        }
    }

    return stack.top();
}

int main(){
    std::cout << "Exercice 1 - Td3" << std::endl;
    std::cout << std::endl;

    std::string input = "3 4 11 5 + / +";

    // std::cout << "Veuiller rentrer un calcul sous format NPI : ";
    // std::getline(std::cin, input);
    // std::cout << std::endl;

    std::vector<std::string> mySplitString {split_string(input)};

    for(std::string element : mySplitString){
        std::cout << is_floating(element);
    }
    std::cout << std::endl;

    std::cout << "Result : " << calcul(input) << std::endl;
    

    

}