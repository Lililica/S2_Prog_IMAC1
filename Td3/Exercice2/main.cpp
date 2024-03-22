#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <cctype>
#include <queue>
#include <stack>

#define stringify( name ) #name



enum Operator { ADD = 0, SUB, MUL, DIV, POW, OPEN_PAREN, CLOSE_PAREN};
enum class TokenType { OPERATOR, OPERAND };
struct Token {
  TokenType type;
  float value;
  Operator op;
};

const char* convert_enum_to_string[] = {
    stringify(ADD),
    stringify(SUB),
    stringify(MUL),
    stringify(DIV),
    stringify(POW),
    stringify(OPEN_PAREN),
    stringify(CLOSE_PAREN)
};

std::vector<std::string> split_string(std::string const& s);
std::vector<Token> tokenize(std::vector<std::string> const& words);



size_t operator_precedence(Operator const op){
    if(op == Operator::ADD || op == Operator::SUB || op == Operator::POW){
        return 1;
    }
    else if(op == Operator::MUL || op == Operator::DIV){
        return 2;
    }
}

void displayVec(std::vector<Token> vec){
    for(Token token : vec){
        if(token.type == TokenType::OPERAND){
            std::cout << token.value << ' ';
        }
        else{
            std::cout << convert_enum_to_string[token.op] << ' ';
        }
    }
    std::cout << std::endl;
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
                while(stack.top().op != Operator::OPEN_PAREN){
                    result.push_back(stack.top());
                    stack.pop();
                }
                stack.pop();
            }
            else{
                if(stack.size() != 0){
                    if(operator_precedence(token.op) > operator_precedence(stack.top().op)){
                        result.push_back(stack.top());
                        stack.pop();
                    }
                    // else{
                    //     result.push_back(token);
                    // }
                }
                stack.push(token);
            }
        }
    }
    while(stack.size() != 0){
        result.push_back(stack.top());
        stack.pop();
    }
    return result;

}



std::vector<std::string> split_string(std::string const& s)
{
    std::istringstream in(s);
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

float npi_evaluate(std::vector<Token> const& tokens){
    std::stack<float> stack;

    if(tokens.size() == 0){
        return 0;
    }

    for(Token token : tokens){
        if(token.type == TokenType::OPERAND){
            stack.push(token.value);
        }
        else{
            float resultTemp = stack.top();
            stack.pop();
            if(stack.size() != 0){                
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
            stack.push(resultTemp);
        }

    }
    return stack.top();
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
            else if(token == std::string{"("}){        
                result.push_back(make_token(Operator::OPEN_PAREN));
            }
            else if(token == std::string{")"}){        
                result.push_back(make_token(Operator::CLOSE_PAREN));
            }
        }
    }
    return result;
}

int main(){
    std::cout << "Exercice 2 - Td3" << std::endl;
    std::cout << std::endl;

    std::string input {"3 + 4 ^ 2 / ( 1 - 5 ) ^ 6 "};

    // std::cout << "Veuiller rentrer un calcul sous format NPI : ";
    std::cout << "Veuiller rentrer un calcul sous format classic : ";
    // std::getline(std::cin, input);
    // std::cout << std::endl;

    // std::vector<Token> mySplitString {tokenize(split_string(input))};

    std::cout << std::endl;

    std::cout << "Format NPI : ";
    displayVec(infix_to_npi_tokens(input));
    std::cout << std::endl;

    std::cout << std::endl;

    std::cout << "Result : " << npi_evaluate(infix_to_npi_tokens(input)) << std::endl;
}