#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <cctype>
#include <queue>
#include <stack>

enum class Operator { ADD, SUB, MUL, DIV, POW, OPEN_PAREN, CLOSE_PAREN};
enum class TokenType { OPERATOR, OPERAND };
struct Token {
  TokenType type;
  float value;
  Operator op;
};

std::vector<std::string> split_string(std::string const& s);
std::vector<Token> tokenize(std::vector<std::string> const& words);



size_t operator_precedence(Operator const op){
    if(op == Operator::ADD || op == Operator::SUB){
        return 1;
    }
    else if(op == Operator::POW){ 
        return 1;
    }
    else if(op == Operator::MUL || op == Operator::DIV){
        return 3;
    }
    else if(op == Operator::OPEN_PAREN){
        return 4;
    }
    else if(op == Operator::CLOSE_PAREN){
        return 5;
    }
}

std::vector<Token> infix_to_npi_tokens(std::string const& expression){
    std::vector<Token> mySplitString {tokenize(split_string(expression))};
    std::vector<Token> result;
    std::stack<Token> stack;
    for(Token token : mySplitString){
        if(token.type == TokenType::OPERAND){
            result.push_back(token);
        }
        else{
            if(token.op == Operator::OPEN_PAREN){
                stack.push(token);
            }
            else if(token.op == Operator::CLOSE_PAREN){
                stack.pop();
                while(stack.top().op != Operator::OPEN_PAREN){
                    result.push_back(stack.top());
                    stack.pop();
                }
                stack.pop();
            }
            else{
                if(operator_precedence(token.op) > operator_precedence(stack.top().op)){
                    result.push_back(stack.top());
                    stack.pop();
                }else{
                    result.push_back(token);
                }
            }
        }
    }
    

}



std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s);
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

float npi_evaluate(std::vector<Token> const& tokens){
    std::stack<float> stack;

    if(tokens == std::vector<Token>{}){
        return 0;
    }

    for(Token token : tokens){
        if(token.type == TokenType::OPERAND){
            stack.push(token.value);
        }
        else{
            float resultTemp = stack.top();
            stack.pop();
            if(token.op == Operator::ADD){ 
                resultTemp += stack.top();
                stack.pop();
            }
            else if(token.op == Operator::SUB){        
                resultTemp = stack.top() - resultTemp;
                stack.pop();
            }
            else if(token.op == Operator::MUL){        
                resultTemp *= stack.top();
                stack.pop();
            }
            else if(token.op == Operator::DIV){        
                resultTemp = stack.top() / resultTemp;
                stack.pop();
            }
            else if(token.op == Operator::POW){        
                resultTemp = pow(stack.top(), resultTemp);
                stack.pop();
            }
        }
    }
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

Token make_token(float value){
    return Token{
        TokenType::OPERAND,
        value
    };
}

Token make_token(Operator op){
    return Token{
        TokenType::OPERATOR,
        float{INFINITY},
        op
    };
}

std::vector<Token> tokenize(std::vector<std::string> const& words){
    std::vector<Token> result;
    for(std::string token : words){
        if(is_floating(token)){
            result.push_back(make_token(std::stof(token)));
        }
        else{
            if(token == std::string{"+"}){        
                result.push_back(make_token(Operator::ADD));
            }
            else if(token == std::string{"-"}){        
                result.push_back(make_token(Operator::SUB));
            }
            else if(token == std::string{"*"}){        
                result.push_back(make_token(Operator::MUL));
            }
            else if(token == std::string{"/"}){        
                result.push_back(make_token(Operator::DIV));
            }
            else if(token == std::string{"^"}){        
                result.push_back(make_token(Operator::POW));
            }
        }
    }
    return result;
}

int main(){
    std::cout << "Exercice 2 - Td3" << std::endl;
    std::cout << std::endl;

    std::string input;

    std::cout << "Veuiller rentrer un calcul sous format NPI : ";
    std::getline(std::cin, input);
    std::cout << std::endl;

    std::vector<Token> mySplitString {tokenize(split_string(input))};

    std::cout << std::endl;

    std::cout << "Result : " << npi_evaluate(mySplitString) << std::endl;
}