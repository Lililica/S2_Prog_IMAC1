#pragma once

#include <algorithm>
#include <numeric>
#include <iterator>
#include <iostream>
#include <vector>
#include <string>

size_t folding_string_hash(std::string const& s, size_t const& max);

size_t folding_string_ordered_hash(std::string const& s, size_t const& max);

size_t polynomial_rolling_hash(const std::string& s, size_t const& p, size_t const& m);