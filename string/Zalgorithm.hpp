#pragma once

#include <string>
#include <vector>

namespace BAKATAN {

std::vector<long long> Zalgorithm(const std::string& S) {
    std::vector<long long> Z(S.size()); Z[0] = S.size();
    int i = 1, j = 0;
    while (i < S.size()) {
        while (i + j < S.size() && S[j] == S[i + j]) j++;
        Z[i] = j;
        if (j == 0) {i++; continue;}
        int k = 1;
        while (k < j && k + Z[k] < j) {Z[i + k] = Z[k]; k++;}
        i += k; j -= k;
    }
    return Z;
}

} //namespace BAKATAN