//
// Created by mehdi on 11/9/18.
//

#ifndef ENGINE_SIM_CRANKPIN_H
#define ENGINE_SIM_CRANKPIN_H

#include <utility>
#include <ostream>
#include "CombustionChamber.h"


class CrankPin
{
public:
    CrankPin(double cylender_volume, double stroke, double connecting_rod_length)
            :  combs_chamber_(CombustionChamber(cylender_volume, stroke, connecting_rod_length))
    { }
    CrankPin()
            :  combs_chamber_(CombustionChamber(0.0, 0.0, 0.0))
    { }

    friend std::ostream &operator<<(std::ostream &os, const CrankPin &pin) {
        os << "combs_chamber_: " << pin.combs_chamber_;
        return os;
    }

    CombustionChamber combs_chamber_;

};


#endif //ENGINE_SIM_CRANKPIN_H
