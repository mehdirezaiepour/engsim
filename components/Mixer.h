//
// Created by mehdi on 11/11/18.
//

#ifndef ENGINE_SIM_MIXER_H
#define ENGINE_SIM_MIXER_H

#include "Gas_Mixture_Flow.h"

#include <cstddef>
#include <array>

template <std::size_t Number_Of_Input_Streams, std::size_t Number_Of_Components>
class Mixer
{
public:
private:
    std::array<Gas_Mixture_Flow<Number_Of_Components>, Number_Of_Input_Streams> inputs_;
    Gas_Mixture_Flow<Number_Of_Components> output_;

};


#endif //ENGINE_SIM_MIXER_H
