//
// Created by mehdi on 11/9/18.
//

#ifndef ENGINE_SIM_UTILITY_H
#define ENGINE_SIM_UTILITY_H
//

//
#include <cmath>
#include <vector>
#include <iostream>
//
namespace util{
    // free functions:
    double regression_approx(double x, const std::vector<double>& xs,
                             const std::vector<double>& ys);
    template <typename T>
    std::ostream& operator << (std::ostream& ost, const std::vector<T>& v);

}


#endif //ENGINE_SIM_UTILITY_H
