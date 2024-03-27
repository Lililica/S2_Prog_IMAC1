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

auto isPeer = [](int a){ return a%2 == 0;};

int sumPeer(std::vector<int> const& vec){
    std::vector<int> peerElement;
    for(int number : vec){
        if(isPeer(number) && (number != 0)){
            peerElement.push_back(number);
        }
    }
    return std::accumulate(peerElement.begin(), peerElement.end(), 0);
}


int main(){
    std::cout << "Pour aller plus loin - Td4" << std::endl;
    std::cout << std::endl;

    std::vector<int> const vec {generate_random_vector(10000)};

    std::cout << "La somme quadratique : " << sumQuad(vec) <<std::endl;
    std::cout << "La somme des paires : " << sumPeer(vec) <<std::endl;
    

}