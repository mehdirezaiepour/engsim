//
// Created by mehdi on 11/11/18.
//

#ifndef ENGINE_SIM_GASMIXTURE_H
#define ENGINE_SIM_GASMIXTURE_H

#include "Gas.h"

#include <array>

template <std::size_t Number_Of_Components>
class GasMixture
{
public:

private:
    std::array<Gas, Number_Of_Components>     components_;
    std::array<double , Number_Of_Components> mass_ratio_;
    std::array<double , Number_Of_Components> mol_ratio_;
    double temperature_;
    double pressure_;
};


#endif //ENGINE_SIM_GASMIXTURE_H
