#pragma once

#include <iostream>
#include <utility>
#include <vector>

namespace BAKATAN {

template<typename E>
struct graph_base : std::vector<std::vector<std::pair<int, E>>> {
    using std::vector<std::vector<std::pair<int, E>>>::std::vector;
    int n, m;
};

} //namespace BAKTAN