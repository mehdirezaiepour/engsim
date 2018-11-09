//
// Created by mehdi on 11/9/18.
//

#ifndef ENGINE_SIM_CRANKSHAFT_H
#define ENGINE_SIM_CRANKSHAFT_H

#include "utility.h"
#include "EngineInfo.h"
#include "CrankPin.h"
#include "SolverInfo.h"

#include <array>
#include <vector>
#include <cmath>
#include <ostream>

#define INLINE_4_CYL  {0.0, M_1_PI, M_1_PI, 0.0}



//
//template<typename T, size_t Num_Elements>
//std::ostream &operator << (std::ostream &ost, const std::array<T, Num_Elements>& v) {
//    ost << "[  ";
//    for(auto a : v)
//    {
//        ost << a << "  ";
//    }
//    ost << "]";
//}
//
//
//


template <std::size_t Num_Crank_Pins>
std::array<CrankPin, Num_Crank_Pins>
crank_pins_maker( std::array<double ,Num_Crank_Pins> crank_pins_rel_positions_,
                          double cylinder_volume,
                          double stroke,
                          double connecting_rod_length);

//
template <std::size_t Num_Crank_Pins>
class Crankshaft
{
public:
    //
    explicit Crankshaft(const EngineInfo<Num_Crank_Pins>& e_info)
            :   crank_pins_rel_positions_(e_info.crank_pins_rel_positions),
                crank_pins_cur_positions_(e_info.crank_pins_rel_positions),
                crank_cur_position_(0.0),
                crank_rotation_rps_(0.0),
                sum_torques_     (0.0),
                sum_torques_old_ (0.0),
                diameter_(stroke_ / 2.0),
                stroke_(e_info.stroke),
                weight_(e_info.crankeshaft_weight),
                friction_torque_        (0.0),
                static_friction_torque_ (0.0),
                time_step_   (SolverInfo::time_step),
                crank_pins_( crank_pins_maker( e_info.crank_pins_rel_positions,
                                               e_info.cylinder_volume,
                                               e_info.stroke,
                                               e_info.connecting_rod_length ) )

    { }
    //
    void update_all(){
        calc_torques();
        crank_cur_position_ += crank_rotation_rps_ * time_step_;
    }

    void calc_torques(){
        sum_torques_old_ = sum_torques_;
        sum_torques_ = 0.0;
        for(int i = 0; i < Num_Crank_Pins; ++i)
        {
            sum_torques_ += crank_pins_[i].combs_chamber_.ideal_combs_force()
                    * diameter_* sin(crank_pins_cur_positions_[i]);
        }

    }
    template <std::size_t Number_Of_Crank_Pins>
    friend std::ostream &operator<<(std::ostream &os,
            const Crankshaft<Number_Of_Crank_Pins> &crankshaft);

private:
    std::array<double, Num_Crank_Pins> crank_pins_rel_positions_;
    std::array<double, Num_Crank_Pins> crank_pins_cur_positions_;
    double crank_cur_position_;
    double crank_rotation_rps_;
    double sum_torques_;
    double sum_torques_old_;
    double diameter_;
    double stroke_;
    double weight_;
    double friction_torque_;
    double static_friction_torque_;
    double time_step_;
    std::array<CrankPin, Num_Crank_Pins> crank_pins_;





};
//
template <std::size_t Num_Crank_Pins>
std::array<CrankPin, Num_Crank_Pins>
crank_pins_maker( std::array<double , Num_Crank_Pins> crank_pins_rel_positions_,
                  double cylinder_volume,
                  double stroke,
                  double connecting_rod_length){
    std::array<CrankPin,  Num_Crank_Pins> c_pins;
    for(CrankPin cp : c_pins){
        cp = CrankPin( cylinder_volume,  stroke,  connecting_rod_length);
        cp.combs_chamber_.cur_height(0.0);

    }
    return c_pins;
}

//
template <std::size_t Number_Of_Crank_Pins>
std::ostream &operator<<(std::ostream &os,
        const Crankshaft<Number_Of_Crank_Pins> &crankshaft) {
    // os  << "crank_pins_rel_positions_: " << crankshaft.crank_pins_rel_positions_
       // << " crank_pins_cur_positions_: " << crankshaft.crank_pins_cur_positions_
            ;std::cout<< " crank_cur_position_: " << crankshaft.crank_cur_position_
            ;std::cout<< " crank_rotation_rps_: " << crankshaft.crank_rotation_rps_
            ;std::cout<< " sum_torques_: " << crankshaft.sum_torques_
            ;std::cout<< " sum_torques_old_: " << crankshaft.sum_torques_old_
            ;std::cout<< " diameter_: " << crankshaft.diameter_
            ;std::cout<< " stroke_: " << crankshaft.stroke_
            ;std::cout<< " weight_: " << crankshaft.weight_
            ;std::cout<< " friction_torque_: " << crankshaft.friction_torque_
            ;std::cout<< " static_friction_torque_: " << crankshaft.static_friction_torque_
            ;std::cout<< " time_step_: " << crankshaft.time_step_
            ;//std::cout<< " crank_pins_: " << crankshaft.crank_pins_;
    return os;
}

#endif //ENGINE_SIM_CRANKSHAFT_H

