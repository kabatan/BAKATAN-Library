#pragma once

#include "atcoder/convolution.hpp"
#include "atcoder/math.hpp"

namespace BAKATAN {

template<unsigned int MOD = 1000000007, class T,
         std::enable_if_t<internal::is_integral<T>::value>* = nullptr>
std::vector<T> convolution_allmod(const std::vector<T>& A, const std::vector<T>& B) {

    static constexpr long long MOD1 = 167772161; //2^25*5+1
    static constexpr long long MOD2 = 469762049; //2^26*7+1
    static constexpr long long MOD3 = 1224736769; //2^24*73+1
    const std::vector<T> x = convolution<MOD1>(A, B);
    const std::vector<T> y = convolution<MOD2>(A, B);
    const std::vector<T> z = convolution<MOD3>(A, B);
    const T MOD1_inv_MOD2 = inv_mod(MOD1, MOD2);
    const T MOD12_inv_MOD3 = inv_mod(MOD1 * MOD2, MOD3);
    const T MOD12_MOD = MOD1 * MOD2 % MOD;

    std::vector<T> res(x.size());
    for (int i = 0; i < res.size(); i++) {
        T v1 = (y[i] - x[i]) * MOD1_inv_MOD2 % MOD2; 
        if (v1 < 0) v1 += MOD2; 
        T v2 = (z[i] - (x[i] + MOD1 * v1) % MOD3) * MOD12_inv_MOD3 % MOD3;
        if (v2 < 0) v2 += MOD3;
        res[i] = (x[i] + MOD1 * v1 + MOD12_MOD * v2) % MOD; 
        if (res[i] < 0) res[i] += MOD;
    }
    return res;
}

template <class mint, internal::is_static_modint_t<mint>* = nullptr>
std::vector<mint> convolution_allmod(const std::vector<mint>& A, const std::vector<mint>& B) {
    static constexpr long long MOD = mint::mod();
    std::vector<long long> A_(A.size()); 
    std::vector<long long> B_(B.size());
    for (int i = 0; i < A.size(); i++) A_[i] = A[i].val();
    for (int i = 0; i < B.size(); i++) B_[i] = B[i].val();
    std::vector<long long> C_ = convolution_allmod<MOD>(A_, B_); 
    std::vector<mint> C(C_.size()); 
    for (int i = 0; i < C.size(); i++) C[i] = C_[i]; 
    return C;
}

} //namespace