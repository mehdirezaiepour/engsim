//
// Created by mehdi on 11/9/18.
//

#ifndef ENGINE_SIM_COMBUSTIONCHAMBER_H
#define ENGINE_SIM_COMBUSTIONCHAMBER_H

#include "GasMixture.h"
#include "Camshaft.h"
#include "Constants.h"
#include "utilities.h"
#include <ostream>

class CombustionChamber
{
public:
    CombustionChamber(double volume, double stroke, double connecting_rod_length, int id)
        : charge_efficiency_(1.0),
          volume_(volume),
          stroke_(stroke),
          cur_height_(0.0),
          cur_position_(0.0),
          cur_pressure_(0.0),
          connecting_rod_length_(connecting_rod_length),
          id_(id)
          {}
    double ideal_combs_force(){
        // TODO : Use a combustion model here
        charge_efficiency_ = 1.0;
        const double one_over_stroke = 1.0 / stroke_;
        const double charge_efficiency_mult_cur_height = charge_efficiency_ * cur_height_ ;
        return charge_efficiency_mult_cur_height * one_over_stroke;
    }
    //
    const double& charge_efficiency(){
        // TODO : Use a charge efficiency model here
        return charge_efficiency_;
    }
    //
    void do_material_balance(){
        Camshaft::lift_exhaust(cur_position_);
    }
    //
    const double& cur_height() const { return cur_height_;}
    void cur_height(const double& cur_height) {
        cur_height_ = cur_height;
    }
    //
    const double& cur_position() const { return cur_position_;}
    void cur_position(const double& cur_position) {
        cur_position_ = cur_position;
        calc_cur_height();
    }
    void calc_cur_height()
    {
        const double radius  = 0.5 * stroke_;
        const double r_cos_w = 0.5 * stroke_ * cos(cur_position_);
        const double sin_p   = sin(cur_position_);
        const double sqrt_l2_min_r2_mult_sin2_p =
                sqrt(
                        connecting_rod_length_
                        * connecting_rod_length_
                        - radius * radius * sin_p * sin_p
                );

        cur_height_ =
                connecting_rod_length_
                + radius
                - (r_cos_w + sqrt_l2_min_r2_mult_sin2_p) ;
    }
    inline const double& connecting_rod_length(){
        return connecting_rod_length_;
    }
    friend std::ostream &operator<<(std::ostream &os, const CombustionChamber &chamber) {
        os  << "\n     ID = "      << chamber.id_
            << "\n     charge_efficiency_: "     << chamber.charge_efficiency_
            << "\n     volume_: "                << chamber.volume_
            << "\n     stroke_: "                << chamber.stroke_
            << "\n     cur_height_: "            << chamber.cur_height_
            << "\n     cur_position_: "          << chamber.cur_position_
            << "\n     cur_pressure_: "          << chamber.cur_pressure_
            << "\n     connecting_rod_length_: " << chamber.connecting_rod_length_
            << "\n";
        return os;
    }

    //
private:
    double charge_efficiency_;
    double volume_;
    double stroke_;
    double cur_height_;
    double cur_position_;
    double cur_pressure_;
    double connecting_rod_length_;
    GasMixture<4>    gas_mixture_;
    int    id_;

};


#endif //ENGINE_SIM_COMBUSTIONCHAMBER_H
