//
// Created by mehdi on 11/9/18.
//

#ifndef ENGINE_SIM_COMBUSTIONCHAMBER_H
#define ENGINE_SIM_COMBUSTIONCHAMBER_H


#include <ostream>

class CombustionChamber
{
public:
    CombustionChamber(double volume, double stroke, double connecting_rod_length)
        : charge_efficiency_(1.0),
          volume_(volume),
          stroke_(stroke),
          cur_height_(0.0),
          connecting_rod_length_(connecting_rod_length)
          {}
    double ideal_combs_force(){
        // TODO : Use a combustion model here
        charge_efficiency_ = 1.0;
        const double one_over_stroke = 1 / stroke_;
        const double charge_efficiency_mult_cur_height = charge_efficiency_ * cur_height_ ;
        return charge_efficiency_mult_cur_height * one_over_stroke;
    }
    //
    const double& charge_efficiency(){
        // TODO : Use a charge efficiency model here
        return charge_efficiency_;
    }
    //
    const double& cur_height() const { return cur_height_;}
    void cur_height(const double& cur_height) {
        cur_height_ = cur_height;
    }

    friend std::ostream &operator<<(std::ostream &os, const CombustionChamber &chamber) {
        os << "charge_efficiency_: " << chamber.charge_efficiency_ << " volume_: " << chamber.volume_ << " stroke_: "
           << chamber.stroke_ << " cur_height_: " << chamber.cur_height_ << " connecting_rod_length_: "
           << chamber.connecting_rod_length_;
        return os;
    }

    //
private:
    double charge_efficiency_;
    double volume_;
    double stroke_;
    double cur_height_;
    double connecting_rod_length_;

};


#endif //ENGINE_SIM_COMBUSTIONCHAMBER_H
