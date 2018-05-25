#include "wrap-hwlib.hpp"

#include "strain-gauge.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);

    auto input = hwlib::target::pin_in(hwlib::target::pins::a0);
    StrainGauge strainGauge = StrainGauge(input);
    hwlib::cout << "R: " << (int) strainGauge.getResistance() << "\r" << hwlib::endl;
    hwlib::cout << "F: " << (int) strainGauge.getNewton()     << "\r" << hwlib::endl;
    
    return 0;
}
