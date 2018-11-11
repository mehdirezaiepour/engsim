//
// Created by mehdi on 11/11/18.
//

#ifndef ENGINE_SIM_GAS_MIXTURE_FLOW_H
#define ENGINE_SIM_GAS_MIXTURE_FLOW_H

#include "GasMixture.h"
template <std::size_t Number_Of_Components>
class Gas_Mixture_Flow : public GasMixture<Number_Of_Components>
{
public:
private:
    double mass_flow;
    double mol_flow;
};


#endif //ENGINE_SIM_GAS_MIXTURE_FLOW_H
