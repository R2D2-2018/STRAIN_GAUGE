#include "wrap-hwlib.hpp"

#include "strain_gauge.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);

    auto input = hwlib::target::pin_adc(hwlib::target::ad_pins::a1);
    StrainGauge strainGauge(input);

    hwlib::cout << "R: " << (int)strainGauge.getResistance() << "\r" << hwlib::endl;
    hwlib::cout << "F: " << (int) strainGauge.getForce()     << "\r" << hwlib::endl;
    
    while (true) {
        hwlib::cout << (int)strainGauge.getResistance() << "\r\n";
        hwlib::wait_ms(500);
    }

    return 0;
}
