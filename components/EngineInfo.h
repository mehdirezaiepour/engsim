//
// Created by mehdi on 11/9/18.
//

#ifndef ENGINE_SIM_ENGINEINFO_H
#define ENGINE_SIM_ENGINEINFO_H

#include "Constants.h"

#include <array>

template <std::size_t NumberOfCylinders>
struct EngineInfo
{
    std::array<double, NumberOfCylinders> crank_pins_rel_positions;
    std::array<double, NumberOfCylinders> camshaft_lob_rel_positions;
    double  cylinder_volume,
            stroke,
            connecting_rod_length,
            crankeshaft_weight,
            system_inertia = 1.0 * Constants::Kg
                                 * Constants::SquareMeter ;

};


#endif //ENGINE_SIM_ENGINEINFO_H
