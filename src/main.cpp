#include "wrap-hwlib.hpp"

#include "strain_gauge.hpp"

int main() {
    WDT->WDT_MR = WDT_MR_WDDIS;

    hwlib::wait_ms(1000);

    auto input = hwlib::target::pin_adc(hwlib::target::ad_pins::a1);
    StrainGauge::StrainGauge strainGauge(input);

    while (true) {
        // hwlib::cout << "V: " << strainGauge.readSensor() << "\r" << hwlib::endl;
        hwlib::cout << "R: " << strainGauge.getResistance() << "\r" << hwlib::endl;
        hwlib::cout << "F: " << strainGauge.getForce() << "\r" << hwlib::endl;
        hwlib::wait_ms(500);
    }

    return 0;
}
