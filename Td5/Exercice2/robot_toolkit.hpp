
#include <unordered_map>
#include <iostream>
#include <string>

// Question 1

std::unordered_map<std::string, std::vector<float>> robots_fixes_map(
                        std::vector<std::pair<std::string, float>> const& robots_fixes);
// Question 2

float accumulate_float(std::vector<float> const& v);