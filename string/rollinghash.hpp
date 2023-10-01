#pragma once

#include <string>
#include <vector>

namespace BAKATAN {

using ull = unsigned long long;

template <char c>
struct rollinghash {
    rollinghash (std::string S_) : S(S_), siz(S_.size()) {
        hash.resize(siz + 1); hash[0] = 0;
        power.resize(siz + 1); power[0] = 1;
        if (base < 100) base += 100;
        for (int i = 0; i < siz; i++) { 
            hash[i + 1] = Mod(Mul(base, hash[i]) + (S[i] - c) + 1);
        }
        for (int i = 0; i < siz; i++) {
            power[i + 1] = Mod(Mul(power[i], base));
        } 
    }
    long long query (const int& l, const int& r) const {
        return (long long)(Mod(hash[r] + 4 * mod - Mul(hash[l], power[r - l])));
    }
    private:
    static const ull mod = (1ll << 61) - 1, modsub = (1ll << 31) - 1;
    ull Mod (const ull& x) const { 
        ull res = (x >> 61) + (x & mod);
        if (res >= mod) res -= mod;
        return res;
    }
    ull Mul(const ull& a, const ull& b) const {
        const ull au = a >> 31;
        const ull ad = a & ((1ll << 31) - 1);
        const ull bu = b >> 31;
        const ull bd = b & ((1ll << 31) - 1);
        const ull mid = ad * bu + au * bd;
        const ull midu = mid >> 30;
        const ull midd = mid & ((1ll << 30) - 1);
        return au * bu * 2 + midu + (midd << 31) + ad * bd;
    }
    std::string S; 
    ull siz, base = Mod(rand());
    std::vector<ull> hash, power;
};

} //namespace BAKATAN