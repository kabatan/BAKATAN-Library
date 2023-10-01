#pragma once

#include <iostream>
#include <vector>
#include "atcoder/convolution.hpp"
#include "math/convolution_allmod.hpp"

namespace BAKATAN {

template<typename T>
struct sparse_fps {
    struct term {
        T ord, coe;
        term () : ord(0), coe(0) {}
        term (const T& ord_, const T& coe_) : ord(ord_), coe(coe_) {}
    };
    sparse_fps (const std::vector<T> &ords, const std::vector<T> &coes) {
        assert(ords.size() == coes.size());
        A.assign(ords.size());
        for (int i = 0; i < A.size(); i++) A[i] = term{ords[i], coes[i]};
    }
    inline const term &operator[](int k) const {return A[k];}
    inline term &operator[](int k) {return A[k];}
    sparse_fps &operator*(const T) const {
        
    }
    private:
    std::vector<term> A;
};

template<typename T>
struct fps : vector<T> {
    using vector<T>::vector;
    using vector<T>::operator=;
    fps operator-() const {for (auto &e : *this) e = -e; return *this;}
    fps &operator+=(const T& x) {
        if (this->empty()) this->resize(1);
        (*this)[0] += x; return *this;
    }
    fps &operator-=(const T& x) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= x; return *this;
    }
    fps &operator*=(const T& x) {for (auto &e : *this) e *= x; return *this;}
    fps &operator/=(const T& x) {for (auto &e : *this) e /= x; return *this;}
    fps &operator%=(const T& x) {for (auto &e : *this) e %= x; return *this;}
    fps &operator+=(const fps& f) {
        const int siz = min((*this).size(), f.size());
        for (int i = 0; i < siz; i++) (*this)[i] += f[i]; return *this;
    }
    fps &operator-=(const fps& f) {
        const int siz = min((*this).size(), f.size());
        for (int i = 0; i < siz; i++) (*this)[i] -= f[i]; return *this;
    }
    fps &operator*=(const fps& f) {
        const int siz = this->size();
        *this = convolution(*this, f); 
        this->resize(siz); return *this;
    }
    fps &operator<<=(const int& d) {
        const int siz = (*this).size();
        (*this).insert((*this).begin(), d, 0);
        (*this).resize(siz); return *this;
    }
    fps &operator>>=(const int& d) {
        const int siz = (*this).size();
        (*this).erase((*this).begin(), (*this).begin() + min(d, siz)); 
        (*this).resize(siz); return *this;
    }
    friend istream& operator>>(istream& is, fps& f) {
        for (auto &in : f) is >> in; return is;
    }
    friend ostream& operator<<(ostream& out, fps& f) {
        for (int i = 0; i < f.size(); i++) {
            out << f[i] << (i + 1 != f.size() ? " " : "");
        } return out;
    }
    fps operator+(const T& x) const {return fps(*this) += x;}
    fps operator-(const T& x) const {return fps(*this) -= x;}
    fps operator*(const T& x) const {return fps(*this) *= x;}
    fps operator/(const T& x) const {return fps(*this) /= x;}
    fps operator%(const T& x) const {return fps(*this) %= x;}
    fps operator+(const fps& f) const {
        fps res(*this); res.resize(max((*this).size(), f.size()));
        for (int i = 0; i < f.size(); i++) res[i] += f[i];
        return res;
    }
    fps operator-(const fps& f) const {
        fps res(*this); res.resize(max((*this).size(), f.size()));
        for (int i = 0; i < f.size(); i++) res[i] -= f[i];
        return res;
    }
    fps operator*(const fps& f) const {
        fps res = convolution(*this, f); return res;
    }
    fps operator<<(const int& d) const {
        fps res(*this); res.insert(res.begin(), d, 0);
        return res;
    }
    fps operator>>(const int& d) const {
        fps res(*this); res.erase(res.begin(), res.begin() + min(d, (int)res.size()));
        return res;
    }
    T eval(const T& a) const {
        T x = 1, res = 0;
        for (auto e : *this) {res += e * x; x *= a;}
        return res;
    }
    fps differential() const {
        fps res(*this); 
        for (int i = 1; i < res.size(); i++) res[i - 1] = res[i] * i;
        res.pop_back(); return res;
    }
    fps integral() const {
        fps res(*this); res.emplace_back(0);
        for (int i = res.size() - 1; i > 0; i--) res[i] = res[i - 1] / i;
        res[0] = 0; return res;
    }
};

} //namespace BAKATAN