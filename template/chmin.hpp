#pragma once

namespace BAKATAN {

template <typename T>
T chmin(T& A, const T& B) {return A = std::min(A, B);}
template <typename T>
T chmax(T& A, const T& B) {return A = std::max(A, B);}

} //namespace BAKATAN