//
// Created by mehdi on 11/11/18.
//

#ifndef ENGINE_SIM_GAS_H
#define ENGINE_SIM_GAS_H

struct Gas
{
    double mol_weight;
    double density;
    double Cp;
    double Cv;
    double enthalpy_of_formation;
    double enthalpy_of_vaporization;

};


#endif //ENGINE_SIM_GAS_H
