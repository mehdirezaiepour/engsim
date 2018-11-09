//
// Created by mehdi on 11/9/18.
//

#ifndef ENGINE_SIM_BUTTERFLYVALVE_H
#define ENGINE_SIM_BUTTERFLYVALVE_H
//
#include "utility.h"
//
#include <vector>
//
class ButterflyValve
{
public:
    ButterflyValve( std::vector<double> cv_percentages, std::vector<double> cvs)
          : cvs_(std::move(cvs)), cv_percentages_(std::move(cv_percentages)) {
        // TODO : ASSERT : opening percentages has to be ascending and starting from 0. and ending to 100.
    }
    //
    const double& open_percent() const { return open_percent_;}
    double& open_percent()  { return open_percent_;}
    //
    const double& inlet_p() const { return inlet_p_;}
    double& inlet_p() { return inlet_p_;}
    //
    const double& outlet_p() const { return outlet_p_;}
    double& outlet_p() { return outlet_p_;}
    //
    const double& delta_p() const { return delta_p_;}
    double& delta_p() { return delta_p_;}
    //
    double flow_qm_p_s() const {
        const double cv = regression_approx(open_percent_, cv_percentages_,  cv_percentages_);
        return cv * std::sqrt(delta_p_);
    }
    void flow_qm_p_s_vary_inlet_p(double flow_qm_p_s) {}
    void flow_qm_p_s_vary_outlet_p(double flow_qm_p_s) { }
    void flow_qm_p_s_vary_open_percent(double flow_qm_p_s) { }
    //

private:
    std::vector<double> cvs_;
    std::vector<double> cv_percentages_;
    double open_percent_ = 0;
    double inlet_p_ = 0;
    double outlet_p_ = 0;
    double delta_p_ = 0;
};

#endif //ENGINE_SIM_BUTTERFLYVALVE_H
