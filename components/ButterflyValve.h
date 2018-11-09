//
// Created by mehdi on 11/9/18.
// simple Butterfly valve : Flow = Cv * sqrt(Delta_P)
// NOTE: Constructor needs Cv vs. %Opening as two std::vectors with at
//       least 3 members.
// Example:
//              std::vector<double>   cv_percentages {0,  20 ,50 ,80 ,100};
//              std::vector<double>   cvs            {0,  4, 44, 135, 159};
//              components::ButterflyValve   bv(cv_percentages, cvs);
// NOTE: Values of 0% and 100% MUST be in the vectors.

#ifndef ENGINE_SIM_BUTTERFLYVALVE_H
#define ENGINE_SIM_BUTTERFLYVALVE_H
//
#include "utility.h"
//
#include <vector>
#include <cassert>
//
namespace components{

#define  MIN_NUMBER_OF_CV_PERCENTAGE_PAIRS 3

    class ButterflyValve
    {
    public:
        ButterflyValve( std::vector<double> opening_percentages,
                        std::vector<double> cvs)
                : cvs_(std::move(cvs)),
                  opening_percentages_(std::move(opening_percentages)) {
            assert(cvs_.size() == opening_percentages_.size()
                   && "Size of 'opening_percentages' and 'cvs' has to be the same");
            assert(cvs_.size() >= MIN_NUMBER_OF_CV_PERCENTAGE_PAIRS
                   && "Minimum acceptable number of 'opening_percentages' and "
                   && "'cvs' pairs is 3.");
            assert(opening_percentages_[0] == 0.
                   && opening_percentages_[opening_percentages_.size()-1] == 100.
                   && "opening_percentages_ has to starts from 0. and ends at 100.");

        }
        //
        const double& open_percent() const { return open_percent_;}
        void open_percent(const double value)  { open_percent_ = value;}
        //
        const double& inlet_p() const { return inlet_p_;}
        void inlet_p(const double value) {
            inlet_p_ = value;
        }
        //
        const double& outlet_p() const { return outlet_p_;}
        void outlet_p(const double value) {
            outlet_p_ = value;
        }
        //
        const double delta_p() const { return inlet_p_ - outlet_p_;}
        //
        double flow_qm_p_s() const {
            const double cv = util::regression_approx(open_percent_,
                                                      opening_percentages_,
                                                      cvs_);
            return cv * std::sqrt(inlet_p_ - outlet_p_);
        }
        void flow_qm_p_s_vary_inlet_p(double flow_qm_p_s) {}
        void flow_qm_p_s_vary_outlet_p(double flow_qm_p_s) { }
        void flow_qm_p_s_vary_open_percent(double flow_qm_p_s) { }
        //
        const double cv() const {
            return util::regression_approx(open_percent_,
                                           opening_percentages_,
                                           cvs_);
        }
        //

    private:
        std::vector<double> cvs_;
        std::vector<double> opening_percentages_;
        double open_percent_ = 0;
        double inlet_p_ = 0;
        double outlet_p_ = 0;
    };


}




#endif //ENGINE_SIM_BUTTERFLYVALVE_H
