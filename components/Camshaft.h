//
// Created by mehdi on 11/10/18.
//
// NOTE :
//     In 0 degree of each cylinder:     intake is going to open,
//                                       &
//                                       exhaust has just closed.
//     &
//
//     Engines 0 degree position == Cylinder #1's 0 degree.
//

#ifndef ENGINE_SIM_CAMSHAFT_H
#define ENGINE_SIM_CAMSHAFT_H

#include <cmath>
#include "Constants.h"

class Camshaft
{
public:
    static double lift_intake(double position) {
        double lift = 0;
        const double pos = fmod(position, 2.0 * Constants::Angle_Turn);
        // TODO : Change it s.t get the lobe function and pos. as input of program.
        // TODO : Change the lift-function (it's a step function now)
        if(pos <= 0.5 * Constants::Angle_Turn) {
            lift = 100.0 * Constants::Percent;
        }
        else if(pos <= 1.0 * Constants::Angle_Turn) {
            lift = 0.0 * Constants::Percent;
        }
        else if(pos <= 1.5 * Constants::Angle_Turn) {
            lift = 0.0 * Constants::Percent;
        }
        else if(pos <= 2.0 * Constants::Angle_Turn) {
            lift = 0.0 * Constants::Percent;
        }
        return lift;
    }
    //
    static double lift_exhaust(double position_radian) {
        double lift = 0;
        const double pos = fmod(position_radian, 2.0 * Constants::Angle_Turn);
        // TODO : Change it s.t get the lobe function and pos. as input of program.
        // TODO : Change the lift-function (it's a step function now)
        if(pos <= 0.5 * Constants::Angle_Turn) {
            lift = 0.0 * Constants::Percent;
        }
        else if(pos <= 1.0 * Constants::Angle_Turn) {
            lift = 0.0 * Constants::Percent;
        }
        else if(pos <= 1.5 * Constants::Angle_Turn) {
            lift = 0.0 * Constants::Percent;
        }
        else if(pos <= 2.0 * Constants::Angle_Turn) {
            lift = 100.0 * Constants::Percent;
        }
        return lift;
    }

private:

};


#endif //ENGINE_SIM_CAMSHAFT_H
