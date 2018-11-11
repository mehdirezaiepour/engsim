//
// Created by mehdi on 11/9/18.
//

#ifndef ENGINE_SIM_CRANKSHAFT_H
#define ENGINE_SIM_CRANKSHAFT_H

#include "utilities.h"
#include "EngineInfo.h"
#include "CrankPin.h"
#include "SolverInfo.h"
#include "Constants.h"

#include <array>
#include <vector>
#include <cmath>
#include <ostream>

#define INLINE_4_CYL  {0.0, M_PI, M_PI, 0.0}



// TODO : Why it does not work in the utilities.h ???!
template<class T1, std::size_t Num_Elements>
std::ostream &operator << (std::ostream &ost, const std::array<T1, Num_Elements>& v) {
    ost << "[  ";
    for(auto a : v)
    {
        ost << a << "  ";
    }
    ost << "]";
    return ost;
}


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
                crank_rotation_rad_per_s_(0.0),
                sum_torques_     (0.0),
                sum_torques_old_ (0.0),
                radius_(e_info.stroke / 2.0),
                stroke_(e_info.stroke),
                weight_(e_info.crankeshaft_weight),
                system_inertia_(e_info.system_inertia),
                friction_torque_        (0.0),
                static_friction_torque_ (0.0),
                time_step_ (SolverInfo::time_step),
                crank_pins_( crank_pins_maker( e_info.crank_pins_rel_positions,
                                               e_info.cylinder_volume,
                                               e_info.stroke,
                                               e_info.connecting_rod_length ) )

    { }
    //
    void update_all(){
        calc_torques();
        update_rotation_rad_p_s();
        update_positions();
    }
    //
    void update_rotation_rad_p_s(){
        // TODO : Write a better model for it!
        crank_rotation_rad_per_s_ += (sum_torques_ + sum_torques_old_)/ (2.0 * system_inertia_);
    }
    //
    void update_positions(){
        crank_cur_position_ += crank_rotation_rad_per_s_ * time_step_;
        crank_cur_position_ = fmod(crank_cur_position_, 2.0 * Constants::Angle_Turn);

        for(std::size_t i = 0; i < Num_Crank_Pins; ++i){
            crank_pins_cur_positions_[i] =
                    crank_cur_position_ + crank_pins_rel_positions_[i];

            crank_pins_[i].combs_chamber_
                          .cur_position(crank_pins_cur_positions_[i]);

        }
    }
    //
    void calc_torques(){
        sum_torques_old_ = sum_torques_;
        sum_torques_ = 0.0;
        for(std::size_t i = 0; i < Num_Crank_Pins; ++i)
        {
            sum_torques_ += crank_pins_[i].combs_chamber_.ideal_combs_force()
                    * radius_* sin(crank_pins_cur_positions_[i]);
        }

    }
    //
    void set_rotation_rate_rps(double rot_r)
    {
        crank_rotation_rad_per_s_ = rot_r;
    }
    //
    void report_print(){
        std::array<double, Num_Crank_Pins> comb_chamb_heights;
        for(std::size_t i = 0; i < Num_Crank_Pins; ++i) {
            comb_chamb_heights[i] = crank_pins_[i].combs_chamber_.cur_height();
        }
        std::cout
           << "\n"
           << "crank_rotation_rad_per_s_ = "
           << crank_rotation_rad_per_s_
           << "\n"
           << "crank_cur_position_ = "
           << crank_cur_position_
           << "\n"
           << "crank_pins_cur_positions_ = "
           << crank_pins_cur_positions_
           << "\n"
           << "comb_chamb_heights = "
           << comb_chamb_heights
           << "\n"
           << "sum_torques_ = "
           << sum_torques_
           << "\n"
           << "friction_torque_ = "
           << friction_torque_
           << std::endl;
    }
    //
    template <std::size_t Number_Of_Crank_Pins>
    friend std::ostream &operator<<(std::ostream &os,
            const Crankshaft<Number_Of_Crank_Pins> &crankshaft);

private:
    std::array<double, Num_Crank_Pins> crank_pins_rel_positions_;
    std::array<double, Num_Crank_Pins> crank_pins_cur_positions_;
    double crank_cur_position_;
    double crank_rotation_rad_per_s_;
    double sum_torques_;
    double sum_torques_old_;
    double radius_;
    double stroke_;
    double weight_;
    double system_inertia_;
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
    for(std::size_t id = 0; id < c_pins.size(); ++id){
        c_pins[id] = CrankPin( cylinder_volume,  stroke,  connecting_rod_length, id);
        c_pins[id].combs_chamber_.cur_height(0.0);
    }
    return c_pins;
}

//
template <std::size_t Number_Of_Crank_Pins>
std::ostream &operator<<(std::ostream &os,
                         const Crankshaft<Number_Of_Crank_Pins> &crankshaft) {
    os << "\nCrankshaft :"
       << "\n     crank_pins_rel_positions_: " << crankshaft.crank_pins_rel_positions_
       << "\n     crank_pins_cur_positions_: " << crankshaft.crank_pins_cur_positions_
       << "\n     crank_cur_position_: " << crankshaft.crank_cur_position_
       << "\n     crank_rotation_rad_per_s_: " << crankshaft.crank_rotation_rad_per_s_
       << "\n     sum_torques_: " << crankshaft.sum_torques_
       << "\n     sum_torques_old_: " << crankshaft.sum_torques_old_
       << "\n     radius_: " << crankshaft.radius_
       << "\n     stroke_: " << crankshaft.stroke_
       << "\n     weight_: " << crankshaft.weight_
       << "\n     system_inertia_: " << crankshaft.system_inertia_
       << "\n     friction_torque_: " << crankshaft.friction_torque_
       << "\n     static_friction_torque_: " << crankshaft.static_friction_torque_
       << "\n     time_step_: " << crankshaft.time_step_
       << "\n     crank_pins_: " << crankshaft.crank_pins_
       << "\n";
    return os;

}

#endif //ENGINE_SIM_CRANKSHAFT_H

