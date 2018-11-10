//
// Created by mehdi on 11/10/18.
//

#ifndef ENGINE_SIM_CONSTANTS_H
#define ENGINE_SIM_CONSTANTS_H

#include <cmath>

// NOTE : The basis of all calculations are metric.
//         [ m, m^2, m^3, Kg, second, degree of centigrade ]
//        Therefor, all other units hase to be converted to metric, before
//        being use.

class Constants
{
public:
    static constexpr double Pi_m_8          = (8.0 * M_1_PI);
    static constexpr double Pi_m_7          = (7.0 * M_1_PI);
    static constexpr double Pi_m_6          = (6.0 * M_1_PI);
    static constexpr double Pi_m_5          = (5.0 * M_1_PI);
    static constexpr double Pi_m_4          = (4.0 * M_1_PI);
    static constexpr double Pi_m_3          = (3.0 * M_1_PI);
    static constexpr double Pi_m_2          = (2.0 * M_1_PI);
    static constexpr double Pi_m_1          = (1.0 * M_1_PI);
    static constexpr double Pi_m_1_div_2    = (1.0/2.0 * M_1_PI);
    static constexpr double Pi_m_1_div_3    = (1.0/3.0 * M_1_PI);
    static constexpr double Pi_m_1_div_4    = (1.0/4.0 * M_1_PI);
    static constexpr double Pi_m_1_div_8    = (1.0/8.0 * M_1_PI);
    // TIME
    static constexpr double MicroSecond = 1.0e-6;
    static constexpr double MiliSecond  = 1.0e-3;
    static constexpr double Second      = 1.0;
    static constexpr double Minute      = 60.0;
    static constexpr double hour        = 3600.0;
    // WEIGHT
    static constexpr double gram = 0.001;
    static constexpr double Kg   = 1.0;
    // LENGTH
    static constexpr double Meter      = 1.0;
    static constexpr double CentiMeter = 0.01;
    static constexpr double MiliMeter  = 0.001;
    // AREA
    static constexpr double SquareMeter       = 1.0;
    static constexpr double SquareCentiMeter  = 1.0e-4;
    static constexpr double SquareMiliMeter  = 1.0e-6;
    // VOLUME
    static constexpr double CubicMeter       = 1.0;
    static constexpr double Liter            = 1.0e-3;
    static constexpr double Milliliter       = 1.0e-6;
    static constexpr double CubicCentiMeter  = 1.0e-6;
    static constexpr double CC               = 1.0e-6;
    static constexpr double CubicMiliMeter   = 1.0e-9;

};


#endif //ENGINE_SIM_CONSTANTS_H
