#pragma once

#define _USE_MATH_DEFINES 
#include <cmath>

namespace BAKATAN {

template<typename T>
T deg_to_rad(const T& degree) {return T(degree * M_PI / 180.0);}
template<typename T> 
T rad_to_deg(const T& radian) {return T(radian * 180.0 / M_PI);}

} //namespace BAKATAN
