#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>

bool checkPalindrome(std::string const& word){
    return std::equal(word.begin(), word.begin() + word.size() / 2, word.rbegin());
}
 


int main(){
    std::cout << "Exercice 3 - Td4" << std::endl;
    std::cout << std::endl; 


    std::string haha = "hahaaha";
    std::string non = "non";

    std::cout << checkPalindrome(haha) << " et : " << checkPalindrome(non) << std::endl;

}