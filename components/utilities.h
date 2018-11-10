//
// Created by mehdi on 11/9/18.
//

#ifndef ENGINE_SIM_UTILITIES_H
#define ENGINE_SIM_UTILITIES_H
//

//
#include <cmath>
#include <vector>
#include <array>
#include <iostream>
//
namespace util{
    // free functions:
    double regression_approx(double x, const std::vector<double>& xs,
                             const std::vector<double>& ys);
}

template <class T>
std::ostream& operator << (std::ostream& ost, const std::vector<T>& v);


template<class T1, std::size_t Num_Elements>
std::ostream &operator << (std::ostream &ost, const std::array<T1, Num_Elements>& v);

#endif //ENGINE_SIM_UTILITIES_H
