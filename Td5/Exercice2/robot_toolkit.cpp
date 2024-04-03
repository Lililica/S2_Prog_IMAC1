#pragma once

#include <unordered_map>
#include <iostream>
#include <string>

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(
    std::vector<std::pair<std::string, float>> const& robots_fixes
);