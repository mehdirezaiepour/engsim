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
    CrankPin(double cylinder_volume, double stroke, double connecting_rod_length, int id)
            :  combs_chamber_(CombustionChamber(cylinder_volume, stroke, connecting_rod_length, id))
    { }
    CrankPin()
            :  combs_chamber_(CombustionChamber(0.0, 0.0, 0.0, 0))
    { }

    friend std::ostream &operator<<(std::ostream &os, const CrankPin &pin) {
        os  << "\n"
            << "combs_chamber_:\n"
            << "      " <<pin.combs_chamber_;
        return os;
    }

    CombustionChamber combs_chamber_;

};


#endif //ENGINE_SIM_CRANKPIN_H
