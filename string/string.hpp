#pragma once

#include <string>

namespace BAKATAN {

bool palindrome (const std::string& S) {
    for (int i = 0; i < S.size() / 2; i++) {
        if (S[i] != S[S.size() - i - 1]) return false;
    }
    return true;
}

} //namespace BAKATAN