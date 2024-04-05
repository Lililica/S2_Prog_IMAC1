#pragma once
#include "robot_generator.hpp"

#include <unordered_map>
#include <iostream>
#include <string>
#include <numeric>

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(
    std::vector<std::pair<std::string, float>> const& robots_fixes
){
    
    std::unordered_map<std::string, std::vector<float>> myFinalMap;
    for(std::pair robot : robots_fixes){
        myFinalMap[robot.first].push_back(robot.second);
    }
    return myFinalMap;
}

float accumulate_float(std::vector<float> const& v){
    return std::accumulate(v.begin(), v.end(), 0.0);
}