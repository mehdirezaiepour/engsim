//
// Created by mehdi on 11/9/18.
//
#include "utilities.h"

namespace util {
// free functions:

//=============================================================================
// #define PRINT_DEBUG_regression_approx
    double regression_approx(double x, const std::vector<double> &xs,
                             const std::vector<double> &ys) {
#ifdef PRINT_DEBUG_regression_approx
        std::cout << std::endl;
        std::cout << " xs = " << xs << std::endl;
        std::cout << " ys = " << ys << std::endl;
#endif
        const std::size_t sz = xs.size();
        std::size_t indx_high = 0;
        // TODO: use a better alg. like bi-section search
        for (; indx_high + 1 < sz && x > xs[indx_high]; ++indx_high) {
        }
        //
#ifdef PRINT_DEBUG_regression_approx
        std::cout << std::endl;
        std::cout << "  x = " << x;
        std::cout << "  indx_high = " << indx_high;
#endif
        //
        const double &x_high = xs[indx_high];
        const double &x_low = xs[indx_high - 1];
#ifdef PRINT_DEBUG_regression_approx
        std::cout << ", x_high = " << x_high;
        std::cout << ", x_low = " << x_low;
#endif
        //
        const double &y_high = ys[indx_high];
        const double &y_low = ys[indx_high - 1];
#ifdef PRINT_DEBUG_regression_approx
        std::cout << ", y_high = " << y_high;
        std::cout << ", y_low = " << y_low;
        std::cout << std::endl;
        std::cout << std::endl;
#endif
        //
        const double y = (y_high - y_low) * (x - x_low) / (x_high - x_low) + y_low;
        //
        return y;
    }

} // namespace util

template <class T>
std::ostream& operator << (std::ostream& ost, const std::vector<T>& v){
    ost << "[  ";
    for(auto a : v)
    {
        ost << a << "  ";
    }
    ost << "]";
    return ost;
}

template<class T1, std::size_t Num_Elements>
std::ostream &operator << (std::ostream &ost, const std::array<T1, Num_Elements>& v) {
    ost << "[  ";
    for(auto a : v)
    {
        ost << a << "  ";
    }
    ost << "]";
    return ost;
}

