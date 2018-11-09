//
// Created by mehdi on 11/9/18.
//
#include "utility.h"
#include "tests.h"
#include <cmath>
void test_ButterflyValve(){
    std::vector<double> cv_percentages {0,  20 ,50 ,80 ,100};
    std::vector<double> cvs {0,  4, 44, 135, 159};
    components::ButterflyValve bv(cv_percentages, cvs);
    bv.inlet_p(9.);
    bv.outlet_p(0.);
    bv.open_percent(75.);

    std::cout << " Oppening = " << bv.open_percent()
              << " cv = " << bv.cv()
              << "\n____________________________________\n";
    std::cout << " flow = " << bv.flow_qm_p_s();

}


void test_Crankshaft(){
    EngineInfo<4> info;
    info.stroke = 1.0;
    info.connecting_rod_length = 0;
    info.cylinder_volume = 0;
    info.crank_pins_rel_positions = {};
    info.crankeshaft_weight = 1.0;
    Crankshaft<4> cs(INLINE_4_CYL);
    std::cout << cs;
}
