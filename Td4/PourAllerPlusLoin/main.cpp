#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iterator>

 
std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}


int sumQuad(std::vector<int> vec){
    std::transform(vec.cbegin(), vec.cend(), vec.begin(), [](int a){return a*a;});
    return std::accumulate(vec.begin(), vec.end(),0);
}


size_t sumPeer(std::vector<int> vec){
    std::transform(vec.cbegin(), vec.cend(), vec.begin(), [](int a){return (a%2==0 && a!=0) ? a : 1;});
    return std::accumulate(std::begin(vec), std::end(vec), 1.0, std::multiplies<int>());
}


int main(){
    std::cout << "Pour aller plus loin - Td4" << std::endl;
    std::cout << std::endl;

    std::vector<int> const vec {generate_random_vector(20)};

    std::cout << "La somme quadratique : " << sumQuad(vec) <<std::endl;
    std::cout << "La somme des paires : " << sumPeer(vec) <<std::endl;
    

}