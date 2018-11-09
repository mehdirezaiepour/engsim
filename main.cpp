//
// Created by mehdi on 11/9/18.
//
#include "ButterflyValve.h"
int main()
{
    std::vector<double> cvs {0, 20 ,50 ,80 ,100};
    std::vector<double> cv_percentages {0,  4, 44, 135, 159};
    ButterflyValve bv(cv_percentages, cvs);


    return 0;
}