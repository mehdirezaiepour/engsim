//
// Created by mehdi on 11/9/18.
//
#include "Constants.h"
#include "utilities.h"
#include "tests.h"
//
#include <cmath>
//
void test_ButterflyValve(){
    std::vector<double> cv_percentages {0,  20 ,50 ,80 ,100};
    std::vector<double> cvs {0,  4, 44, 135, 159};
    components::Valve bv(cv_percentages, cvs);
    bv.inlet_p(9.);
    bv.outlet_p(0.);
    bv.open_percent(75.);

    std::cout << " Oppening = " << bv.open_percent()
              << " cv = " << bv.cv()
              << "\n____________________________________\n";
    std::cout << " flow = " << bv.flow_qm_p_s();

}


void test_Crankshaft(){
    // NISSAN Z24/Z24i
    EngineInfo<4> info;
    info.stroke =                  96.012  * Constants::MiliMeter;
    info.connecting_rod_length =   165.0   * Constants::MiliMeter;
    info.cylinder_volume =  0.25 * 2389.0  * Constants::CC;
    info.system_inertia =  18.75           * Constants::Kg
                                           * Constants::SquareMeter ;
    info.crank_pins_rel_positions = INLINE_4_CYL;
    std::cout << "\nINLINE_4_CYL  = " << std::array<double, 4>( INLINE_4_CYL);
    info.crankeshaft_weight = 1.0;
    Crankshaft<4> cs(info);
    cs.set_rotation_rate_rps(1000 * Constants::Angle_Turn * Constants::PerMinute);
    std::cout << cs;
    for(std::size_t i = 0; i < 10; ++i)
    {
        std::cout << "_________________________________________________________"
                  << std::endl;
        cs.update_all();
        cs.report_print();
    }

}
