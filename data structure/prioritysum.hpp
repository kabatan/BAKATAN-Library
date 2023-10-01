#pragma once 

#include <set>

namespace BAKATAN {

template <typename T>
class prioritysum {
    int k; T sum = 0;
    std::multiset<T> in,out;

    public:
    prioritysum (const int& k_) : k(k_) {}
    T query() const {return sum;}
};

} //namespace BAKATAN 