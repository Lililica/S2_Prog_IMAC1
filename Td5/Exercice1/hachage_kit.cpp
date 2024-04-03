#include "hachage_kit.hpp"

#include <algorithm>
#include <numeric>
#include <iterator>
#include <iostream>
#include <vector>
#include <string>

// Exercice 1

// Question 1

size_t folding_string_hash(std::string const& s, size_t const& max){
    return std::accumulate(s.begin(), s.end(),0)%max;
}



// Question 2

size_t folding_string_ordered_hash(std::string const& s, size_t const& max){
    size_t result {0};
    for(int i{0}; i < s.size(); i++){
        result += (i*(s[i]))%max;
    }
    return result; 
}


// Question 3


size_t polynomial_rolling_hash(const std::string& s, size_t const& p, size_t const& m){
    size_t result {0};
    size_t power {1};
    for(int i{0}; i < s.size(); i++){
        result += ((s[i]) * power)%m;
        power *= p;
    }
    return result; 
}

