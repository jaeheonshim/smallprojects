#ifndef UTIL_H
#define UTIL_H

template <typename T> inline T clamp(T val, T low, T high) {
    if(val < low) return low;
    if(val > high) return high;
    return val;
}

template <typename T> inline int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

#endif