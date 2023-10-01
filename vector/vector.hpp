#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

namespace BAKATAN {

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
    for (auto &in : v) is >> in; 
    return is;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& v) {
    for (int i = 0; i < v.size(); i++) os << v[i] << (i + 1 == v.size() ? "" : " ");
    return os;
}
template <typename T>
inline void coutvec(const std::vector<T>& v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << (i == v.size() - 1 ? "" : "\n");
    }
    std::cout << endl;
    return;
}
template <typename T> 
inline T min(const std::vector<T>& v) {
    T res = v[0];
    for (int i = 1; i < v.size(); i++) res = std::min(res, v[i]);
    return res; 
}
template <typename T> 
inline T max(const std::vector<T>& v) {
    T res = v[0];
    for (int i = 1; i < v.size(); i++) res = std::max(res, v[i]);
    return res; 
}
template <typename T> 
inline T sum(const std::vector<T>& v) {
    T res = 0;
    for (int i = 0; i < v.size(); i++) res += v[i];
    return res; 
}

} //namespace BAKATAN