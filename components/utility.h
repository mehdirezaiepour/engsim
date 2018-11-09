//
// Created by mehdi on 11/9/18.
//

#ifndef ENGINE_SIM_UTILITY_H
#define ENGINE_SIM_UTILITY_H
//

//
#include <cmath>
#include <vector>
//

// free functions:
double regression_approx(double x, const std::vector<double>& xs, const std::vector<double>& ys)
{
    const std::size_t sz = xs.size();
    std::size_t indx_high = 0;
    // TODO: use a better alg. like bi-section search
    for(; indx_high + 1 < sz && x < xs[indx_high]; ++indx_high){}
    //
    const double &  x_high= xs[indx_high];
    const double &  x_low = xs[indx_high - 1];
    //
    const double &  y_high= ys[indx_high];
    const double &  y_low = ys[indx_high - 1];
    //
    const double y = (y_high - y_low)*(x - x_low)/(x_high - x_low) + y_low;
    //
    return y;
}
#endif //ENGINE_SIM_UTILITY_H
