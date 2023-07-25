#pragma once

#include <iostream>
#include <vector>

namespace BAKATAN {

template <typename T>
struct matrix {
    size_t h, w;
    matrix (const size_t& h_, const size_t& w_, const T& e = T()) : h(h_), w(w_){
        A.resize(h);
        for (int i = 0; i < h; i++) {
            A[i].resize(w);
            for (int j = 0; j < w; j++) A[i][j] = e;
        }
    }
    inline const std::vector<T> &operator[](int k) const {return A[k];}
    inline std::vector<T> &operator[](int k) {return A[k];}
    matrix operator-() const {
        for (std::vector<T>& x : A) {for (T& e : x) e = -e;} return A;
    }
    matrix &operator+=(const T& c) {
        for (std::vector<T>& x : A) {for (T& e : x) e += c;} return A;
    }
    matrix operator+(const T& c) const {return A += c;}
    matrix &operator-=(const T& c) {
        for (std::vector<T>& x : A) {for (T& e : x) e -= c;} return A;
    }
    matrix operator-(const T& c) const {return A -= c;}
    matrix &operator*=(const T& c) {
        for (std::vector<T>& x : A) {for (T& e : x) e *= c;} return A;
    }
    matrix operator*(const T& c) const {return A *= c;}
    matrix &operator/=(const T& c) {
        for (std::vector<T>& x : *this) {for (T& e : x) e /= c;} return A;
    }
    matrix operator/(const T& c) const {return A /= c;}
    matrix &operator%=(const T& c) {
        for (std::vector<T>& x : *this) {for (T& e : x) e %= c;} return A;
    }
    matrix operator%(const T& c) const {return A %= c;}
    matrix &operator+=(const matrix& B) {
        assert(h == B.h && w == B.w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) (*this)[i][j] += B[i][j];
        }
        return *this;
    }
    matrix operator+(const matrix& B) const {return *this += B;}
    matrix &operator-=(const matrix& B) {
        assert(h == B.h && w == B.w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) (*this)[i][j] -= B[i][j];
        }
        return *this;
    }
    matrix operator-(const matrix& B) const {return *this -= B;}
    matrix operator*(const matrix& B) const {
        assert(w == B.h);
        matrix res(h, B.w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                for (int k = 0; k < B.w; k++) {
                    res[i][k] += (*this)[i][j] * B[j][k];
                }
            }
        }
        return res;
    }
    matrix &operator*=(const matrix& B) {return *this = *this * B;}
    friend std::istream& operator>>(std::istream& is, matrix& B) {
        for (int i = 0; i < B.h; i++) {
            for (int j = 0; j < B.w; j++) is >> B[i][j];
        }
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, matrix& B) {
        for (int i = 0; i < B.h; i++) {
            for (int j = 0; j < B.w; j++) {
                os << B[i][j] << ((j + 1 != B.w) ? " " : (i + 1 != B.h) ? "\n" : "");
            }
        }
        return os;
    }

    private:
    std::vector<std::vector<T>> A;
};

} //namespace BAKATAN