#include <unordered_map>
#include <iostream>
#include <string>
#include <numeric>

#include "robot_generator.hpp"
#include "robot_toolkit.hpp"

void display_vec(std::vector<float> const& v){
    std::cout << "[ ";
    for(std::vector<float>::const_iterator it{v.begin()}; it != v.end(); ++it){
        if(it != v.end() - 1){
            std::cout << *it << ", ";
        }
        else{
            std::cout << *it << " ]";
        }
    }
}

void display_map(std::unordered_map<std::string, std::vector<float>> const& map){
    for(std::unordered_map<std::string, std::vector<float>>::const_iterator it{map.begin()}; it != map.end(); ++it){
        std::cout << it->first << " : " << accumulate_float(it->second ) << std::endl;
    }
}

void display_map_init(std::unordered_map<std::string, std::vector<float>> const& map){
    for(std::unordered_map<std::string, std::vector<float>>::const_iterator it{map.begin()}; it != map.end(); ++it){
        std::cout << it->first << " : " ;
        display_vec(it->second);
        std::cout << std::endl;
    }
}

int main(){
    std::cout << "Exercice 2 - Td5" << std::endl;
    std::cout << std::endl; 

    std::vector<std::pair<std::string, float>> random_robot {get_robots_fix(100)};


    display_map_init(robots_fixes_map(random_robot));
    display_map(robots_fixes_map(random_robot));


    return 0;
}